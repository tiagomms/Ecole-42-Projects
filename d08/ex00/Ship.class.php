<?php

include_once('OnScreen.class.php');

abstract class Ship extends OnScreen {

	protected $max_health;
	protected $health;
	protected $default_shield;
	protected $shield;
	protected $speed;
	protected $agility;

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
		$this->pointsDePuissance = $kwargs['pp'];
		$this->shield = $kwargs['shield'];
		
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
		if($this->position_x < 0 || $this->position_x >= $arena->getWidth()
			|| $this->position_y < 0 || $this->position_y >= $arena->getHeight())
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
			if ($arena->getTileContents($this->position_x + $x, $this->position_y + $y) !== NULL) {
				$arena->destroyShip($this);
			} else {
				$this->position_x += $x;
				$this->position_y += $y;
			}
		}
	}

	public function getHealth() {		return $this->health; }
	public function getShield() {		return $this->shield; }
	public function getSpeed() {		return $this->speed; }
	public function getAgility() {		return $this->agility; }
} 

?>