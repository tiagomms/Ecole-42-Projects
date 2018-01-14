<?php
include("../php_assets/exit_to.php");
include("../php_assets/return_to.php");
set_return_to((isset($_GET['return_to']) ? $_GET['return_to'] : ""));
session_start();
// Default action
if (!isset($_GET["action"])) {
	$_GET["action"] = "login";
}
// NULL -> ""
if (!isset($_SESSION['current_user'])) {
	$_SESSION['current_user'] = "";
}
switch ($_GET["action"]) {
	case "login":
		//If the user is logged in but gets here, get him out
		if ($_SESSION['current_user'] !== "")
			return_to('Already logged in!');
		$title = "Login";
		$form = <<<EOT
<form method="post" action="login.php">
	Username: <input type="text" name="login" value=""/>
	<br />
	Password: <input type="password" name="passwd" value=""/>
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<a href="/login/index.php?action=create"><button>Create an account</button></a>
EOT;
		break;
	case "logout":
		//Should log out and send back to homepage
		exit_to("/login/logout.php");
		break;
	case "create":
		//If the user is logged in but gets here, get him out
		$title = "Create Account";
		$form = <<<EOT
<form method="post" action="create.php">
	Username: <input type="text" name="login" value=""/>
	<br />
	Password: <input type="password" name="passwd" value=""/>
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
EOT;
		break;
	case "modif":
		//If the user is NOT logged in but gets here, get him out
		if ($_SESSION['current_user'] === "")
			exit_to("/");
		$title = "Change Password";
		$current_user = $_SESSION['current_user'];
		$form = <<<EOT
<form method="post" action="modif.php">
	Username: <input type="text" name="login" value="$current_user"/>
	<br />
	Old Password: <input type="password" name="oldpw" value=""/>
	<br />
	New Password: <input type="password" name="newpw" value=""/>
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
EOT;
		break;
}
?>
<html>
<head>
	<title><?php echo $title."\n"; ?></title>
	<link rel="stylesheet" type="text/css" href="login.css">
	<link rel="stylesheet" type="text/css" href="../header.css">
</head>
<body>
	<?php include("../header.php"); ?>
	<div style="margin-left: auto; margin-right: auto; max-width: 1280px; min-width:840px;">
		<h1><?php echo $title; ?></h1>
		<?php echo $form."\n"; ?>
		<a href="/">
		    <button>Home</button>
		</a>
	</div>
</body>
</html>
