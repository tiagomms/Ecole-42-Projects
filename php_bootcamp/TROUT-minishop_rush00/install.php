#!/usr/bin/php
<?php
include("php_assets/exit_to.php");
// Add private/passwd
if (!file_exists("private"))
	mkdir("private");
if (!file_exists("private/passwd"))
	file_put_contents("private/passwd", "");
// Add default users: {login=root, passwd=root, admin=true} & {login=foo, passwd=bar, admin=false}

$passwd_file = 'a:1:{s:4:"root";a:2:{s:6:"passwd";s:128:"06948d93cd1e0855ea37e75ad516a250d2d0772890b073808d831c438509190162c0d890b17001361820cffc30d50f010c387e9df943065aa8f4e92e63ff060c";s:5:"admin";b:1;}}';
file_put_contents("private/passwd", $passwd_file);
// Go to home
exit_to("/");
?>