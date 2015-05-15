<?php
include("../php_assets/return_to.php");
if ($_POST['submit'] === "Update" &&
	isset($_POST['login'])    &&
	$_POST['login']  !== "")
{
	if (!file_exists("../private/passwd")) {
		return_to("ERROR");
	}
	$passwd_file = file_get_contents("../private/passwd");
	$passwd_database = unserialize($passwd_file);
	if (isset($_POST['passwd']) && $_POST['passwd'] !== "") {
		$passwd_database[$_POST['login']]['passwd'] = hash("whirlpool", $_POST['passwd']);
	}
	if (isset($_POST['admin']) && $_POST['admin'] === "true") {
		$passwd_database[$_POST['login']]['admin'] = true;
	} else {
		$passwd_database[$_POST['login']]['admin'] = false;
	}
	$passwd_file = serialize($passwd_database);
	file_put_contents("../private/passwd", $passwd_file);
	return_to("OK");
}
else
	return_to("ERROR");
?>
