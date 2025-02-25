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

with operator overload I can decide, what happens if I use operators on
objects. For example a and b are not numbers but objects. In the functions
with operator overload, I can do the operation on the attributes of the object
I decide. Or do anything else.

---------------------------------------------------------------------*/
int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	// std::cout << "before Postfix" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
