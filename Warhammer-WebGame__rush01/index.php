<?php

include_once('Arena.class.php');
include_once('SniperTrout.class.php');
include_once('Obstacle.class.php');
include_once('resetGame.php');
include_once('getShipByName.php');
include_once('Bear.class.php');
include_once('KamikazeRock.class.php');
include_once('RedneckTrout.class.php');

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
		return "Health: " . $ship->getHealth();
	} else {
		return "Ship is dead!";
	}
}

function printShieldStats($name, $arena) {
	$ship = getShipByName($name, $arena);
	if ($ship) {
		return "Shield: " . $ship->getShield();
	} else {
		return "";
	}
}

function printPPStats($name, $arena) {
	$ship = getShipByName($name, $arena);
	if ($ship) {
		return "PP: " . $ship->getPP();
	} else {
		return "";
	}
}

function printMovePPStats($name, $arena) {
	$ship = getShipByName($name, $arena);
	if ($ship) {
		return "movePP: " . $ship->getMovePP();
	} else {
		return "";
	}
}

function printShootPPStats($name, $arena) {
	$ship = getShipByName($name, $arena);
	if ($ship) {
		return "shootPP: " . $ship->getShootPP();
	} else {
		return "";
	}
}

function getCurrentShipName($arena) {
	if ($arena->getShipPosition() == -1)
		return NULL;
	$ship = $arena->getShip();
	if ($ship !== NULL)
		return $ship->getName();
}

function getPhase($ship) {
	if ($ship->getPP() != 0)
		return "Order";
	else if ($ship->getMovePP() != 0)
		return "Movement";
	else
		return "Shoot";
}

?>

<html>
<head>
	<link rel="stylesheet" type="text/css" href="game.css"></head>
</head>
<body>
	<div id="background"></div>
	<div id="all" style="text-align:center">
		<h1>Trout: The Sequel</h1>

		<?php
		if (($shipPlaying = getCurrentShipName($_SESSION['arena'])) !== NULL) {
			$current_Phase = getPhase($_SESSION['arena']->getShip());
			echo <<<EOF
			<h4>Ship Playing : $shipPlaying</h4>
			<h5>Phase: $current_Phase</h5>
EOF;
		}
		else {
			echo <<<EOF
			<h5 class="subtitle">This is the story of three lonely trout scouring the oceans to find trout partners to grow old with. Two were male and one was female. But the female had literally no interest in the other two and so continued their quest. They feared being eaten by BIG GRIZZLY BEARS but were protected by their rock-like friends, the rocks. The rocks had been treated like shit for years by the bears, getting stamped on, broken, existence barely even acknowledged. They were pretty pissed about this and decided to blow themselves up to take out the bears. The bears, on the other hand, saw that YouTube video on honey badgers and decided they couldnt care less. Trout and rocks be damned.</h5>
			<h5></h5>
EOF;
		}
		?>	
	</div>
	<div class="all">
		<div class="trout_data">
			<h4>Trout controls:</h4>
			<br />
			<h5>Trout 1 - Redneck</h5>
			<div>
				<form class="centered_forms" action="move.php" method="POST">
					<input type="hidden" name="name" value="RedneckTrout1">
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
			</div>
			<div>
				<form class="centered_forms" action="shoot.php" method="POST">
					<input type="hidden" name="name" value="RedneckTrout1">
					<input name="shoot" value="shoot_down" type="submit">
					<input name="shoot" value="shoot_up" type="submit">
				</form>
			</div>
			<div>
				<form class="centered_forms" action="Order.php" method="POST">
					<input type="hidden" name="name" value="RedneckTrout1">
					<input name="movePP" value="increase movePP" type="submit">
					<input name="shootPP" value="increase shootPP" type="submit">
				</form>
			</div>
			<?php 	$var1 = printHealthStats('RedneckTrout1', $_SESSION['arena']); 
			$var2 = printShieldStats('RedneckTrout1', $_SESSION['arena']);
			$var3 = printPPStats('RedneckTrout1', $_SESSION['arena']);
			$var4 = printMovePPStats('RedneckTrout1', $_SESSION['arena']);
			$var5 = printShootPPStats('RedneckTrout1', $_SESSION['arena']);
			echo <<<EOF
			<p>$var1&emsp;$var2</p>
			<p>$var3&emsp;$var4&emsp;$var5</p>
			<br />
