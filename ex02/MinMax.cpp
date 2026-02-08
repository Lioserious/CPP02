/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MinMax.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:05:39 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/08 15:06:14 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/**
 * min - Non-const Version
 * Gibt Referenz auf das kleinere Objekt zurück
 * Kann modifiziert werden!
 */
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

/**
 * min - Const Version
 * Für const Objekte
 * Kann NICHT modifiziert werden
 */
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

/**
 * max - Non-const Version
 */
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

/**
 * max - Const Version
 */
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}