<?php
	if ($_POST["submit"] === "OK" && $_POST['login'] !== "" && $_POST['newpw'] !== "" && $_POST['login'] !== NULL && $_POST['newpw'] !== NULL)
	{
		#if does not directory exists or file does not exist
		if (file_exists("../private") == FALSE || file_exists("../private/passwd") == FALSE)
		{
			echo "ERROR\n";
			exit(1);
		}	

		#get content from the file
		$content_from_file = file_get_contents("../private/passwd");
		
		#unserialize
		$unserial_database = unserialize($content_from_file);
		$login_found = 0;
		$hash_oldpw = hash('whirlpool', $_POST['oldpw']);
		$hash_newpw = hash('whirlpool', $_POST['newpw']);		
		$_POST['oldpw'] = ""; #delete oldpw string
		$_POST['newpw'] = ""; #delete newpw string
		foreach ($unserial_database as &$data) {
					if ($data['login'] === $_POST['login']) 
					{
						$login_found = 1;
						if ($data['passwd'] === $hash_oldpw)
						{
							$data['passwd'] = $hash_newpw;					
							break ;
						}
						else
						{
							echo "ERROR\n";
							exit(1);
						}
					}
				}
		if ($login_found == 0)
		{
			echo "ERROR\n";
			exit(1);
		}
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