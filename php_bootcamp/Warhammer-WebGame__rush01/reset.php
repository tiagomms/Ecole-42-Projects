<?php

include_once('resetGame.php');

if (isset($_POST['reset'])) {
	resetGame();
	header('Location: index.php');
}

?>