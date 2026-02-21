#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
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

    // Konvertierungsf.
    float   toFloat(void) const;
    int     toInt(void) const;

    // Getter/Setter
    int     getStoredValue(void) const;
    void    setStoredValue(int const raw);

    //Vergleichsoperatoren
    bool    operator>(const Fixed& rhs) const;
    bool    operator<(const Fixed& rhs) const;
    bool    operator>=(const Fixed& rhs) const;
    bool    operator<=(const Fixed& rhs) const;
    bool    operator==(const Fixed& rhs) const;
    bool    operator!=(const Fixed& rhs) const;

    //Arithmetische Operatoren
    Fixed   operator+(const Fixed& rhs) const;
    Fixed   operator-(const Fixed& rhs) const;
    Fixed   operator*(const Fixed& rhs) const;
    Fixed   operator/(const Fixed& rhs) const;

    //  Inkrement/Dekrement
    Fixed&  operator++(void);           // (++a)
    Fixed   operator++(int);            // (a++)
    Fixed&  operator--(void);           // (--a)
    Fixed   operator--(int);            // (a--)

    //Statische Min/Max Funktionen
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};
// Stream Operator
std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
