#!/usr/bin/php
<?PHP
if ($argc == 1)
	exit;
$explode = explode(" ", $argv[1]);
$filter = array_filter($explode);
$first = array_shift($filter);
foreach ($filter as $key) {
	echo $key." ";
}
echo $first."\n"
?>