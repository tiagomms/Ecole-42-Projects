<?PHP

include("../php_assets/get_database.php");

function find_unique_tags($product_database)
{
	$all_tags = array();
	foreach ($product_database as $product)
	{
		$all_tags = array_merge($all_tags, $product['tags']);
	}
	return array_unique($all_tags);
}

$product_database = get_database();

?>

<html>
<head>
	<title>Products</title>
	<link rel="stylesheet" type="text/css" href="products.css"></head>
	<link rel="stylesheet" type="text/css" href="../header.css">
<body>

	<?php include("../header.php"); ?>
	<div style="margin-left: auto; margin-right: auto; max-width: 1280px;">
		<div id="topbox">
		<ul>
			<a href="index.php"><li>all</li></a>'
			<?PHP
				$unique_tags = find_unique_tags($product_database);
				foreach ($unique_tags as $tag)
				{
					$encoded_tag = urlencode($tag);
					echo <<<EOT
<a href="index.php?tag=$encoded_tag">
	<li>$tag</li>
</a>
EOT;
				}
			?>
		</ul>
		</div>
		<div id="products_display">
		<?PHP

			foreach($product_database as $name => $info)
			{
				$image_url = $info['image_url'];
				$description = $info['description'];
				$price = $info['price'];
				$tags = $info['tags'];
				if (!isset($_GET['tag']) || in_array($_GET['tag'], $tags))
				{
					echo <<<EOT
<div class="food_item">
	<br />
	<div class="food_image">
	<img src="$image_url">
	</div>
	<div class="food_info">
		<strong>$name</strong>
		<p>$description</p>
	</div>
	<div>
		<form method="post" action="../user/add_to_cart.php">
			<input type="hidden" name="product" value="$name"/>
			<input id="submit_button" type="submit" name="submit" value="Add To Cart" />
		</form>
		<p id="price">Price: $$price</p>
	</div>
</div>
EOT;
					}
				}
			?>
		</div>
	</div>
</body>
</html>