<?PHP

Class Color {

	public $red = 0;
	public $blue = 0;
	public $green = 0;
	public static $verbose = False;

	public function __construct(array $kwargs)
	{
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = (($kwargs['rgb'] >> 16) & 255);
			$this->green = (($kwargs['rgb'] >> 8) & 255);
			$this->blue = (($kwargs['rgb']) & 255);
		}
		else if (array_key_exists('red', $kwargs) 
			&& array_key_exists('blue', $kwargs)
			&& array_key_exists('green', $kwargs))
		{
			$this->red = intval($kwargs['red']);
			$this->blue = intval($kwargs['blue']);
			$this->green = intval($kwargs['green']);
		}
		if (self::$verbose === True)
			print( $this . ' constructed.' . PHP_EOL);
		return;
	}

	public function __destruct() {
		if (self::$verbose === True)
			print( $this . ' destructed.' . PHP_EOL);
		return;
	}

	public function __toString() {
		return sprintf('Color( red: %3d, green: %3d, blue: %3d )', $this->red, $this->green, $this->blue);
	}

	public function add(Color $add_color)
	{
		return new Color( array ('red' => $this->red + $add_color->red, 'green' => $this->green + $add_color->green, 'blue' => $this->blue + $add_color->blue ) );
	}

	public function sub(Color $sub_color)
	{
		return new Color(array ('red' => $this->red - $sub_color->red, 'green' => $this->green - $sub_color->green, 'blue' => $this->blue - $sub_color->blue ) );
	}

	public function mult($f)
	{
		return new Color(array ('red' => $this->red * $f, 'green' => $this->green * $f, 'blue' => $this->blue * $f ) );
	}

	public static function doc()
	{
		return file_get_contents('./Color.doc.txt') . PHP_EOL;
	}
}
?>