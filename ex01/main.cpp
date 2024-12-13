/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:39:31 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 13:29:10 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

static void test1(void) {
  std::cout << "\n=== Test case 1: Basic cases ===" << std::endl;
  ScavTrap apple("Apple");
  apple.attack("Banana");
  apple.takeDamage(5);
  apple.beRepaired(3);
  apple.guardGate();
  apple.guardGate();
}

static void test2(void) {
  std::cout << "\n=== Test case 2: Edge cases ===" << std::endl;
  ScavTrap orange("Orange");
  orange.takeDamage(100);
  orange.takeDamage(1144);
  orange.attack("Banana");
  orange.beRepaired(150);
}

static void test3(void) {
  std::cout << "\n=== Test case 3: Copy and assignment ===" << std::endl;
  ScavTrap pineapple("Pineapple");
  ScavTrap strawberry(pineapple);
  ScavTrap mango("Mango");
  mango = pineapple;
  strawberry.attack("Lemon");
  mango.guardGate();
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
