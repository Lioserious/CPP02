/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementDecrement.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:43:03 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/08 15:11:35 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/**
 * Pre-Increment (++a)
 * 1. Erhöhe Wert um ε (kleinste darstellbare Zahl = 1)
 * 2. Gib Referenz zurück
 * 
 * ε = 1 im Raw-Format = 1/256 als Float = 0.00390625
 */
Fixed& Fixed::operator++(void)
{
    this->_value++;
    return *this;
}

/**
 * Post-Increment (a++)
 * 1. Speichere alten Wert
 * 2. Erhöhe Wert um ε
 * 3. Gib alten Wert zurück
 * 
 * Dummy Parameter 'int' unterscheidet Pre von Post!
 */
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value++;
    return temp;
}

/**
 * Pre-Decrement (--a)
 */
Fixed& Fixed::operator--(void)
{
    this->_value--;
    return *this;
}

/**
 * Post-Decrement (a--)
 */
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value--;
    return temp;
}