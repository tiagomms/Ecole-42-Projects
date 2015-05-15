<?php
	session_start();
	if ($_GET["submit"] === "OK")
	{		
		$_SESSION["login"] = $_GET["login"];
		$_SESSION["passwd"] = $_GET["passwd"];
	}
?>
<html>
	<head>
		<title>Index</title>
	</head>
	<body>
		<form method="GET">
			login: <input type="text" name="login" value=<?php echo '"'.$_SESSION["login"].'"'; ?>><br />
			password: <input type="password" name="passwd" value=<?php echo '"'.$_SESSION["passwd"].'"'; ?>><br />
			<input type="submit" name="submit" value="OK">
		</form>
	</body>
</html>