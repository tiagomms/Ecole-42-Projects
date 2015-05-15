#!/usr/bin/php
<?php

$split_str = explode(" ", $argv[1]);
$remove_null_strs= array_filter($split_str);
if (count($remove_null_strs) == 0)
	exit;
$offset= array_slice($remove_null_strs, 0);
$last=$offset[count($offset) - 1];
unset($offset[count($offset) - 1]);

foreach ($offset as $elem){
	echo "$elem ";
}
echo "$last\n";
?>