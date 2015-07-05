// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Array.tpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:44 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <exception>

template< typename T>
class Array
{
public:
	Array<T>() : _size(0), _array(NULL)
	{
	return;
	}	 // Canonical
	
	Array<T>(unsigned int n) : _size(n)
	{
		this->_array = new T[n];
		return;
	}// Canonical
	
	Array<T>(Array<T> const & src) //Canonical
	{
		this->_array = new T[src._size]; 
		*this = src;
		return;
	}
	
	Array<T> & operator=(Array<T> const & src) // Canonical
	{
		unsigned int i;

		i = 0;
		while (i < src._size)
		{
			if (i >= this->_size)
				throw Array<T>::OutOfBounds();
			else
				this->_array[i] = src._array[i];
			i++;
		}
		return *this;
	}

	~Array<T>()
	{
		if (this->_array)
			delete [] this->_array;
	}

	T & operator[](unsigned int index)
	{
		if (index >= this->_size)
			throw Array<T>::OutOfBounds();
		return this->_array[index];
	}

	class	OutOfBounds : public std::exception
	{
	
	public:
		virtual const char * what() const throw()
		{
			return "Out of bounds for this array Index ";
		}
		
		virtual ~OutOfBounds() throw() //Canonical
		{
			return;
		}

		OutOfBounds(OutOfBounds const & src) //Canonical
		{
			*this = src;
		}
		
		OutOfBounds & operator=(OutOfBounds const & src) //Canonical
		{
			*this = src;
			return *this;
		}
		
		OutOfBounds() //Canonical
		{
			return;
		}

	private:

	};	

private:
	const unsigned int _size;
	T * _array;

};

template< typename T>
std::ostream & operator<<(std::ostream & o, T & element)
{
	o << element;
	return o;
}

#endif