<?php

include_once('Ship.class.php');
include_once ('FlankLaser.class.php');

class Obstacle extends Ship {

	public function __construct($x, $y, $width, $height) {
		parent::__construct( array ( 'name' => 'obstacle'
									, 'x' => $x
									, 'y' => $y
									, 'width' => $width
									, 'height' => $height
									, 'max_health' => 1000000
									, 'shield' => 1000000000
									, 'pp' => 0
									, 'speed' => 0
									, 'agility' => 0));
	}

	public function fight(array $kwargs) {
		error_log("this shouldn't be able to fire... I'm an obstacle");
	}
	
	public function __toString() {
		return "Obstacle" . parent::__toString();
	}
}

?>