// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   MutantStack.hpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:36 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*

Then you will write a program that does the following :

• Open a file that contains Mindopen code

• Read this file, and for each instruction deciphered, create an Instruction derived
object that represents the actual instruction to run, and queue it in a ... well, a
queue of instructions in memory

• Close the file

• Execute each instruction in queue

In case it isn’t obvious, this means you must also create a set of Instruction classes,
one for each actual instruction in the language, that all have a method like execute
or something, that will execute the actual instruction. You will also probably need an
interface to manipulate all those instructions and store them all in the same container ...
A thorough and detailed main function will be expected, as well as some test files that
are actual Mindopen programs to use.


Character	Meaning
>	increment the data pointer (to point to the next cell to the right).

<	decrement the data pointer (to point to the next cell to the left).

+	increment (increase by one) the byte at the data pointer.

-	decrement (decrease by one) the byte at the data pointer.

.	output the byte at the data pointer.

,	accept one byte of input, storing its value in the byte at the data pointer.

[	if the byte at the data pointer is zero, then instead of moving the instruction 
	pointer forward to the next command, jump it forward to the command after the 
	matching ] command.

]	if the byte at the data pointer is nonzero, then instead of moving the instruction 
	pointer forward to the next command, jump it back to the command after the 
	matching [ command.

brainfuck command	C equivalent
(Program Start)		char array[infinitely large size] = {0};
					char *ptr=array;
>					++ptr;
<					--ptr;
+					++*ptr;
-					--*ptr;
.					putchar(*ptr);
,					*ptr=getchar();
[					while (*ptr) {
]					}

*/

#include "IMindOpen.hpp"
#include "BeginLoop.hpp"
#include "EndLoop.hpp"
#include "Decrement.hpp"
#include "Increment.hpp"
#include "PtrBackward.hpp"
#include "PtrForward.hpp"
#include "ReadChar.hpp"
#include "WriteChar.hpp"


int main (int argc, char **argv) 
{
	if (argc == 2)
	{
		std::ifstream ifs (argv[1], std::ifstream::in);
		if (ifs.fail())
		{
			std::cerr << "Invalid or Null file\n";
			return 0;
		}

		std::deque<IMindOpen*> deque;
		char c = ifs.get();
		while (ifs.good()) 
		{
			switch (c)
			{
				case '+':
				{
					Increment * inc = new Increment;
					deque.push_back(inc);
					break;
				}
				case '-':
				{
					Decrement * dec = new Decrement;
					deque.push_back(dec);
					break;
				}
				case '>':
				{
					PtrForward * ptr = new PtrForward;
					deque.push_back(ptr);
					break;
				}
				case '<':
				{
					PtrBackward * ptr = new PtrBackward;
					deque.push_back(ptr);
					break;
				}
				case '[':
				{
					BeginLoop * bloop = new BeginLoop;
					deque.push_back(bloop);
					break;
				}
				case ']':
				{
					EndLoop * eloop = new EndLoop;
					deque.push_back(eloop);
					break;
				}
				case '.':
				{
					WriteChar * wrtc = new WriteChar;
					deque.push_back(wrtc);
					break;
				}
				case ',':
				{
					ReadChar * rdc = new ReadChar;
					deque.push_back(rdc);
					break;
				}
				default:
					break;																								
			}	
			c = ifs.get();
		}
		ifs.close();

		char *array= new char[30000];
		for (int i = 0; i < 30000; i++)
			array[i] = 0;

		bool in_parenthesis = false;
		bool temp;
		std::deque<IMindOpen*>::iterator it = deque.begin();
		//int i = 0;
		while (it != deque.end())
		{
			temp = in_parenthesis;
			in_parenthesis = (*it)->execute(temp, &array, &deque, &it);
			//std::cout << i++ << " , *array : " << (int)*array <<  std::endl;
			if (deque.empty())
				it = deque.end();
		}
	}
	else
		std::cerr << "Please introduce at least/only a filename\n";
	return 0;
}


