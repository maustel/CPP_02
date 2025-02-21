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

Key points:
    It's like having a decimal point in a fixed position
    Faster than floating-point numbers because it uses integer arithmetic
    Commonly used in games and digital signal processing
    Limited range and precision compared to floating-point
    Works well for specific applications like money calculations where exact precision is needed
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

	std::cout << "d is " << d.getRawBits() << " in raw bits" << std::endl;
}
