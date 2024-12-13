/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:39:31 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 14:23:00 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main() {
  FragTrap frag("Fraggy");

  std::cout << "=== Test High Fives ===" << std::endl;
  frag.highFivesGuys();

  return 0;
}
