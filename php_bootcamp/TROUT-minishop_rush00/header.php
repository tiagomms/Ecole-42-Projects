<div id="header">
	<div id="header_left">
		<img src="../images/trout.png" alt="LOGO">
		<div class="underneath_text">
			<?php
				session_start();
				if (!isset($_SESSION['current_user'])) {
					$_SESSION['current_user'] = "";
				}
				function login_link($action, $name) {
				echo <<<EOT
		<a id="login_$action" class="login_link" href="/login?action=$action">
			<button>$name</button>
		</a>
EOT;
				}

				if ($_SESSION['current_user'] === "") {
					login_link("login", "Login");
					login_link("create", "Create a new account");
				} else {
					echo $_SESSION['current_user'];
					login_link("modif", "Change Password");
					login_link("logout", "Logout");
				}
			?>
		</div>
	</div>
	<div id="header_center">
		<div class="middle_thingy">
			<a href="../products">
				<img class="circle_image" src="http://www.acmefood.com/resources/images/back_1.jpg" alt="Products"><br/>
				<p class="underneath_text">Products</p>
			</a>
		</div>
		<?PHP
		if ($_SESSION['current_user'] !== "")
		{
			echo <<<EOT
			<div class="middle_thingy">
				<a href="../user">
					<img class="circle_image" src="http://www1.bellaliant.net/myaccount/demo/img/icon1.png" alt="My Account"><br/>
					<p class="underneath_text">My Account</p>
				</a>
			</div>
EOT;
		}
		?>
		<?php
		if ($_SESSION['admin'] === true)
		{
			echo <<<EOT
			<div class="middle_thingy">
				<a href="../admin">
					<img class="circle_image" src="../images/admin.jpg" alt="My Account"><br/>
					<p class="underneath_text">Admin</p>
				</a>
			</div>
EOT;
		}
		?>
	</div>
	<div id="header_right">
		<a href="/cart/current_cart.php">
			<img src="../images/cart.jpg" alt="Cart">
		</a>
		<p class="underneath_text">Cart</p>
	</div>
</div>