<?php

include_once('OnScreen.class.php');

abstract class Ship extends OnScreen {

	protected $max_health;
	protected $health;
	protected $default_shield;
	protected $shield;
	protected $speed;
	protected $agility;
	protected $pp;
	protected $movePP;
	protected $shootPP;
	protected $defaultPP;
	protected $_current_ship;

	public function __construct( array $kwargs ) {
		parent::__construct( $kwargs );
		
		if ( !isset( $kwargs['max_health'] )
				|| !isset( $kwargs['shield'] )
				|| !isset( $kwargs['pp'] ) 
				|| !isset( $kwargs['speed'])
				|| !isset( $kwargs['agility'])) {
			error_log("Ship error: incorrect parameters to constructor"
						. PHP_EOL );
			exit(1);
		}
		$this->max_health = $kwargs['max_health'];
		$this->defaultShield = $kwargs['shield'];
		$this->pp = $kwargs['pp'];
		$this->shield = $kwargs['shield'];
		$this->movePP = $kwargs['movePP'];
		$this->shootPP = $kwargs['shootPP'];
		$this->defaultPP = $kwargs['pp'];
		
		# setup for start of game
		$this->health = $this->max_health;
	}
	
	# should be called at the beginning of each turn to reset things
#	public function beginningOfTurn() {
#		$this->shield = $this->default_shield;
#	}

	public abstract function fight(array $kwargs);
	
	public function __toString() {
		return sprintf( "%s[ health: %d ; default_shield: %d ; position (%d, %d) ]"
						, $this->name, $this->health, $this->default_shield
						, $this->position_x, $this->position_y);
	}
	
	public function isInLimits($arena)
	{
		#check if the ship has gone out of screen
		if($this->position_x < 0 
			|| $this->position_x + $this->width - 1 >= $arena->getWidth()
			|| $this->position_y < 0 
			|| $this->position_y + $this->height - 1 >= $arena->getHeight())
		{
			$arena->destroyShip($this);
			return FALSE;
		}
		return TRUE;
	}

	# happens when a ship is hit with a shot
	public function shipIsShot($arena) {
		if ($this->shield == 0)
			$this->health = $this->health - 1;
		else
			$this->shield = $this->shield - 1;
		if ($this->health <= 0)
		{
			$arena->destroyShip($this);
		}
	}

	public function move($x, $y, $arena) {
		$this->position_x += $x;
		$this->position_y += $y;
		if ($this->isInLimits($arena) == TRUE)
		{
			$this->position_x -= $x;
			$this->position_y -= $y;
			$current_x = 0;
			while ($current_x < $this->width) {
				$current_y = 0;

				while ($current_y < $this->height) {
					if (($encountered_object = $arena->getTileContents($this->position_x + $x + $current_x,
						$this->position_y + $y + $current_y, $this)) !== NULL) {
						if (get_class($this) === 'KamikazeRock'
							&& get_class($encountered_object) !== 'Obstacle')
							$arena->destroyShip($encountered_object);
						$arena->destroyShip($this);
						break;
					}
					$current_y++;
				}
				$current_x++;
			}
			if ($current_x == $this->width && $current_y == $this->height)
			{
				$this->position_x += $x;
				$this->position_y += $y;
			}
		}
	}

	public function setPPpoints($ismove, $arena) {
		$current_PP = $this->getPP();
		if ($current_PP != 0) {
				if ($ismove == 1)
					$this->setMovePP();
				else 
					$this->setShootPP();
				$this->decreasePP();
		}
	}

	public function setPP() 		{ $this->pp = $this->defaultPP; }
	public function setMovePP() 	{ $this->movePP += 1; }
	public function setShootPP() 	{ $this->shootPP += 1; }
	public function decreasePP() 	{ $this->pp -= 1; }
	public function decreaseMovePP() { $this->movePP -= 1; }
	public function decreaseShootPP() { $this->shootPP -= 1; }


	public function getHealth() {		return $this->health; }
	public function getShield() {		return $this->shield; }
	public function getSpeed() {		return $this->speed; }
	public function getAgility() {		return $this->agility; }
	public function getPP() {			return $this->pp; }
	public function getDefaultPP() {	return $this->defaultPP; }
	public function getMovePP() {		return $this->movePP; }
	public function getShootPP() {		return $this->shootPP; }

public static function doc()
{
	return file_get_contents('./Ship.doc.txt') . PHP_EOL;
}

}

?>