/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:52:09 by maustel           #+#    #+#             */
/*   Updated: 2025/02/20 11:52:09 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*---------------------------------------------------------------------
main function is given from the subject

A fixed-point number is a way to represent decimal numbers using integers by
assuming a fixed number of decimal places. For example, 1.23 can be stored as
the integer 123 with 2 decimal places.
in our case it will be shifted 8 bytes to the left (x * 256)
so we can store also the numbers on the right hand side of the decimal point
to re-transform we do x / 256

Key points about fixed point:
    It's like having a decimal point in a fixed position
    Faster than floating-point numbers because it uses integer arithmetic
    Commonly used in games and digital signal processing
    Limited range and precision compared to floating-point

Since we have a default, int and float constructor, the program chooses
automatically depending on the parameter, which constructor to use

Clean numbers like 10.0 maintain exact precision throughout
Complex numbers like 1234.4321 accumulate small rounding errors
Intermediate values like 42.42 show slight variations due to binary representation limitations
This behavior is normal and expected in fixed-point arithmetic systems, where the trade-off between
precision and integer-based calculations leads to these small rounding effects.
---------------------------------------------------------------------*/
int main()
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "d is " << d.getRawBits() << " as raw bits" << std::endl; //not from subject
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
}
