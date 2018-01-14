<?php

class Targaryen {

	public function resistsFire() {
		return;
	}

	public function getBurned() {
		if ($this->resistsFire() === True)
			return 'emerges naked but unharmed';
		else
			return 'burns alive';
	}
}

?>