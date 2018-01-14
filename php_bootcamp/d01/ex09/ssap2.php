#!/usr/bin/php
<?PHP
unset($argv[0]);
$implode = implode(" ", $argv);
$explode = explode(" ", $implode);
$filter = array_filter($explode);

function get_ascii($char)
{
	$ascii = ord($char);
	if ($ascii == 0)
		return $ascii;
	if (($ascii < 48) || ($ascii >= 91 && $ascii <= 96) || ($ascii >= 123))
		$ascii += 1000;
	else if (is_numeric($char))
		$ascii += 100;
	else if (ctype_upper($char))
		$ascii += 32;
	return $ascii;
}

function ord_compare($string1, $string2)
{
	if ($string1 == $string2)
		return 0;
	$split_s1 = str_split($string1, 1);
	$split_s2 = str_split($string2, 1);
	$i = 0;
	while ($split_s1[$i])
	{
		$ascii_s1 = get_ascii($split_s1[$i]);
		$ascii_s2 = get_ascii($split_s2[$i]);
		if ($ascii_s1 != $ascii_s2)
			return ($ascii_s1 < $ascii_s2) ? -1 : 1;
		$i += 1;
	}
	return -1;
}

usort($filter, "ord_compare");
foreach ($filter as $key) {
	echo $key."\n";
}
?>