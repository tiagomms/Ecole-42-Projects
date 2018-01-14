<?php

include_once('Arena.class.php');
include_once('Scout.class.php');
include_once('Obstacle.class.php');

@session_start();

function resetGame() {
	$arena = new Arena();

	$arena->addOnScreen( new Scout(0, 0, 'a') );
	$arena->addOnScreen( new Scout($arena->getWidth() - 1, $arena->getHeight() - 1, 'b') );

	$arena->addOnScreen( new Obstacle(10, 10, 10, 10) );
	$arena->addOnScreen( new Obstacle(14, 4, 2, 2) );
	$arena->addOnScreen( new Obstacle(24, 14, 2, 2) );
	$arena->addOnScreen( new Obstacle(14, 24, 2, 2) );
	$arena->addOnScreen( new Obstacle(4, 14, 2, 2) );

    $_SESSION['arena'] = $arena;
}

?>