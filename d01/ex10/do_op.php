#!/usr/bin/php
<?PHP

if ($argc != 4)
{
	echo "Incorrect Parameters\n";
	exit (1);
}
eval("echo \"$argv[1]\" $argv[2] \"$argv[3]\";");
echo "\n"; 
?>