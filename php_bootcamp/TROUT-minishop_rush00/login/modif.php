<?php
include("../php_assets/return_to.php");
// Modify login password
// Can only be done by actual user (not admin)
// Does not allow change of admin settings (see: admin_update)
if (isset($_POST['login'])   &&
	$_POST['login'] !== ""   &&
	isset($_POST['oldpw'])   &&
	$_POST['oldpw'] !== ""   &&
	isset($_POST['newpw'])   &&
	$_POST['newpw'] !== ""   &&
	$_POST['submit'] === "OK")
{
	if (!file_exists("../private/passwd")) {
		return_to("NO USERS");
	}
	$passwd_file = file_get_contents("../private/passwd");
	$passwd_database = unserialize($passwd_file);
	if (!isset($passwd_database[$_POST['login']])) {
		return_to("WRONG USERNAME");
	}
	if ($passwd_database[$_POST['login']]['passwd'] !== hash("whirlpool", $_POST['oldpw'])) {
		return_to("WRONG PASSWORD");
	}
	$passwd_database[$_POST['login']]['passwd'] = hash("whirlpool", $_POST['newpw']);
	$passwd_file = serialize($passwd_database);
	file_put_contents("../private/passwd", $passwd_file);
	return_to("OK");
}
else
	return_to("ERROR");
?>
