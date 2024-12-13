/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:02:59 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 13:25:57 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  ~FragTrap();

  FragTrap &operator=(const FragTrap &other);

  void highFivesGuys(void);
};

#endif
