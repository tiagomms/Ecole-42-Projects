<?php

class Lannister {
    public function sleepFamily() {
        return TRUE;
    }
    
    public function sleepWith($person) {
        if (is_subclass_of($person, 'Lannister') === FALSE)
        	print("Let's do this." . PHP_EOL);
        else if (is_subclass_of($person, 'Lannister') === TRUE &&
         $this->sleepFamily() === TRUE &&
         $person->sleepFamily() === TRUE)
            print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
        else
            print("Not even if I'm drunk !" . PHP_EOL);
    }
}

?>