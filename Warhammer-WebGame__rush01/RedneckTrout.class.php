<?php

include_once('Ship.class.php');
include_once ('Shotgun.php');

class RedneckTrout extends Ship {

	use Shotgun;

	# Teo: this has another thing called $name to specify between first and second. Maybe we should call this $team later?
	public function __construct($x, $y, $name, $player) {
		parent::__construct( array ( 'name' => $name
									, 'x' => $x
									, 'y' => $y
									, 'width' => 4
									, 'height' => 1
									, 'max_health' => 5
									, 'shield' => 0
									, 'pp' => 10
									, 'speed' => 15
									, 'agility' => 4
									, 'player' => $player
									, 'movePP' => 0
									, 'shootPP' => 0));
	}

	public function fight(array $kwargs) {
		$ship = $this->type($kwargs['dice_roll'], $kwargs['width'], $kwargs['height'],
			$kwargs['position_x'], $kwargs['position_y'], $kwargs['arena'],
			$kwargs['direction']);
		if ($ship === NULL)
			error_log("ship that was shot was null (fight function, RedneckTrout.class.php)");
		else {
			$ship->shipIsShot($kwargs['arena']);
		}
	}
	
	public function __toString() {
		return "SniperTrout" . parent::__toString();
	}

public static function doc()
{
	return file_get_contents('./RedneckTrout.doc.txt') . PHP_EOL;
}

}

?>