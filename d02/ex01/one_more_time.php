#!/usr/bin/php
<?PHP
if ($argc != 2)
	exit(1);

$argv[1] = trim($argv[1]);
$str_split = explode(" ", $argv[1]);

if (count($str_split) != 5)
{
	echo "Wrong Format\n";
	exit (1);
}

#days of the week
$day = $str_split[0];
$str_split[0]= preg_replace("/^[lL]undi/", "Monday", $str_split[0]);
$str_split[0]= preg_replace("/^[mM]ardi/", "Tuesday", $str_split[0]);
$str_split[0]= preg_replace("/^[mM]ercredi/", "Wednesday", $str_split[0]);
$str_split[0]= preg_replace("/^[jJ]eudi/", "Thursday", $str_split[0]);
$str_split[0]= preg_replace("/^[vV]endredi/", "Friday", $str_split[0]);
$str_split[0]= preg_replace("/^[sS]amedi/", "Saturday", $str_split[0]);
$str_split[0]= preg_replace("/^[dD]imanche/", "Sunday", $str_split[0]);

if ($day === $str_split[0])
{
	echo "Wrong Format\n";
	exit (1);
}
#day of the month
if (strlen($str_split[1]) != 1 && strlen($str_split[1]) != 2)
{
	echo "Wrong Format\n";
	exit (1);
}

#month
$month = $str_split[2];
$str_split[2]= preg_replace("/^[jJ]anvier/", "January", $str_split[2]);
$str_split[2]= preg_replace("/^[fF]evrier/", "February", $str_split[2]);
$str_split[2]= preg_replace("/^[mM]ars/", "March", $str_split[2]);
$str_split[2]= preg_replace("/^[aA]vril/", "April", $str_split[2]);
$str_split[2]= preg_replace("/^[mM]ai/", "May", $str_split[2]);
$str_split[2]= preg_replace("/^[jJ]uin/", "June", $str_split[2]);
$str_split[2]= preg_replace("/^[jJ]uillet/", "July", $str_split[2]);
$str_split[2]= preg_replace("/^[aA]out/", "August", $str_split[2]);
$str_split[2]= preg_replace("/^[sS]eptembre/", "September", $str_split[2]);
$str_split[2]= preg_replace("/^[oO]ctobre/", "October", $str_split[2]);
$str_split[2]= preg_replace("/^[nN]ovembre/", "November", $str_split[2]);
$str_split[2]= preg_replace("/^[dD]ecembre/", "December", $str_split[2]);
if ($month === $str_split[2])
{
	echo "Wrong Format\n";
	exit (1);
}
#year
if (strlen($str_split[3]) != 4)
{
	echo "Wrong Format\n";
	exit (1);
}
#hours
if (strlen($str_split[4]) != 8)
{
	echo "Wrong Format\n";
	exit (1);
}

#time in epoch
$english_day = $str_split[0]; #weekday in english written
unset($str_split[0]); 
$full_time = implode(" ", $str_split);
date_default_timezone_set('Europe/Paris'); #paris time zone
$time_in_secs = strtotime($full_time);
$weekday = strftime("%A", $time_in_secs); #actual weekday
if (is_numeric($time_in_secs) === FALSE || $weekday !== $english_day)
{
	echo "Wrong Format - not valid date / weekday\n";
	exit (1);
}
else
{
	echo "$time_in_secs\n";
}

?>