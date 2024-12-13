/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:31:37 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 16:14:47 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name_("Default") {
  std::cout << "DiamondTrap default constructor called" << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 30;
  this->maxHitPoints_ = this->hitPoints_;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), name_(name) {
  std::cout << "DiamondTrap custom constructor called" << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 30;
  this->maxHitPoints_ = this->hitPoints_;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), name_(other.name_) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap [" << this->name_ << "] is destroyed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    ScavTrap::operator=(other);
    this->name_ = other.name_;
  }
  return *this;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "WhoAmI() Information:" << std::endl;
  std::cout << "  DiamondTrap name: " << this->name_ << std::endl;
  std::cout << "  ClapTrap    name: " << ClapTrap::name_ << std::endl;

  //   std::cout << "Hit points    : " << this->hitPoints_ << std::endl;
  //   std::cout << "Energy points : " << this->energyPoints_ << std::endl;
  //   std::cout << "Attack damage : " << this->attackDamage_ << std::endl;
  //   std::cout << "Max hit points: " << this->maxHitPoints_ << std::endl;
}
