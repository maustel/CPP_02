/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:28:42 by maustel           #+#    #+#             */
/*   Updated: 2025/02/20 11:28:42 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

/*------------------------------------------------------------------
Copy constructor -> Fixed b( a );
Creates a new object(b) as a copy of an existing one (a)
copies _fp_value from existing class (should copy all non const values)
does not copy _fract_bits because its constant
could be also done like this:
*this = other;
-------------------------------------------------------------------*/
Fixed::Fixed(const Fixed &other): _fp_value(other._fp_value)
{
	std::cout << "Copy constructor called." << std::endl;
}

/*------------------------------------------------------------------
Copy assignment operator
Copies values into an existing object
In case of a = b, in the method (this) refers to left operand (a), while
	the parameter taken is (b).
The return value of the function, as in the function about operator<<,
	is needed only for chaining it with other oprands like a = b = c.
-------------------------------------------------------------------*/
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_fp_value = other._fp_value;
	return (*this);
}

/*------------------------------------------------------------------
returns the raw value of the fixed-point value
-------------------------------------------------------------------*/
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called." << std::endl;
	(void) _fract_bits;
	return (this->_fp_value);
}

/*------------------------------------------------------------------
sets the raw value of the fixed-point number
-------------------------------------------------------------------*/
void Fixed::setRawBits(int const raw )
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_fp_value = raw;
}
