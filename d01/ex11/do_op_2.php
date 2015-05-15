#!/usr/bin/php
<?PHP

if ($argc != 2)
{
	echo "Incorrect Parameters\n";
	exit (1);
}
$plus_op = explode("+", $argv[1]);
$minus_op = explode("-", $argv[1]);
$mul_op = explode("*", $argv[1]);
$div_op = explode("/", $argv[1]);
$mod_op = explode("%", $argv[1]);


if (count($plus_op) == 2)
{
	$op = "+";
	$array = $plus_op;
}
else if (count($minus_op) == 2)
{
	$op = "-";
	$array = $minus_op;
}
else if (count($mul_op) == 2)
{
	$op = "*";
	$array = $mul_op;
}
else if (count($div_op) == 2)
{
	$op = "/";
	$array = $div_op;
}
else if (count($mod_op) == 2)
{
	$op = "%";
	$array = $mod_op;
}
else
{
	echo "Syntax Error\n";
	exit (1);
}
$implodi = implode(" ", $array);
$sploadi = explode(" ", $implodi);
$filter = array_filter($sploadi);
$numbers = array_slice($filter, 0);

if (count($numbers) == 2 && is_numeric($numbers[0]) && is_numeric($numbers[1]))
{
	eval("echo \"$numbers[0]\" $op \"$numbers[1]\";");
}
else
{
	echo "Syntax Error\n";
	exit (1);
}
echo "\n"; 
?>