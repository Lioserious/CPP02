/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:33:29 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/19 12:13:32 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/**
 * Default Constructor
 * 
 * Erstellt ein neues Fixed-Objekt und initialisiert _value mit 0.
 * 
 * Wird aufgerufen bei:
 *   - Fixed a;
 *   - Fixed b = Fixed();
 * 
 * Initialisierungsliste `: _value(0)` setzt den Wert auf 0 BEVOR
 * der Funktionskörper ausgeführt wird.
 * 
 * Ausgabe: "Default constructor call"
 */
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor call" << std::endl;
}


/**
 * Copy Constructor
 * 
 * Erstellt ein NEUES Objekt als Kopie eines existierenden Objekts.
 * 
 * Wird aufgerufen bei:
 *   - Fixed b(a);
 *   - Fixed c = a;
 *   - Funktionsaufruf by value: func(Fixed f)
 * 
 * Parameter:
 *   @param other - Referenz auf das zu kopierende Objekt (const = wird nicht verändert)
 * 
 * Implementierung:
 *   - Nutzt den Assignment Operator (*this = other) um Code-Duplikation zu vermeiden
 *   - *this = das neue Objekt selbst
 *   - this = Pointer/Adresse des neuen Objekts
 * 
 * Ausgabe: "Copy constructor call"
 */
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor call" << std::endl;
    *this = other;
}

/**
 * Copy Assignment Operator
 * 
 * Überschreibt ein BEREITS EXISTIERENDES Objekt mit Werten eines anderen.
 * Unterschied zum Copy Constructor: Das Zielobjekt existiert bereits!
 * 
 * Wird aufgerufen bei:
 *   - b = a;  (b existiert schon)
 *   - a = b = c;  (Kettenzuweisung)
 * 
 * Parameter:
 *   @param other - Referenz auf das Quellobjekt (const = wird nicht verändert)
 * 
 * Rückgabe:
 *   @return Fixed& - Referenz auf sich selbst für Kettenzuweisung (a = b = c)
 * 
 * Implementierung:
 *   - Selbstzuweisungsprüfung: if (this != &other)
 *     * this = meine Adresse
 *     * &other = Adresse von other
 *     * Verhindert Probleme bei: a = a;
 *   - Kopiert _value mittels getStoredValue()
 *   - return *this = gibt Referenz auf sich selbst zurück
 * 
 * Ausgabe: "Copy assignment operator call"
 */
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator call" << std::endl;
    if (this != &other)
    {
        this->_value = other.getRawBits();
    }
    return *this;
}

/**
 * Destructor
 * 
 * Wird AUTOMATISCH aufgerufen wenn ein Objekt "stirbt".
 * Verantwortlich für Aufräumarbeiten (Speicher freigeben, Dateien schließen, etc.)
 * 
 * Wird aufgerufen bei:
 *   - Verlassen des Scopes: { Fixed a; } ← hier am Ende
 *   - delete ptr; (bei dynamisch allokierten Objekten)
 *   - Ende von main()
 * 
 * Reihenfolge:
 *   - Destruktoren werden in UMGEKEHRTER Reihenfolge der Erstellung aufgerufen
 *   - Erstellt: a, b, c → Zerstört: c, b, a
 * 
 * Hier: Keine Aufräumarbeiten nötig (kein dynamischer Speicher),
 *       nur Debug-Ausgabe.
 * 
 * Ausgabe: "Destructor call"
 */
Fixed::~Fixed()
{
    std::cout << "Destructor call" << std::endl;
}
/**
 * getStoredValue - Getter Funktion
 * 
 * Gibt den intern gespeicherten Fixed-Point Wert zurück (nur lesen, nicht ändern).
 * 
 * Wird aufgerufen bei:
 *   - int x = a.getStoredValue();
 *   - std::cout << a.getStoredValue();
 *   - other._value = a.getStoredValue();
 * 
 * Rückgabe:
 *   @return int - Der gespeicherte Wert von _value
 * 
 * const-Qualifikation:
 *   - `const` am Ende bedeutet: Diese Funktion ändert das Objekt NICHT
 *   - Ermöglicht Aufruf auf const-Objekten: const Fixed a; a.getStoredValue();
 *   - Best Practice: Alle Getter sollten const sein
 * 
 * this->:
 *   - `this` = Pointer auf das aktuelle Objekt
 *   - `this->_value` = Zugriff auf Member (kann auch nur `_value` schreiben)
 * 
 * Ausgabe: "getStoredValue member function call"
 */
int Fixed::getRawBits(void) const
{
    std::cout << "getStoredValue member function call" << std::endl;
    return this->_value;
}
/**
 * setStoredValue - Setter Funktion
 * 
 * Setzt den intern gespeicherten Fixed-Point Wert auf einen neuen Wert.
 * 
 * Wird aufgerufen bei:
 *   - a.setStoredValue(42);
 *   - a.setStoredValue(b.getStoredValue());
 * 
 * Parameter:
 *   @param raw - Der neue Wert (int const = kann nicht verändert werden)
 * 
 * Rückgabe:
 *   - void = gibt nichts zurück
 * 
 * NICHT const:
 *   - Diese Funktion ÄNDERT das Objekt (_value wird überschrieben)
 *   - Daher KEIN `const` am Ende
 *   - Kann NICHT auf const-Objekten aufgerufen werden
 * 
 * this->:
 *   - `this->_value` = Mein eigenes Member
 *   - `raw` = Der übergebene Parameter
 * 
 * Keine Ausgabe (nur Wert setzen)
 */
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}