/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:50:45 by lpatin            #+#    #+#             */
/*   Updated: 2026/03/13 13:32:08 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	this->_fpn_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	this->_fpn_value = other._fpn_value;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fpn_value = other._fpn_value;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void){
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpn_value;
}

void Fixed::setRawBits(int const raw){
	this->_fpn_value = raw;
}

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	this->_fpn_value = n << this->_n_frac_bits;
}

Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_fpn_value = roundf(f * (1 << this->_n_frac_bits));
}

float Fixed::toFloat(void) const{
	return (float)this->_fpn_value / (1 << this->_n_frac_bits);
}

int Fixed::toInt(void) const{
	return this->_fpn_value >> this->_n_frac_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}