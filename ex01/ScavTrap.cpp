/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:03:11 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/12 21:52:37 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), isGuardingGate_(false) {
  std::cerr << "ScavTrap default constructor called" << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 20;
  this->maxHitPoints_ = 100;
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name), isGuardingGate_(false) {
  std::cout << "ScavTrap custom constructor called" << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 20;
  this->maxHitPoints_ = 100;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), isGuardingGate_(false) {
  std::cerr << "ScavTrap copy constructor called" << std::endl;
  *this = other;
}

ScavTrap::~ScavTrap() {
  std::cerr << "ScavTrap " << this->name_
            << " has been destroyed and removed from memory" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    this->name_ = other.name_;
    this->hitPoints_ = other.hitPoints_;
    this->energyPoints_ = other.energyPoints_;
    this->attackDamage_ = other.attackDamage_;
    this->maxHitPoints_ = other.maxHitPoints_;
    this->isGuardingGate_ = other.isGuardingGate_;
  }
  return *this;
}

void ScavTrap::printNoHitPointsMsg() const {
  std::cout << "ScavTrap " << this->name_
            << " can't do anything because it has no hit points left"
            << std::endl;
}

void ScavTrap::printNoEnergyPointsMsg() const {
  std::cout << "ScavTrap " << this->name_
            << " can't do anything because it has no energy points left"
            << std::endl;
}

void ScavTrap::printAttackMsg(const std::string &target) const {
  std::cout << "ScavTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
}

bool ScavTrap::checkStatus() {
  if (this->hitPoints_ == 0) {
    printNoHitPointsMsg();
    return false;
  }
  if (this->energyPoints_ == 0) {
    printNoEnergyPointsMsg();
    return false;
  }
  return true;
}

void ScavTrap::attack(const std::string &target) {
  if (!checkStatus())
    return;
  printAttackMsg(target);
  this->energyPoints_--;
}

void ScavTrap::guardGate() {
  if (isGuardingGate_) {
    std::cout << "ScavTrap " << this->name_
              << " has already been in Gate keeper mode" << std::endl;
    return;
  }
  isGuardingGate_ = true;
  std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode"
            << std::endl;
}
