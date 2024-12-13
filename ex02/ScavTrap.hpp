/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:59:52 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 14:02:35 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
private:
  bool isGuardingGate_;

  void printName() const;
  void printNoHitPointsMsg() const;
  void printNoEnergyPointsMsg() const;
  void printAttackMsg(const std::string &message) const;
  bool checkStatus();

public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ~ScavTrap();

  ScavTrap &operator=(const ScavTrap &other);

  void attack(const std::string &target);
  void guardGate();
};

#endif
