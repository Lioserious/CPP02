#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Konvertierungs-Constructors
    Fixed(const int n);
    Fixed(const float f);

    // Getter/Setter
    int     getStoredValue(void) const;
    void    setStoredValue(int const raw);

    // Konvertierungsf.
    float   toFloat(void) const;
    int     toInt(void) const;
};
// Operator Overload (außerhalb der Klasse!)
std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
