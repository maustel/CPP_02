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

---------------------------------------------------------------------*/
int main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;

}
