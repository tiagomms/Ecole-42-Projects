#!/usr/bin/php
<?php
while (1)
{
	echo "Entrez un nombre: ";
	$handle = fopen("php://stdin","r");
	$number = fgets($handle);	
	if ($number == FALSE) //not number
	{
		echo "\n";
		break;
	}
	$number = trim($number);
	if (is_numeric($number))
	{
		if($number % 2 == 0) // pair
			echo "Le chiffre ".$number." est Pair";
		else
			echo "Le chiffre ".$number." est Impair";
	}
	else
		echo "'$number' n'est pas un chiffre";
	echo "\n";
}
?>