<?php
	if ($_POST["submit"] === "OK" && $_POST['login'] !== "" && $_POST['passwd'] !== "" && $_POST['login'] !== NULL && $_POST['passwd'] !== NULL)
	{
		#if does not directory exists
		if (file_exists("../private") == FALSE)
			mkdir("../private/", 0777); 
		
		#if file does not exist
		if (file_exists("../private/passwd") == FALSE)
			file_put_contents("../private/passwd", "");

		#get content from the file
		$content_from_file = file_get_contents("../private/passwd");
		
		#unserialize
		$unserial_database = unserialize($content_from_file);
		foreach ($unserial_database as $data) {
					if ($data['login'] === $_POST['login']) {
						echo "ERROR\n";
						exit(1);
					}
				}		
		
		$new_content['login'] = $_POST['login'];
		$new_content['passwd'] = hash('whirlpool', $_POST['passwd']);
		$_POST['passwd'] = ""; #delete
		#add new data to unserialized stuff. It works a like a malloc of an entire new line below the other one
		$unserial_database[] = $new_content; 
		$new_serial_database = serialize($unserial_database);

		#SERIALIZE EVERYTHING AGAIN, OTHERWISE YOU ARE FUCKED SIR
		file_put_contents("../private/passwd", $new_serial_database);	
		echo "OK\n";			
		exit(0);
	}
	else
	{
		echo "ERROR\n";
		exit(1);
	}
?>