<?php


include_once('Arena.class.php');
include_once('Ship.class.php');

trait Explosion {

#Order decides number of charges [i.e number of times the dice is rolled]
#diceRoll decides range

	private $_short = 2;
	private $_medium = 4;
	private $_long = 6;

	#General for all weapons
	private function _get_range($dice_roll) {
		if ($dice_roll === "short")
			return ($this->_short);
		else if ($dice_roll === "medium")
			return ($this->_medium);
		else
			return ($this->_long);
	}
	
	#Specific for this one
	public function type($dice_roll, $width, $height, $position_x, $position_y, $arena) {
		$range = $this->_get_range($dice_roll);
		$current_x = $position_x - $range;
		while ($current_x < $position_x + $range + $height) {
			$current_y = $position_y - $range;
			while ($current_y < $position_y + $range + $width) {
				$ship = $arena->getTileContents($current_x, $current_y, $this);
				if ($ship !== NULL)
					$ship->shipIsShot($arena);
				$current_y++;
			}
			$current_x++;
		}
	}
}

?>