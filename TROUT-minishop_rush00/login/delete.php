<?php
include("../php_assets/return_to.php");
// Removes a login entirely
// Admin only
if (isset($_POST['login'])  &&
	$_POST['login'] !== ""  &&
	$_POST['submit'] === "Delete")
{
	if (!file_exists("../private/passwd")) {
		return_to("NO USERS");
	}
	$passwd_file = file_get_contents("../private/passwd");
	$passwd_database = unserialize($passwd_file);
	if (isset($_SESSION['current_user'])                              &&
		isset($passwd_database[$_SESSION['current_user']])            &&
		$passwd_database[$_SESSION['current_user']]['admin'] === true &&
		isset($passwd_database[$_POST['login']]))
	{
		unset($passwd_database[$_POST['login']]);
		$passwd_file = serialize($passwd_database);
		file_put_contents("../private/passwd", $passwd_file);
		return_to("OK");
	}
	return_to("NOT ADMIN OR USER DOES NOT EXIST");
}
else
	return_to("ERROR");
?>
