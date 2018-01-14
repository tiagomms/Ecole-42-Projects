<?php

class NightsWatch implements IFighter{

	private $_recruits = array();

	public function recruit($guy) {
		if ($guy instanceof IFighter)
			$this->_recruits[] = $guy;
	}

	public function fight(){
		foreach ($this->_recruits as $guy) {
			$guy->fight();
		}
	}
}

?>