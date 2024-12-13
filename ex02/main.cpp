/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:39:31 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 17:33:55 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

static void test1(void) {
  std::cout << "\n=== Test case 1: Basic cases ===" << std::endl;
  FragTrap apple("Apple");
  apple.attack("Banana");
  apple.takeDamage(5);
  apple.beRepaired(3);
  apple.highFivesGuys();
}

static void test2(void) {
  std::cout << "\n=== Test case 2: Edge cases ===" << std::endl;
  FragTrap orange("Orange");
  orange.takeDamage(100);
  orange.takeDamage(1144);
  orange.attack("Banana");
  orange.beRepaired(150);
  orange.highFivesGuys();
}

static void test3(void) {
  std::cout << "\n=== Test case 3: Copy and assignment ===" << std::endl;
  FragTrap pineapple("Pineapple");
  FragTrap strawberry(pineapple);
  FragTrap mango("Mango");
  mango = pineapple;
  strawberry.attack("Lemon");
  mango.highFivesGuys();
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