EOF;
			?>

			<h5>Trout 2 - Redneck</h5>
			<div>
				<form class="centered_forms" action="move.php" method="POST">
					<input type="hidden" name="name" value="RedneckTrout2">
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
			</div>
			<div>
				<form class="centered_forms" action="shoot.php" method="POST">
					<input type="hidden" name="name" value="RedneckTrout2">
					<input name="shoot" value="shoot_down" type="submit">
					<input name="shoot" value="shoot_up" type="submit">
				</form>
			</div>
			<div>
				<form class="centered_forms" action="Order.php" method="POST">
					<input type="hidden" name="name" value="RedneckTrout2">
					<input name="movePP" value="increase movePP" type="submit">
					<input name="shootPP" value="increase shootPP" type="submit">
				</form>
			</div>
			<?php 	$var1 = printHealthStats('RedneckTrout2', $_SESSION['arena']); 
			$var2 = printShieldStats('RedneckTrout2', $_SESSION['arena']);
			$var3 = printPPStats('RedneckTrout2', $_SESSION['arena']);
			$var4 = printMovePPStats('RedneckTrout2', $_SESSION['arena']);
			$var5 = printShootPPStats('RedneckTrout2', $_SESSION['arena']);
			echo <<<EOF
			<p>$var1&emsp;$var2</p>
			<p>$var3&emsp;$var4&emsp;$var5</p>
			<br />
EOF;
			?>

			<h5>Trout 3 - Sniper</h5>
			<div>
				<form class="centered_forms" action="move.php" method="POST">
					<input type="hidden" name="name" value="SniperTrout">
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
			</div>
			<div>
				<form class="centered_forms" action="shoot.php" method="POST">
					<input type="hidden" name="name" value="SniperTrout">
					<input name="shoot" value="shoot_down" type="submit">
					<input name="shoot" value="shoot_up" type="submit">
					<input name="shoot" value="shoot_left" type="submit">
					<input name="shoot" value="shoot_right" type="submit">
				</form>
			</div>
			<div>
				<form class="centered_forms" action="Order.php" method="POST">
					<input type="hidden" name="name" value="SniperTrout">
					<input name="movePP" value="increase movePP" type="submit">
					<input name="shootPP" value="increase shootPP" type="submit">
				</form>
			</div>
			<?php 	$var1 = printHealthStats('SniperTrout', $_SESSION['arena']); 
			$var2 = printShieldStats('SniperTrout', $_SESSION['arena']);
			$var3 = printPPStats('SniperTrout', $_SESSION['arena']);
			$var4 = printMovePPStats('SniperTrout', $_SESSION['arena']);
			$var5 = printShootPPStats('SniperTrout', $_SESSION['arena']);
			echo <<<EOF
			<p>$var1&emsp;$var2</p>
			<p>$var3&emsp;$var4&emsp;$var5</p>
			<br />
EOF;
			?>
		</div>
		<div id="central_table">

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
		</div>










		<div class="trout_data">
			<h4>Bear controls:</h4>
			<br />
			<h5>Bear 1 - D</h5>
			<div>
				<form class="centered_forms" action="move.php" method="POST">
					<input type="hidden" name="name" value="d">
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
			</div>
			<div>
				<form class="centered_forms" action="shoot.php" method="POST">
					<input type="hidden" name="name" value="d">
					<input name="shoot" value="explosion" type="submit">
				</form>
			</div>
			<div>
				<form class="centered_forms" action="Order.php" method="POST">
					<input type="hidden" name="name" value="d">
					<input name="movePP" value="increase movePP" type="submit">
					<input name="shootPP" value="increase shootPP" type="submit">
				</form>
			</div>
			<?php 	$var1 = printHealthStats('d', $_SESSION['arena']); 
			$var2 = printShieldStats('d', $_SESSION['arena']);
			$var3 = printPPStats('d', $_SESSION['arena']);
			$var4 = printMovePPStats('d', $_SESSION['arena']);
			$var5 = printShootPPStats('d', $_SESSION['arena']);
			echo <<<EOF
			<p>$var1&emsp;$var2</p>
			<p>$var3&emsp;$var4&emsp;$var5</p>
			<br />
EOF;
			?>

			<h5>Bear 2 - E</h5>
			<div>
				<form class="centered_forms" action="move.php" method="POST">
					<input type="hidden" name="name" value="e">
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
			</div>
			<div>
				<form class="centered_forms" action="shoot.php" method="POST">
					<input type="hidden" name="name" value="e">
					<input name="shoot" value="explosion" type="submit">
				</form>
			</div>
			<div>
				<form class="centered_forms" action="Order.php" method="POST">
					<input type="hidden" name="name" value="e">
					<input name="movePP" value="increase movePP" type="submit">
					<input name="shootPP" value="increase shootPP" type="submit">
				</form>
			</div>
			<?php 	$var1 = printHealthStats('e', $_SESSION['arena']); 
			$var2 = printShieldStats('e', $_SESSION['arena']);
			$var3 = printPPStats('e', $_SESSION['arena']);
			$var4 = printMovePPStats('e', $_SESSION['arena']);
			$var5 = printShootPPStats('e', $_SESSION['arena']);
			echo <<<EOF
			<p>$var1&emsp;$var2</p>
			<p>$var3&emsp;$var4&emsp;$var5</p>
			<br />
