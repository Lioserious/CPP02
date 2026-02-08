/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:41:08 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/08 15:02:02 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
/**
 * operator>
 * Vergleicht zwei Fixed-Point Zahlen
 * Vergleicht die rohen _value Werte (schneller als toFloat!)
 */
bool Fixed::operator>(const Fixed& rhs) const
{
    return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return this->_value < rhs._value;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->_value <= rhs._value;
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->_value != rhs._value;
}
