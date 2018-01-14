SELECT substring(reverse(telephone), 1, CHAR_LENGTH(telephone) - 1) AS 'enohpelet' FROM distrib
WHERE telephone regexp '^05';