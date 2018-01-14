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
//   Created: 2015/06/19 14:05:36 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string>
#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;

	Data() {};
	~Data() {};
	Data(Data const & src) { *this = src; }
	Data & operator=(Data const & src) { 
		this->s1 = src.s1;
		this->n = src.n;
		this->s2 = src.s2; 
		return *this;
	};
};

void * serialize(void) 
{
	void *result;
	int i;

	char * serialize_string = new char[18]; //8 + 1 + 8
	//serialize_string.resize(17); // 

	static const char alphanum[] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (i = 0; i < 8; ++i) {
        serialize_string[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    serialize_string[i++] = alphanum[rand() % 10];
    for (i = 9; i < 17; ++i) {
        serialize_string[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    serialize_string[i] = '\0';
    std::cout << "serialized string: " << serialize_string << std::endl;
    result = reinterpret_cast<void*>(serialize_string);
    return result;
}

Data * deserialize( void * raw )
{
	Data * new_data = new Data;
	int i;

	char* unserialized_string;
	unserialized_string = reinterpret_cast<char*>(raw);
	
	new_data->s1.resize(8);
	for (i = 0; i < 8; ++i)
	{
		new_data->s1[i] = unserialized_string[i];
	}
	new_data->s2.resize(8);
	for (i = 9; i < 17; ++i)
	{
		new_data->s2[i - 9] = unserialized_string[i];
	}
	new_data->n = static_cast<int>(unserialized_string[8]);
	
	return new_data;
}

int main()
{
	srand(time(NULL));
	void * raw = serialize();

	std::cout << "Void * raw serialize: " << raw << std::endl;
	Data * data = deserialize(raw);
	std::cout << std::endl << "Void * raw deserialized" << std::endl;
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << " , which is the char: \'" 
		<< (data->n - '0') << "\'" << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
}