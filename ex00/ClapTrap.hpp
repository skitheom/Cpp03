/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:50:24 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/11 01:21:45 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
  std::string name_;
  unsigned int hitPoints_;
  unsigned int energyPoints_;
  unsigned int attackDamage_;

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
