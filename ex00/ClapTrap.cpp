/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:55:06 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 13:37:33 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name_("Default"), hitPoints_(10), energyPoints_(10), attackDamage_(0),
      maxHitPoints_(10) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0),
      maxHitPoints_(10) {
  std::cout << "ClapTrap custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name_(other.name_), hitPoints_(other.hitPoints_),
      energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_),
      maxHitPoints_(other.maxHitPoints_) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap [" << this->name_ << "] is destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "CrapTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    this->name_ = other.name_;
    this->hitPoints_ = other.hitPoints_;
    this->energyPoints_ = other.energyPoints_;
    this->attackDamage_ = other.attackDamage_;
    this->maxHitPoints_ = other.maxHitPoints_;
  }
  return *this;
}

void ClapTrap::printName() const {
  std::cout << "ClapTrap [" << this->name_ << "]";
}

void ClapTrap::printNoHitPointsMsg() const {
  printName();
  std::cout << " can't do anything because it has no hit points left"
            << std::endl;
}

void ClapTrap::printNoEnergyPointsMsg() const {
  printName();
  std::cout << " can't do anything because it has no energy points left"
            << std::endl;
}

void ClapTrap::printAttackMsg(const std::string &target) const {
  printName();
  std::cout << " attacks " << target << ", causing " << this->attackDamage_
            << " points of damage!" << std::endl;
}

void ClapTrap::printAlreadyDeadMsg() const {
  printName();
  std::cout << " has been incapacitated (HP: 0)" << std::endl;
}

void ClapTrap::printDeathMsg(unsigned int amount) const {
  printName();
  std::cout << " is incapacitated after taking " << amount
            << " points of damage" << std::endl;
}

void ClapTrap::printTakeDamageMsg(unsigned int amount) const {
  printName();
  std::cout << " takes " << amount << " points of damage" << std::endl;
}

void ClapTrap::printHitPointsAlreadyFullMsg() const {
  printName();
  std::cout << " already has full hit points" << std::endl;
}

void ClapTrap::printBeRepairedMsg(unsigned int amount) const {
  printName();
  std::cout << " repairs itself, restoring " << amount << " hit points"
            << std::endl;
}

bool ClapTrap::checkStatus() {
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

void ClapTrap::attack(const std::string &target) {
  if (!checkStatus())
    return;
  printAttackMsg(target);
  this->energyPoints_--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints_ == 0) {
    printAlreadyDeadMsg();
    return;
  }
  if (this->hitPoints_ <= amount) {
    printDeathMsg(amount);
    this->hitPoints_ = 0;
    return;
  }
  printTakeDamageMsg(amount);
  this->hitPoints_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!checkStatus())
    return;
  if (this->hitPoints_ == this->maxHitPoints_) {
    printHitPointsAlreadyFullMsg();
    return;
  }
  amount = std::min(amount, this->maxHitPoints_ - this->hitPoints_);
  printBeRepairedMsg(amount);
  this->hitPoints_ += amount;
  this->energyPoints_--;
}
