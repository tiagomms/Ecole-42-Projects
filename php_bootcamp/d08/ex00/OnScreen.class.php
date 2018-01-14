<?php

 class OnScreen {

	# position_x/y is the top left corner
	protected $name;
	protected $position_x;
	protected $position_y;
	protected $width;
	protected $height;

	public function __construct( array $kwargs ) {
		if ( !isset( $kwargs['name'] ) 
				|| !isset( $kwargs['x'] )
				|| !isset( $kwargs['y'] )
				|| !isset( $kwargs['width'] )
				|| !isset( $kwargs['height'] ) ) {
			error_log("OnScreen error: incorrect parameters to constructor"
						. PHP_EOL );
			exit(1);
		}
		$this->name = $kwargs['name'];
		$this->position_x = $kwargs['x'];
		$this->position_y = $kwargs['y'];
		$this->width = $kwargs['width'];
		$this->height = $kwargs['height'];
	}
	
	public function isOccupying($x, $y) {
		# returns whether the OnScreen is over ($x, $y)
		return ( $x >= $this->position_x
				&& $x < $this->position_x + $this->width
				&& $y >= $this->position_y
				&& $y < $this->position_y + $this->height);
	}

	public function getName() {			return $this->name; 		}
	public function getPositionX() {	return $this->position_x;	}
	public function getPositionY() {	return $this->position_y;	}
	public function getWidth() {		return $this->width;		}
	public function getHeight() {		return $this->height;		}
}

?>