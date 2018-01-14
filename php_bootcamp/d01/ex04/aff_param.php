#!/usr/bin/php
<?php

$args_array=$argv;
unset($args_array[0]);
$parameters= array_slice($args_array, 0);

foreach ($parameters as $elem){
	echo "$elem\n";
}
?>