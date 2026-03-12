/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:50:43 by lpatin            #+#    #+#             */
/*   Updated: 2026/03/12 17:37:42 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private :
		int _fpn_value;
		static const int _n_frac_bits = 8;

	public :
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		Fixed(const int n);
		Fixed(const float f);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void);
		void setRawBits(int const raw);
		friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};


#endif