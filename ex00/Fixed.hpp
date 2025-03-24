/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:25:05 by maustel           #+#    #+#             */
/*   Updated: 2025/02/20 11:25:05 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed
{
	private:
	int _fp_value;
	const int _fract_bits = 8;

	public:
	//-------------------------------------canonical
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);	//copy constructor
	Fixed& operator=(const Fixed& other);	//copy assignment operator

	//-------------------------------------member functions
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif

