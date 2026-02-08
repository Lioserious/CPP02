/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:33:24 by lihrig            #+#    #+#             */
/*   Updated: 2026/02/08 14:29:42 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main(void)
{
    Fixed       a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a ist " << a << std::endl;
    std::cout << "b ist " << b << std::endl;
    std::cout << "c ist " << c << std::endl;
    std::cout << "d ist " << d << std::endl;

    std::cout << "a ist " << a.toInt() << " als integer" << std::endl;
    std::cout << "b ist " << b.toInt() << " als integer" << std::endl;
    std::cout << "c ist " << c.toInt() << " als integer" << std::endl;
    std::cout << "d ist " << d.toInt() << " als integer" << std::endl;

    return 0;
}