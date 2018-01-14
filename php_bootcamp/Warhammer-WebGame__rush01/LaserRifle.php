<?php


include_once('Arena.class.php');

trait LaserRifle {

#Order decides number of charges [i.e number of times the dice is rolled]
#diceRoll decides range

	private $_short = 20;
	private $_medium = 40;
	private $_long = 60;
	
	#General for all weapons
	private function _get_range($dice_roll) {
		if ($dice_roll === "short")
			return ($this->_short);
		else if ($dice_roll === "medium")
			return ($this->_medium);
		else
			return ($this->_long);
	}
	
	private function _set_shooting_start_position($direction)
	{
		if ($direction === "shoot_down" || $direction === "shoot_right")
			return 1;
		else if ($direction === "shoot_up" || $direction === "shoot_left")
			return -1;
		else {
			error_log("SniperTrout Laser did not pick direction");
			exit(1);
		}
	}

	#Specific for this one
	public function type($dice_roll, $width, $height, $position_x, $position_y, $arena, $direction_string) {
		$range = $this->_get_range($dice_roll);
		$direction = $this->_set_shooting_start_position($direction_string);
		$counter = $direction;
		if ($direction_string === "shoot_down" || $direction_string === "shoot_up") {
			while (abs($counter) <= $range) {
				$current_coordinate = $position_x + $counter;
				$ship = $arena->getTileContents($current_coordinate, $position_y, $this);
				if ($ship !== NULL)
					$ship->shipIsShot($arena);
				$counter += $direction;
			}
		}
		else
		{
			while (abs($counter) <= $range) {
				$current_coordinate = $position_y + $counter;
				$ship = $arena->getTileContents($position_x, $current_coordinate, $this);
				if ($ship !== NULL)
					$ship->shipIsShot($arena);
				$counter += $direction;
			}
		}
	}
}