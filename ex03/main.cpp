/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:39:31 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 16:21:54 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

void testDefaultConstructor() {
  std::cout << "\n=== Test case 1: Default constructor ===" << std::endl;
  DiamondTrap d;
  d.whoAmI();
  d.attack("enemy");
}

void testNameConstructor() {
  std::cout << "\n=== Test case 2: Name constructor ===" << std::endl;
  DiamondTrap d("GreenTea");
  d.whoAmI();
  d.attack("target");
}

void testCopyConstructorAndAssignment() {
  std::cout << "\n=== Test case 3: Copy and assignment ===" << std::endl;
  DiamondTrap d1("BlueBerry");
  d1.attack("enemy");
  DiamondTrap d2(d1);
  d2.whoAmI();

  DiamondTrap d3("Mango");
  d3 = d1;
  d3.whoAmI();
  d3.guardGate();
  d3.guardGate();
  d3.highFivesGuys();
}

int main() {
  testDefaultConstructor();
  testNameConstructor();
  testCopyConstructorAndAssignment();
  return 0;
}
