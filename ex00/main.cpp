/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:39:31 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/12 21:32:38 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

static void test1(void) {
  std::cout << "\n=== Test case 1: Basic operations ===" << std::endl;
  ClapTrap apple("Apple");
  apple.attack("Banana");
  apple.takeDamage(5);
  apple.beRepaired(3);
}

static void test2(void) {
  std::cout << "\n=== Test case 2: Edge cases ===" << std::endl;
  ClapTrap orange("Orange");
  orange.takeDamage(20);
  orange.attack("Banana");
  orange.beRepaired(10);
  orange.takeDamage(20);
}

static void test3(void) {
  std::cout << "\n=== Test case 3: Copy and assignment ===" << std::endl;
  ClapTrap pineapple("Pineapple");
  ClapTrap strawberry(pineapple);
  ClapTrap mango("Mango");
  mango = pineapple;
  strawberry.attack("Lemon");
  mango.beRepaired(5);
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
