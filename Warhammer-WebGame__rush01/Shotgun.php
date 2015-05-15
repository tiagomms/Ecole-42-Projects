<?php


include_once('Arena.class.php');

trait Shotgun {

#Order decides number of charges [i.e number of times the dice is rolled]
#diceRoll decides range

	private $_short = 10;
	private $_medium = 20;
	private $_long = 30;

	#General for all weapons
	private function _get_range($dice_roll) {
		if ($dice_roll === "short")
			return ($this->_short);
		else if ($dice_roll === "medium")
			return ($this->_medium);
		else
			return ($this->_long);
	}
	
	private function _set_direction($direction)
	{
		if ($direction === "shoot_down")
		{
			return 1;
		}
		else
			return -1;
	}

	private function _set_shooting_start_position($direction, $height)
	{
		if ($direction === "shoot_down")
		{
			return $height - 1;
		}
		else
			return 0;
	}
	#Specific for this one
	public function type($dice_roll, $width, $height, $position_x, $position_y, $arena, $direction_string) {
		$range = $this->_get_range($dice_roll);
		$direction = $this->_set_direction($direction_string);
		$ypoint = $direction;
		$xpoint = 0;
		$shooting_y_pos = $position_y + $this->_set_direction($direction_string, $height) - 1;
		while (abs($ypoint) <= $range) 
		{
			$spray = $width + abs($ypoint) - 1;
			$xpoint = 0 - abs($ypoint) + 1;
			while ($xpoint < $spray)
			{
				if ($arena->getTileContents($position_x + $xpoint, $shooting_y_pos + $ypoint, $this) !== NULL)
					return ($arena->getTileContents($position_x + $xpoint, $shooting_y_pos + $ypoint, $this));
				$xpoint++;
			}
			$ypoint += $direction;
		}
		return NULL;
	}
}