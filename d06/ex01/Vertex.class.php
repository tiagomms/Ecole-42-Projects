<?php

Class Vertex {

	private $_x = 0;
	private $_y = 0;
	private $_z = 0;
	private $_w = 1.0;
	private $_color = array('red' => 255, 'green' => 255, 'blue' => 255);
	public static $verbose = False;

	public function __construct(array $kwargs) {
		if (array_key_exists('color', $kwargs))
		{
			$this->_color['red'] = intval($kwargs['color']->red);
			$this->_color['green'] = intval($kwargs['color']->green);
			$this->_color['blue'] = intval($kwargs['color']->blue);
		}
		if (array_key_exists('x', $kwargs) 
			&& array_key_exists('y', $kwargs)
			&& array_key_exists('z', $kwargs))
		{
			$this->_x = $kwargs['x'];
			$this->_y = $kwargs['y'];
			$this->_z = $kwargs['z'];						
		}
		if (array_key_exists('w', $kwargs))
		{
			$this->_w = $kwargs['w'];
		}
		if (self::$verbose === True)
			print( $this . ' constructed' . PHP_EOL);
		return;
	}

	public function __destruct() {
		if (self::$verbose === True)
			print( $this . ' destructed' . PHP_EOL);
		return;
	}

	public function __toString() {
		if (self::$verbose === True)
			return sprintf('Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) )',
				$this->_x, $this->_y, $this->_z, $this->_w, $this->_color['red'],
				$this->_color['green'], $this->_color['blue']);
		else
			return sprintf('Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )', $this->_x, $this->_y, $this->_z, $this->_w); 
	}

	public static function doc()
	{
		return file_get_contents('./Vertex.doc.txt') . PHP_EOL;
	}
}
?>