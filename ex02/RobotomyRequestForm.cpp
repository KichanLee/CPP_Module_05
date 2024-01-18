#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name)
    : AForm(name, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
    : AForm(rhs) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& rhs) {
  AForm::operator=(rhs);

  return (*this);
}