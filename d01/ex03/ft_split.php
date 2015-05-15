<?php

function ft_split($my_str)
{
	$split_str = explode(" ", $my_str);
	$remove_null_strs= array_filter($split_str);
	$offset= array_slice($remove_null_strs, 0);
	sort($offset);
	return $offset;
}
?>