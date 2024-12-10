/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:55:06 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/11 01:39:16 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name_("Default"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << "ClapTrap custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name_(other.name_), hitPoints_(other.hitPoints_),
      energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name_ << " is destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "CrapTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    this->name_ = other.name_;
    this->hitPoints_ = other.hitPoints_;
    this->energyPoints_ = other.energyPoints_;
    this->attackDamage_ = other.attackDamage_;
  }
  return *this;
}

bool ClapTrap::checkStatus() {
  if (this->hitPoints_ == 0) {
    std::cout << "ClapTrap " << this->name_
              << " can't do anything because it has no hit points left"
              << std::endl;
    return false;
  }
  if (this->energyPoints_ == 0) {
    std::cout << "ClapTrap " << this->name_
              << " can't do anything because it has no energy points left"
              << std::endl;
    return false;
  }
  return true;
}

void ClapTrap::attack(const std::string &target) {
  if (!checkStatus())
    return;
  std::cout << "ClapTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
  this->energyPoints_--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << this->name_;
  if (this->hitPoints_ == 0) {
    std::cout << " has already been destroyed" << std::endl;
    return;
  }
  if (this->hitPoints_ <= amount) {
    std::cout << " is destroyed after taking " << amount << " points of damage"
              << std::endl;
    this->hitPoints_ = 0;
    return;
  }
  std::cout << " takes " << amount << " points of damage" << std::endl;
  this->hitPoints_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!checkStatus())
    return;
  std::cout << "ClapTrap " << this->name_ << " repairs itself, restoring "
            << amount << " hit points" << std::endl;
  this->hitPoints_ += amount;
  this->energyPoints_--;
}