EOF;
			?>

			<h5>Bear 3 - F</h5>
			<div>
				<form class="centered_forms" action="move.php" method="POST">
					<input type="hidden" name="name" value="f">
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
			</div>
			<div>
				<form class="centered_forms" action="shoot.php" method="POST">
					<input type="hidden" name="name" value="f">
					<input name="shoot" value="explosion" type="submit">
				</form>
			</div>
			<div>
				<form class="centered_forms" action="Order.php" method="POST">
					<input type="hidden" name="name" value="f">
					<input name="movePP" value="increase movePP" type="submit">
					<input name="shootPP" value="increase shootPP" type="submit">
				</form>
			</div>
			<?php 	$var1 = printHealthStats('f', $_SESSION['arena']); 
			$var2 = printShieldStats('f', $_SESSION['arena']);
			$var3 = printPPStats('f', $_SESSION['arena']);
			$var4 = printMovePPStats('f', $_SESSION['arena']);
			$var5 = printShootPPStats('f', $_SESSION['arena']);
			echo <<<EOF
			<p>$var1&emsp;$var2</p>
			<p>$var3&emsp;$var4&emsp;$var5</p>
			<br />
EOF;
			?>
		</div>

	</div>
	<br />
	<br />	
	<div id="rocks">
		<div id="rock_info">
			<div id="c1">
				<h5>KamikazeRock 1 - G</h5>
				<div>
					<form class="centered_forms" action="move.php" method="POST">
						<input type="hidden" name="name" value="g">
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
				</div>
				<div>
					<form class="centered_forms" action="Order.php" method="POST">
						<input type="hidden" name="name" value="g">
						<input name="movePP" value="increase movePP" type="submit">
					</form>
				</div>
				<?php 	$var1 = printHealthStats('g', $_SESSION['arena']); 
				$var2 = printShieldStats('g', $_SESSION['arena']);
				$var3 = printPPStats('g', $_SESSION['arena']);
				$var4 = printMovePPStats('g', $_SESSION['arena']);
				echo <<<EOF
				<p>$var1&emsp;$var2</p>
				<p>$var3&emsp;$var4</p>
				<br />
EOF;
				?>
			</div>
			<div id="c2">
				<h5>KamikazeRock 2 - H</h5>
				<div>
					<form class="centered_forms" action="move.php" method="POST">
						<input type="hidden" name="name" value="h">
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
				</div>
				<div>
					<form class="centered_forms" action="Order.php" method="POST">
						<input type="hidden" name="name" value="h">
						<input name="movePP" value="increase movePP" type="submit">
					</form>
				</div>
				<?php 	$var1 = printHealthStats('h', $_SESSION['arena']); 
				$var2 = printShieldStats('h', $_SESSION['arena']);
				$var3 = printPPStats('h', $_SESSION['arena']);
				$var4 = printMovePPStats('h', $_SESSION['arena']);
				echo <<<EOF
				<p>$var1&emsp;$var2</p>
				<p>$var3&emsp;$var4</p>
				<br />
EOF;
				?>
			</div>
			<div id="c3">
				<h5>KamikazeRock 3 - I</h5>
				<div>
					<form class="centered_forms" action="move.php" method="POST">
						<input type="hidden" name="name" value="i">
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
				</div>
				<div>
					<form class="centered_forms" action="Order.php" method="POST">
						<input type="hidden" name="name" value="i">
						<input name="movePP" value="increase movePP" type="submit">
					</form>
				</div>
				<?php 	$var1 = printHealthStats('i', $_SESSION['arena']); 
				$var2 = printShieldStats('i', $_SESSION['arena']);
				$var3 = printPPStats('i', $_SESSION['arena']);
				$var4 = printMovePPStats('i', $_SESSION['arena']);
				echo <<<EOF
				<p>$var1&emsp;$var2</p>
				<p>$var3&emsp;$var4</p>
				<br />
EOF;
				?>

			</div>
		</div>
		<br />
		<form action="reset.php" method="POST">
			<input name="reset" value="reset" type="submit" />
		</form>
	</div>
	<br />

</body>
<footer>
	This is the story of three lonely trout scouring the oceans to find trout partners to grow old with. Two were male and one was female. But the female had literally no interest in the other two and so continued their quest. They feared being eaten by BIG GRIZZLY BEARS but were protected by their rock-like friends, the rocks.

The rocks had been treated like shit for years by the bears, getting stamped on, broken, existence barely even acknowledged. They were pretty pissed about this and decided to blow themselves up to take out the bears.

The bears, on the other hand, saw that YouTube video on honey badgers and decided they couldnt care less. Trout and rocks be damned.
</footer>
</html>


