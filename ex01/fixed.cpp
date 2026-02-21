/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:33:29 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/21 16:59:32 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/**
 * Default Constructor
 * Initialisiert _value mit 0
 */
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor call" << std::endl;
}

/**
 * Copy Constructor
 * Erstellt eine Kopie eines existierenden Objekts
 */
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor call" << std::endl;
    *this = other;
}

/**
 * Copy Assignment Operator
 * Überschreibt ein existierendes Objekt
 */
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator call" << std::endl;
    if (this != &other)
    {
        this->_value = other.getStoredValue();
    }
    return *this;
}

/**
 * Destructor
 * Räumt auf beim Zerstören des Objekts
 */
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/**
 * Int Constructor - 
 * 
 * Konvertiert int zu Fixed-Point
 * Formel: fixed = int × 2^8
 * 
 * Beispiel: Fixed(42)
 *   → _value = 42 << 8 = 42 × 256 = 10752
 */
Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = n << this->_fractionalBits;
}

/**
 * Float Constructor - 
 * 
 * Konvertiert float zu Fixed-Point
 * Formel: fixed = roundf(float × 2^8)
 * 
 * Beispiel: Fixed(42.42f)
 *   → _value = roundf(42.42 × 256) = roundf(10859.52) = 10860
 */
Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(f * (1 << this->_fractionalBits));
}

/**
 * getStoredValue
 * Gibt den rohen Fixed-Point Wert zurück
 */
int Fixed::getStoredValue(void) const
{
    return this->_value;
}

/**
 * setStoredValue
 * Setzt den rohen Fixed-Point Wert
 */
void Fixed::setStoredValue(int const raw)
{
    this->_value = raw;
}

/**
 * toFloat - 
 * 
 * Konvertiert Fixed-Point zu float
 * Formel: float = fixed / 2^8
 * 
 * Beispiel: _value = 10860
 *   → return 10860 / 256.0 = 42.421875
 */
float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << this->_fractionalBits);
}

/**
 * toInt - 
 * 
 * Konvertiert Fixed-Point zu int
 * Formel: int = fixed / 2^8 (Nachkommastellen abgeschnitten)
 * 
 * Beispiel: _value = 10860
 *   → return 10860 >> 8 = 42
 */
int Fixed::toInt(void) const
{
    return this->_value >> this->_fractionalBits;
}

/**
 * operator<< - 
 * 
 * Ermöglicht: std::cout << fixed_object
 * 
 * Gibt den Fixed-Point Wert als Float aus
 * 
 * Beispiel: Fixed a(42.42f);
 *           std::cout << a;  // Ausgabe: 42.4219
 */
std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}

