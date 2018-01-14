<?php

# calls move for the correct ship

include_once('Arena.class.php');
include_once('Scout.class.php');
include_once('Obstacle.class.php');

include_once('getShipByName.php');

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


$shipToMove = getShipByName($_POST['name'], $_SESSION['arena']);
if ($shipToMove)
	$shipToMove->move($delta_x, $delta_y, $_SESSION['arena']);

header('Location: index.php');

?>