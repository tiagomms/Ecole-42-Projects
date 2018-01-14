<?php

include_once('OnScreen.class.php');
include_once('Obstacle.class.php');
include_once('Scout.class.php');


class Arena {
	private $_width;
	private $_height;
	private $_onScreens = array();

	public function __construct() {
		$this->_width = 150;
		$this->_height = 100;
	}

	public function addOnScreen($ship) {
		$this->_onScreens[] = $ship;
	}
	
	public function getTileContents($x, $y) {
		foreach ( $this->_onScreens as $current ) {
			if ($current->isOccupying($x, $y)) {
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
 			   unset($this->_onScreens[$key]);
			}
	}

	public function getHeight() {		return $this->_height;		}
	public function getWidth() {		return $this->_width;		}
	public function getOnScreens() {	return $this->_onScreens;	}
}

?>