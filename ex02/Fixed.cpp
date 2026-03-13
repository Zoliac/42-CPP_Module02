/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:50:45 by lpatin            #+#    #+#             */
/*   Updated: 2026/03/13 14:44:26 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors and destructor stuff

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

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	this->_fpn_value = n << this->_n_frac_bits;
}

Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_fpn_value = roundf(f * (1 << this->_n_frac_bits));
}

//Getters and setters

int Fixed::getRawBits(void){
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpn_value;
}

void Fixed::setRawBits(int const raw){
	this->_fpn_value = raw;
}

//Member functions

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

//Comparaisons

bool Fixed::operator>(const Fixed& other) const{
	return this->_fpn_value > other._fpn_value;
}

bool Fixed::operator<(const Fixed& other) const{
	return this->_fpn_value < other._fpn_value;
}

bool Fixed::operator>=(const Fixed& other) const{
	return this->_fpn_value >= other._fpn_value;
}

bool Fixed::operator<=(const Fixed& other) const{
	return this->_fpn_value <= other._fpn_value;
}

bool Fixed::operator==(const Fixed& other) const{
	return this->_fpn_value == other._fpn_value;
}

bool Fixed::operator!=(const Fixed& other) const{
	return this->_fpn_value != other._fpn_value;
}

//Arithmetique

Fixed Fixed::operator+(const Fixed& other) const{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const{
	return (this->toFloat() / other.toFloat());
}

// Increments
		
Fixed& Fixed::operator++(){
	this->_fpn_value++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	this->_fpn_value++;
	return tmp;
}

Fixed& Fixed::operator--(){
	this->_fpn_value--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	this->_fpn_value--;
	return tmp;
}

//Min/Max

Fixed& Fixed::min(Fixed& a, Fixed& b){
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b) ? a : b;
}
