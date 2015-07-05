// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   main.cpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 21:37:56 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 21:37:57 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>      // std::ifstream, ofstream

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid arguments\n";
		return 0;
	}
	std::string		outfile = std::string(argv[1]) + std::string(".replace");
    std::ifstream	in(argv[1]);
    std::ofstream	out(outfile);
    std::string		wordToReplace(argv[2]);//s1
    std::string		wordToReplaceWith(argv[3]);//s2

    if (!in)
    {
        std::cerr << "Could not open " << argv[1] << "\n";
        return 1;
    }

    if (!out)
    {
        std::cerr << "Could not open " << argv[2] << "\n";
        return 1;
    }

    std::string line;
    size_t len = wordToReplace.length();
    while (std::getline(in, line))
    {
        while (true)
        {
            size_t pos = line.find(wordToReplace);
            if (pos != std::string::npos)
                line.replace(pos, len, wordToReplaceWith);
            else 
                break;
        }
        out << line << '\n';
    }
    in.close();
    out.close();
}
