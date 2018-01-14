<?php

include_once('OnScreen.class.php');
include_once('Obstacle.class.php');
include_once('SniperTrout.class.php');
include_once('Bear.class.php');
include_once('KamikazeRock.class.php');
include_once('RedneckTrout.class.php');

class Arena {
	private $_width;
	private $_height;
	private $_onScreens = array();
	private $_ship_position = -1;
	public  $slicing_needed;

	public function __construct() {
		$this->_width = 150;
		$this->_height = 100;
	}

	public function addOnScreen($ship) {
		$this->_onScreens[] = $ship;
	}
	
	public function getTileContents($x, $y, $ship) {
		foreach ( $this->_onScreens as $current ) {
			if ($current->isOccupying($x, $y) && $current !== $ship) {
				return $current;
			}
		}
		return null;
	}
	
	public function __toString() {
		$drawables = "";
		foreach( $this->getOnScreens() as $current ) {
			$drawables = $drawables . " " . $current;
		}
		return sprintf("Arena[ width: %d ; height: %d ; onScreens: [%s]"
						, $this->_width, $this->_height, $drawables);
	}

	public function destroyShip($ship) {
		if (($key = array_search($ship, $this->_onScreens)) !== false){
				if ($this->getShip() === $ship)
				{
					unset($this->_onScreens[$key]);
					$this->_onScreens = array_slice($this->_onScreens, 0);
					$this->_ship_position -= 2;
					$this->setShipPosition();
				}	
 			    else {
 			    	unset($this->_onScreens[$key]);
 			    	$slicing_needed = 1;
 			    }
 			   
			}
	}

	public function getShipPositionAtBeginning($ship) {	
		return $this->_ship_position = array_search($ship, $this->_onScreens); 
	}

	public function setShipPosition() {	
		$this->_ship_position++;
		while (get_class($this->getShip()) === 'Obstacle' || $this->getShip() === NULL) {
			$this->_ship_position++;
			if (get_class($this->getShip()) === 'Obstacle') {
				$this->_ship_position = 0;
				break ;
			}
		}
		return $this->_ship_position;
	}

	public function getShipPosition() { 		return $this->_ship_position;}
	public function getShip() { 				return $this->_onScreens[$this->_ship_position];}	
	public function getHeight() {				return $this->_height;		}
	public function getWidth() {				return $this->_width;		}
	public function getOnScreens() {			return $this->_onScreens;	}

public static function doc()
{
	return file_get_contents('./Arena.doc.txt') . PHP_EOL;
}

}



?>