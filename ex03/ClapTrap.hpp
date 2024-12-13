/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:50:24 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 13:34:12 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
protected:
  std::string name_;
  unsigned int hitPoints_;
  unsigned int energyPoints_;
  unsigned int attackDamage_;
  unsigned int maxHitPoints_;

private:
  void printName() const;
  void printNoHitPointsMsg() const;
  void printNoEnergyPointsMsg() const;
  void printAttackMsg(const std::string &message) const;
  void printAlreadyDeadMsg() const;
  void printDeathMsg(unsigned int amount) const;
  void printTakeDamageMsg(unsigned int amount) const;
  void printHitPointsAlreadyFullMsg() const;
  void printBeRepairedMsg(unsigned int amount) const;

  bool checkStatus();

public:
  ClapTrap();
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &clapTrap);
  ~ClapTrap();

  ClapTrap &operator=(const ClapTrap &clapTrap);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
