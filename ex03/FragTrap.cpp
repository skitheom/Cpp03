/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:06:26 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 17:39:32 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap default constructor called" << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 100;
  this->attackDamage_ = 30;
  this->maxHitPoints_ = 100;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "FragTrap custom constructor called" << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 100;
  this->attackDamage_ = 30;
  this->maxHitPoints_ = 100;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = other;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap [" << this->name_ << "] is destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    this->name_ = other.name_;
    this->hitPoints_ = other.hitPoints_;
    this->energyPoints_ = other.energyPoints_;
    this->attackDamage_ = other.attackDamage_;
    this->maxHitPoints_ = other.maxHitPoints_;
  }
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap [" << this->name_;
  if (this->hitPoints_ == 0) {
    std::cout << "] is out of HP and can't give high fives." << std::endl;
    return;
  }
  std::cout << "] says: Hey! Let's do high fives, guys!" << std::endl;
}
