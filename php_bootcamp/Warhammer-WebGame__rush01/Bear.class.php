<?php

include_once('Ship.class.php');
include_once ('Explosion.php');

class Bear extends Ship {

	use Explosion;

	public function __construct($x, $y, $name, $player) {
		parent::__construct( array ( 'name' => $name
									, 'x' => $x
									, 'y' => $y
									, 'width' => 4
									, 'height' => 3
									, 'max_health' => 10
									, 'shield' => 5
									, 'pp' => 10
									, 'speed' => 18
									, 'agility' => 3
									, 'player' => $player
									, 'movePP' => 0
									, 'shootPP' => 0));
	}

	public function fight(array $kwargs) {
		$this->type($kwargs['dice_roll'], $kwargs['width'], $kwargs['height'],
			$kwargs['position_x'], $kwargs['position_y'], $kwargs['arena']);
	}
	
	public function __toString() {
		return "Bear" . parent::__toString();
	}

public static function doc()
{
	return file_get_contents('./Bear.doc.txt') . PHP_EOL;
}

}

?>