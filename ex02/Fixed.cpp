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

//--------()()()()()()------ [CONSTRUCTORS AND DESTRUCTOR] ------()()()()()()------

Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Default constructor called." << std::endl;
}

/*-----------------------------------------------------------
Int constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value.
x = floating_input * 2^(fractional_bits)
------------------------------------------------------------*/
Fixed::Fixed(const int nbr)
{
	this->_fp_value = nbr * (1 << this->_fract_bits);
	std::cout << "Int constructor called." << std::endl;
}

/*
constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value.
roundf handles any fractional parts by rounding to the nearest integer value
 */
Fixed::Fixed(const float nbr)
{
	this->_fp_value = roundf(nbr * (1 << this->_fract_bits));
	std::cout << "Float constructor called." << std::endl;
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
*this = other; ->calls copy assignment operator
could be also done like this:
Fixed::Fixed(const Fixed &other): _fp_value(other._fp_value){}
-------------------------------------------------------------------*/
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
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

//--------()()()()()()-------- [MEMBER FUNCTIONS] ---------()()()()()()-------

/*------------------------------------------------------------------
returns the raw value of the fixed-point value
-------------------------------------------------------------------*/
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called." << std::endl;
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

/*------------------------------------------------------------------
converts the fixed-point value to a floating-point value
We take the input value and divide it by (2^fractional_bits)
-------------------------------------------------------------------*/
float Fixed::toFloat() const
{
	return ((float)this->_fp_value / (1 << this->_fract_bits));
}

/*------------------------------------------------------------------
converts the fixed-point value to an integer value
-------------------------------------------------------------------*/
int Fixed::toInt() const
{
	return (this->_fp_value / (1 << this->_fract_bits));
}

//-----()()()()()---- [COMPARISON OPERATOR FUNCTIONS] -----()()()()()-----

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fp_value > rhs._fp_value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fp_value < rhs._fp_value);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fp_value >= rhs._fp_value);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fp_value <= rhs._fp_value);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fp_value == rhs._fp_value);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fp_value != rhs._fp_value);
}

//-----()()()()()---- [ARITHMETIC OPERATOR FUNCTIONS] -----()()()()()-----

Fixed Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

//-----()()()---- [PREFIX INCREMENT / DECREMENT OPERATORS] -----()()()----

/*
The prefix operator returns a reference to the modified object itself. This is
efficient because it doesn't create a temporary copy, and it enables chaining
operations since the result is the modified object.
*/
Fixed& Fixed::operator++(void)
{
	this->_fp_value++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->_fp_value--;
	return (*this);
}

//----()()()---- [POSTFIX INCREMENT / DECREMENT OPERATORS] -----()()()-----

Fixed Fixed::operator++(int)
{
	Fixed tmp (*this);
	this->_fp_value++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp (*this);
	this->_fp_value--;
	return (tmp);
}

//-------()()()()()------- [MIN / MAX FUNCTIONS] --------()()()()()--------

/*
Non-const references (Fixed&) can only bind to non-temporary non-const objects.
Const references (const Fixed&) can bind to anything: const objects, non-const
objects, and temporaries.
static: clearly communicates that max is a utility function rather than an operation on a specific object
It provides the syntax: Fixed::max(a, b)

Static member functions don't have a this pointer because they belong to the class itself, not to any instance
Without an object to protect, the const qualifier has no meaning for static functions
-> static Fixed& min(Fixed& num1, Fixed& num2) const; --> const in the end would not make sense
*/
Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

const Fixed& Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

const Fixed& Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

//-------()()()()()------- [EXTERNAL FUNCTIONS] --------()()()()()--------

/*------------------------------------------------------------------
An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter
------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream &o, const Fixed& obj)
{
	o << obj.toFloat();
	return (o);
}
