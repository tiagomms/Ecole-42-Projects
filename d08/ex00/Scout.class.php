<?php

include_once('Ship.class.php');
include_once ('FlankLaser.class.php');

class Scout extends Ship {

	use FlankLaser;

	# Teo: this has another thing called $name to specify between first and second. Maybe we should call this $team later?
	public function __construct($x, $y, $name) {
		parent::__construct( array ( 'name' => $name
									, 'x' => $x
									, 'y' => $y
									, 'width' => 1
									, 'height' => 1
									, 'max_health' => 10
									, 'shield' => 5
									, 'pp' => 5
									, 'speed' => 15
									, 'agility' => 4));
	}

	public function fight(array $kwargs) {
		$ship = $this->type($kwargs['dice_roll'], $kwargs['width'],
			$kwargs['position_x'], $kwargs['position_y'], $kwargs['arena'],
			$kwargs['direction']);
		if ($ship === NULL)
			error_log("ship that was shot was null (fight function, Scout.class.php)");
		else {
			$ship->shipIsShot($kwargs['arena']);
		}
	}
	
	public function __toString() {
		return "Scout" . parent::__toString();
	}
}

?>