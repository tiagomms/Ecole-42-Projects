<?PHP
include("../php_assets/exit_to.php");
include("../php_assets/return_to.php");
set_return_to("/admin");
session_start();
//Make sure user is admin
if (!file_exists("../private/passwd")) {
	exit_to("/", "NO USERS");
}
$passwd_file = file_get_contents("../private/passwd");
$passwd_database = unserialize($passwd_file);
if (!isset($_SESSION['current_user'])                             ||
	!isset($passwd_database[$_SESSION['current_user']])           ||
	$passwd_database[$_SESSION['current_user']]['admin'] !== true) {
	exit_to("/", "NOT ADMIN");
}
$admin_name = $_SESSION['current_user'];
//Get CSV
$csv_file = file_get_contents("../db/products.csv");
?>
<html>
<head>
	<title>Admin</title>
	<link rel="stylesheet" type="text/css" href="admin.css">
	<link rel="stylesheet" type="text/css" href="../header.css">
</head>
<body>
	<?php include("../header.php"); ?>
	<div style="margin-left: auto; margin-right: auto; max-width: 1280px; min-width:840px;">
		<h1>Admin Page [<?php echo $admin_name; ?>]</h1>
		<h2>Product Database:</h2>
		<form method="post" action="../db/update.php">
			<textarea name="content" rows=20 cols=100 wrap="off"><?php echo $csv_file; ?></textarea>
			<br />
			<input type="submit" name="submit" value="OK" />
		</form>
		<h2>Users:</h2>
		<ul>
			<?php
			foreach ($passwd_database as $login => $data) {
				if ($login === $admin_name) {
					continue ;
				}
				if ($data['admin'] == 0) {
					$is_admin  = "";
				} else {
					$is_admin  = "checked";
				}
				echo <<<EOT
			<li>
				<form method="post" action="../login/admin_update.php">
					<input type="hidden" name="login" value="$login"/>[$login]:
					<input type="text" name="passwd" value=""/>
					Is Admin:<input type="checkbox" name="admin" value="true" $is_admin>
					<input type="submit" name="submit" value="Update" />
				</form>
				<form method="post" action="../login/admin_update.php">
					<input type="hidden" name="login" value="$login"/>
					<input type="submit" name="submit" value="Delete" />
				</form>
			</li>
EOT;
			}
			?>
			<li>
				<form method="post" action="../login/create.php">
					[<input type="text" name="login" value="Username"/>]:
					<input type="text" name="passwd" value="Password"/>
					Is Admin:<input type="checkbox" name="admin" value="true">
					<input type="hidden" name="submit" value="OK" />
					<input type="submit" name="create" value="Create" />
				</form>
			</li>
		</ul>

		<h2>Archive of orders:</h2>
		<div>
			<?PHP
				if (!file_exists("../private"))
					mkdir("../private");
				if (!file_exists("../private/archive"))
					file_put_contents("../private/archive", "");
				$archive_file = file_get_contents("../private/archive");
				$archive_database = unserialize($archive_file);

				if (count($archive_database) > 0)
				{
					foreach($archive_database as $key => $data)
					{
						echo "<h3>$key</h3>";
						foreach ($data as $archive) {
							date_default_timezone_set("Europe/Paris");
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
				}
				else
				{
					echo "That's sad! No one has ordered anything yet!";
				}
				
			?>
		</div>
	</div>
</body>
</html>
