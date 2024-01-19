#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
    : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
    : AForm(rhs) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return (*this);
}

bool RobotomyRequestForm::fiftyPercentChance() const {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  int randomValue = std::rand();
  return (randomValue % 2 == 0);
}

bool RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  std::cout << "drilling~~~~~~\n";
  if (fiftyPercentChance()) {
    std::cout << this->get_Name() << " has been robotomized\n";
    return true;
  } else {
    std::cout << "You failed\n";
    return false;
  }
}