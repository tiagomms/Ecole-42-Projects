<?php
include("../php_assets/return_to.php");
include("auth.php");
include("is_admin.php");
// Login for user
// If this is forced and failed when a user is logged in, they will be kicked
session_start();
if (auth($_POST['login'], $_POST['passwd'])) {
	$_SESSION['current_user'] = $_POST['login'];
	$_SESSION['admin'] = is_admin($_POST['login']);
	$_SESSION['return_to'] = "/";
	return_to("OK");
} else {
	$_SESSION['current_user'] = "";
	$_SESSION['return_to'] = "error_logging_in.html";
	error_log("error logging in");
	return_to("ERROR");
}
?>
