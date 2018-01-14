<?php

include_once('Arena.class.php');
include_once('Scout.class.php');
include_once('Obstacle.class.php');
include_once('resetGame.php');
include_once('getShipByName.php');

@session_start();

if (!isset($_SESSION['arena'])) {
	resetGame();
}

function getShipName($x, $y, $arena) {
	foreach ( $arena->getOnScreens() as $current ) {
		if ( $current->isOccupying($x, $y) ) {
			return $current->getName();
		}
	}
	return "empty";
}

function printHealthStats($name, $arena) {
	$ship = getShipByName($name, $arena);
	if ($ship) {
		echo "Ship " . $name . " health: " . $ship->getHealth();
	} else {
		echo "Ship is dead!";
	}
}

function printShieldStats($name, $arena) {
	$ship = getShipByName($name, $arena);
	if ($ship) {
		echo "Ship " . $name . " shield: " . $ship->getShield();
	} else {
		echo "No shield on ship " . $name . ".";
	}
}

?>

<html>
<head>
	<link rel="stylesheet" type="text/css" href="game.css"></head>
</head>
<body>
	<table>
<?php
		$row = 0;

		while ($row < $_SESSION['arena']->getHeight()) {
			$column = 0;
?>
			<tr>
<?php
			while ( $column < $_SESSION['arena']->getWidth() ) {
?>
				<td class="<?= getShipName($column, $row, $_SESSION['arena'])?>"></td>
<?php
				$column++;
			}
?>
			</tr>
<?php
			$row++;
		}
?>

</table>
	<h4>Ship A controls:</h4>
	<br/>
	<form action="move.php" method="POST">
		<input type="hidden" name="name" value="a">
		<div>
			<input name="move" value="0, -1" type="submit" />
		</div>
		<div>
			<input name="move" value="-1, 0" type="submit" />
			<input name="move" value="1, 0" type="submit" />
		</div>
		<div>
			<input name="move" value="0, 1" type="submit" />
		</div>
	</form>
	<form action="shoot.php" method="POST">
		<input type="hidden" name="name" value="a">
		<input name="shoot" value="shoot_down" type="submit">
		<input name="shoot" value="shoot_up" type="submit">
	</form>
	<?php printHealthStats('a', $_SESSION['arena']); ?>
	<br />
	<?php printShieldStats('a', $_SESSION['arena']); ?>
	
	<h4>Ship B controls:</h4>
	<br/>
	<form action="move.php" method="POST">
		<input type="hidden" name="name" value="b">
		<div>
			<input name="move" value="0, -1" type="submit" />
		</div>
		<div>
			<input name="move" value="-1, 0" type="submit" />
			<input name="move" value="1, 0" type="submit" />
		</div>
		<div>
			<input name="move" value="0, 1" type="submit" />
		</div>
	</form>
	
	<form action="shoot.php" method="POST">
		<input type="hidden" name="name" value="b">
		<input name="shoot" value="shoot_down" type="submit">
		<input name="shoot" value="shoot_up" type="submit">
	</form>
	<?php printHealthStats('b', $_SESSION['arena']); ?>
	<br />
	<?php printShieldStats('b', $_SESSION['arena']); ?>

	<p></p>
	<p></p>
	<form action="reset.php" method="POST">
		<input name="reset" value="reset" type="submit" />
	</form>

</body>
</html>


