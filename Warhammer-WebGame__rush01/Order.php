<?php

# calls move for the correct ship

include_once('Arena.class.php');
include_once('SniperTrout.class.php');
include_once('Obstacle.class.php');
include_once('Bear.class.php');
include_once('KamikazeRock.class.php');
include_once('getShipByName.php');
include_once('RedneckTrout.class.php');

session_start();

header('Location: index.php');

$shipSelected = getShipByName($_POST['name'], $_SESSION['arena']);

if ($_SESSION['arena']->getShipPosition() == -1) {
	$shipToOrder = $shipSelected;
	$_SESSION['arena']->getShipPositionAtBeginning($shipToOrder);
}
else
	$shipToOrder = $_SESSION['arena']->getShip();

#block all others

if ($shipToOrder === $shipSelected)
{
	if ($_POST['movePP'])
		$ismove = 1;
	else if ($_POST['shootPP'])
		$ismove = 0;
	$shipToOrder->setPPpoints($ismove, $_SESSION['arena']);
}

?>