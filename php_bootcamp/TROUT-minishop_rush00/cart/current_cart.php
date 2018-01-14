<?PHP
include("../php_assets/exit_to.php");
include("../php_assets/return_to.php");
include("../php_assets/get_database.php");

session_start();

$product_database = get_database();

?>

<html>
<head>
	<title>Cart</title>
	<link rel="stylesheet" type="text/css" href="cart.css">
	<link rel="stylesheet" type="text/css" href="../header.css">
</head>
<body>
	<?php include("../header.php"); ?>
	<div style="margin-left: auto; margin-right: auto; max-width: 1280px; min-width:840px;">
		<h1>Here are the items in your cart:</h1>
		<!--Name, price, quantity, total-->
		<?PHP
		if (count($_SESSION['cart']) > 0)
		{
			echo <<<EOT
			<table>
				<tr class="title">
					<td>Name</td>
					<td>Price</td>
					<td>Quantity</td>
					<td>Total</td>
				</tr>
EOT;
			$super_total = 0;
			foreach($_SESSION['cart'] as $key => $value)
			{
				$quantity = $value;
				$price = $product_database[$key]['price'];
				$total_price = $quantity * $price;
				echo <<<EOT
				<tr>
					<td>$key</td>
					<td>$price</td>
					<td>$quantity</td>
					<td>$total_price</td>
				</tr>
EOT;
				$super_total += $total_price;
			}
				echo <<<EOT
				<tr>
					<td></td>
					<td></td>
					<td class="title">Super total:</td>
					<td class="title">$super_total</td>
				</tr>
			</table>
EOT;
			if (isset($_SESSION['current_user']) && $_SESSION['current_user'] !== "")
			{
				echo '<a href="../user/archive_cart.php">Validate cart</a>';
			}
			else
			{
				echo "Please login to validate your cart.";
			}
		}
		else
		{
			echo <<<EOT
			There are no items in your cart. Try out our newest trout-related product: Arnault Tzanck!
EOT;
	}
	?>
</div>
</body>
</html>
