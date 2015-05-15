#!/usr/bin/php
<?php

$arguments = $argv;
unset($arguments[0]);
if (count($arguments) == 0)
	exit;
$concatenate = implode(" ", $arguments);
$parameters = explode(" ", $concatenate);
$filtered = array_filter($parameters);
sort($filtered);
foreach ($filtered as $elem){
	echo "$elem\n";
}
?>