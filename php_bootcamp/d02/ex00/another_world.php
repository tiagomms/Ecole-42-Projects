#!/usr/bin/php
<?PHP
if ($argc < 2)
{
	exit(1);
}
$spaces_removed= preg_replace("/[ \t]+/", " ", $argv[1]);
$trimmed = trim($spaces_removed);
echo "$trimmed\n";
?>