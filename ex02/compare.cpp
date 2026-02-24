/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:41:08 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/23 18:39:52 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
/**
 * operator>
 * Vergleicht zwei Fixed-Point Zahlen
 * Vergleicht die rohen _value Werte
 */
bool Fixed::operator>(const Fixed& right) const
{
    return this->_value > right._value;
}

bool Fixed::operator<(const Fixed& right) const
{
    return this->_value < right._value;
}

bool Fixed::operator>=(const Fixed& right) const
{
    return this->_value >= right._value;
}

bool Fixed::operator<=(const Fixed& right) const
{
    return this->_value <= right._value;
}

bool Fixed::operator==(const Fixed& right) const
{
    return this->_value == right._value;
}

bool Fixed::operator!=(const Fixed& right) const
{
    return this->_value != right._value;
}
