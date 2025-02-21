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
#include <cmath>

class Fixed
{
	private:
	int _fp_value;
	const int _fract_bits = 8;

	public:
	Fixed();
	~Fixed();
	Fixed(const int val);	//int constructor
	Fixed(const float nbr);
	Fixed(const Fixed& other);	//copy constructor
	Fixed& operator=(const Fixed& other);	//copy assignment operator
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &o, const Fixed& nbr);

#endif

