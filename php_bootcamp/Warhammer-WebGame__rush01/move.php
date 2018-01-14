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

# debugging
?>
<!-- <pre>
<?php print_r($_SESSION['arena']); ?>
</pre> -->
<?php

$exploded = explode(',', $_POST['move']);
$delta_x = intval($exploded[0]);
$delta_y = intval($exploded[1]);

$shipSelected = getShipByName($_POST['name'], $_SESSION['arena']);

$shipToMove = $_SESSION['arena']->getShip();

if ($shipToMove && $shipToMove->getPP() == 0 && $shipSelected === $shipToMove)
{
	if ($shipToMove->getMovePP() != 0)
	{
		$shipToMove->move($delta_x, $delta_y, $_SESSION['arena']);
		$shipToMove->decreaseMovePP();
	}
	if ($shipToMove->getMovePP() == 0 && $shipToMove->getShootPP() == 0)
	{
		$shipToMove->setPP();
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