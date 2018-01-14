<?php

include_once('Ship.class.php');
include_once ('LaserRifle.php');

class KamikazeRock extends Ship {

	use LaserRifle;

	public function __construct($x, $y, $width, $height, $name, $player) {
		parent::__construct( array ( 'name' => $name
									, 'x' => $x
									, 'y' => $y
									, 'width' => $width
									, 'height' => $height
									, 'max_health' => 1000000000
									, 'shield' => 1000000000
									, 'pp' => 10
									, 'speed' => 2
									, 'agility' => 2
									, 'player' => $player
									, 'movePP' => 0));
	}
	
	public function fight(array $kwargs) {
	}
	
	public function __toString() {
		return "KamikazeRock" . parent::__toString();
	}

public static function doc()
{
	return file_get_contents('./KamikazeRock.doc.txt') . PHP_EOL;
}

}

?>