<?PHP
include("../php_assets/exit_to.php");
include("../php_assets/return_to.php");
set_return_to("/user");
session_start();
//Mak sure user is admin
if (!file_exists("../private/passwd")) {
	exit_to("/", "NO USERS");
}
$passwd_file = file_get_contents("../private/passwd");
$passwd_database = unserialize($passwd_file);
if (!isset($_SESSION['current_user'])                   ||
	!isset($passwd_database[$_SESSION['current_user']])) {
	exit_to("/", "NOT REAL USER OR LOGGED IN");
}
$user_name = $_SESSION['current_user'];
?>
<html>
<head>
	<title>User Page</title>
	<link rel="stylesheet" type="text/css" href="user.css">
	<link rel="stylesheet" type="text/css" href="../header.css">
</head>
<body>
	<?php include("../header.php"); ?>
	<div style="margin-left: auto; margin-right: auto; max-width: 1280px; min-width:840px;">
		<h1>Welcome back, <?php echo $user_name; ?></h1>
		<h2>Archive:</h2>
		<ul>
			<?php
				if (!file_exists("../private"))
					mkdir("../private");
				if (!file_exists("../private/archive"))
					file_put_contents("../private/archive", "");
				$archive_file = file_get_contents("../private/archive");
				$archive_database = unserialize($archive_file);
				if ($archive_database && $archive_database[$user_name])
				{
					date_default_timezone_set("Europe/Paris");
					foreach ($archive_database[$user_name] as $archive) {
						$time_bought = date('l jS \of F Y h:i:s A', $archive['time']);
						echo <<<EOT
					<li>
						$time_bought
						<ul>
EOT;
						foreach ($archive['products'] as $product => $quantity) {
							echo <<<EOT
							<li>$product :: $quantity</li>
EOT;
						}
						echo <<<EOT
						</ul>
					</li>
EOT;
					}
				}
				else
				{
					echo "Archive is empty";
				}
			?>
		</ul>
	</div>
</body>
</html>
