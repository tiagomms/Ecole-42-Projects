<?php

include_once('Arena.class.php');
include_once('SniperTrout.class.php');
include_once('Obstacle.class.php');
include_once('Bear.class.php');
include_once('KamikazeRock.class.php');
include_once('RedneckTrout.class.php');

@session_start();

function resetGame() {
	$arena = new Arena();

	$arena->addOnScreen( new RedneckTrout(0, 0, 'RedneckTrout1', 1) );
	$arena->addOnScreen( new RedneckTrout(5, 2, 'RedneckTrout2', 1) );
	$arena->addOnScreen( new SniperTrout(4, 4, 'SniperTrout', 1) );
	$arena->addOnScreen( new Bear($arena->getWidth() - 7, $arena->getHeight() - 3,'d', 2) );
	$arena->addOnScreen( new Bear($arena->getWidth() - 12, $arena->getHeight() - 5,'e', 2) );
	$arena->addOnScreen( new Bear($arena->getWidth() - 12, $arena->getHeight() - 9,'f', 2) );
	$arena->addOnScreen( new KamikazeRock(16, 4, 3, 3, 'g', 3) ); 
	$arena->addOnScreen( new KamikazeRock(7, 5, 3, 3, 'h', 3) ); 
	$arena->addOnScreen( new KamikazeRock(10, 2, 3, 3, 'i', 3) ); 

	$arena->addOnScreen( new Obstacle(10, 10, 10, 10) );
	$arena->addOnScreen( new Obstacle(14, 4, 2, 2) );
	$arena->addOnScreen( new Obstacle(24, 14, 2, 2) );
	$arena->addOnScreen( new Obstacle(14, 24, 2, 2) );
	$arena->addOnScreen( new Obstacle(4, 14, 2, 2) );

    $_SESSION['arena'] = $arena;
}

?>