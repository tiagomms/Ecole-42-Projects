<?php

class UnholyFactory {

	private $_fighters = array();
	
	public function absorb($model) {
		if (is_subclass_of($model, 'Fighter') === FALSE)
			printf("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
		else if (array_key_exists($model->type, $this->_fighters) === TRUE)
			printf('(Factory already absorbed a fighter of type %s)' . PHP_EOL, $model->type);
		else
		{
			$this->_fighters[$model->type] = $model;
			printf('(Factory absorbed a fighter of type %s)' . PHP_EOL, $model->type);
			return;
		}
	}

	public function fabricate($requested) {
		if (array_key_exists($requested, $this->_fighters) === FALSE)
		{
			printf("(Factory hasn't absorbed any fighter of type %s)" . PHP_EOL, $requested);
			return;
		}
		else
		{
			printf("(Factory fabricates a fighter of type %s)" . PHP_EOL, $requested);
			return clone($this->_fighters[$requested]);
		}
	}
}

?>