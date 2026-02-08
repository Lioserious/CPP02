/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetics.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:41:24 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/08 15:15:20 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
/**
 * operator+
 * Addiert zwei Fixed-Point Zahlen
 * Erstellt ein NEUES Objekt mit dem Ergebnis
 */
Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;
    result.setStoredValue(this->_value + rhs._value);
    return result;
}

/**
 * operator-
 * Subtrahiert zwei Fixed-Point Zahlen
 */
Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;
    result.setStoredValue(this->_value - rhs._value);
    return result;
}

/**
 * operator*
 * Multipliziert zwei Fixed-Point Zahlen
 * 
 * WICHTIG: Beide Zahlen sind mit 2^8 skaliert!
 * a × b = (a_raw × b_raw) / 2^8
 * 
 * Beispiel: 2 × 3 = 6
 *   a_raw = 2 × 256 = 512
 *   b_raw = 3 × 256 = 768
 *   512 × 768 = 393216
 *   393216 / 256 = 1536 = 6 × 256 ✓
 */
Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    long temp = (long)this->_value * (long)rhs._value;
    result.setStoredValue(temp >> this->_fractionalBits);
    return result;
}

/**
 * operator/
 * Dividiert zwei Fixed-Point Zahlen
 * 
 * WICHTIG: Müssen erst skalieren!
 * a / b = (a_raw × 2^8) / b_raw
 * 
 * Beispiel: 6 / 2 = 3
 *   a_raw = 6 × 256 = 1536
 *   b_raw = 2 × 256 = 512
 *   (1536 × 256) / 512 = 768 = 3 × 256 ✓
 */
Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed result;
    long temp = ((long)this->_value << this->_fractionalBits);
    result.setStoredValue(temp / rhs._value);
    return result;
}