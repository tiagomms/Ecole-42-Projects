<?php

class House {

	public function introduce() {
		printf('House %s of %s : "%s"'  . PHP_EOL, static::getHouseName(), static::getHouseSeat(), static::getHouseMotto());
		return;
	}
	
}

?>