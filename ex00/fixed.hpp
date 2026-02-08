#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
     // Default Constructor
    Fixed();
    // Copy Constructor
    Fixed(const Fixed& other);
    // Copy Assignment Operator Ueberschreibt bestehndes object
    Fixed& operator=(const Fixed& other);
    // Destructor
    ~Fixed();

    // Member functions
    int     getStoredValue(void) const;
    void    setStoredValue(int const raw);
};

#endif