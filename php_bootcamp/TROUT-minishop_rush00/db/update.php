<?PHP
include("../php_assets/return_to.php");

file_put_contents("../db/products.csv", $_POST['content']);
set_return_to("/admin");
error_log("trying to go back now");
return_to("updated database");

?>