<?php

include_once('Arena.class.php');
include_once('SniperTrout.class.php');
include_once('Obstacle.class.php');
include_once('Bear.class.php');
include_once('KamikazeRock.class.php');
include_once('RedneckTrout.class.php');
include_once('getShipByName.php');

session_start();

$direction_shoot = $_POST['shoot'];

$shipSelected = getShipByName($_POST['name'], $_SESSION['arena']);

$shipThatShoots = $_SESSION['arena']->getShip();

if ($shipThatShoots && $shipThatShoots->getPP() == 0 &&
	$shipThatShoots->getMovePP() == 0 && $shipSelected === $shipThatShoots)
{
	if ($shipThatShoots->getShootPP() != 0) {
		$shipThatShoots->fight(array("dice_roll" => "short"
							, "width" => $shipThatShoots->getWidth()
							, "height" => $shipThatShoots->getHeight()
							, "position_x" => $shipThatShoots->getPositionX()
							, "position_y" => $shipThatShoots->getPositionY()
							, "arena" => $_SESSION['arena']
							, "direction" => $_POST['shoot']));
		$shipThatShoots->decreaseShootPP();
	}
	if ($shipThatShoots->getShootPP() == 0)
	{
		$shipThatShoots->setPP();
		if ($_SESSION['arena']->slicing_needed == 1)
		{
			$this->_onScreens = array_slice($this->_onScreens, 0);
			$_SESSION['arena']->slicing_needed = 0;
		}
		$_SESSION['arena']->setShipPosition();
	}
}

header('Location: index.php');

?>