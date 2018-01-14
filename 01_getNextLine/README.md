# get next line

**Retrieve next line from a file (either EOF is reached or \n)**

To make it work:
- use Makefile to make libft and obtain its library
- Compile get_next_line.c 
- Write a main.c with the get_next_line function within a loop to read the lines of a file one by one
- get_next_line returns an int: 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -1 --> case of error with the file descriptor or read;

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 0 --> when the file is over from being read (the EOF was reached)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1 --> when a line is read
