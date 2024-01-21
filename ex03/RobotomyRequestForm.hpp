#pragma once

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public Form {
 private:
  RobotomyRequestForm();

 public:
  ~RobotomyRequestForm();
  RobotomyRequestForm(const std::string name);
  RobotomyRequestForm(const RobotomyRequestForm& rhs);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
  bool fiftyPercentChance() const;
  bool execute(Bureaucrat const& executor) const;
};
