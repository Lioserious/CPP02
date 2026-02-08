/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:33:24 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/08 13:38:14 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main(void)
{
    Fixed a;              // Default Constructor
    Fixed b(a);           // Copy Constructor
    Fixed c;              // Default Constructor
    
    c = b;                // Copy Assignment Operator
    
    std::cout << a.getStoredValue() << std::endl;
    std::cout << b.getStoredValue() << std::endl;
    std::cout << c.getStoredValue() << std::endl;
    
    return 0;
}