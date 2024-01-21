#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const std::string name)
    : Form(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
    : Form(rhs) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& rhs) {
  if (this != &rhs) {
    Form::operator=(rhs);
  }
  return (*this);
}

bool RobotomyRequestForm::fiftyPercentChance() const {
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  int randomValue = std::rand();
  return (randomValue % 2 == 0);
}

bool RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (this->get_Sigend()) {
    if (this->get_required_Execute_Grade() < executor.getGrade())
      throw GradeTooLowException();
    std::cout << "drilling~~~~~~\n";
    if (fiftyPercentChance()) {
      std::cout << this->get_Name() << " has been robotomized\n";
      return (true);
    } else {
      std::cout << "robotomy failed\n";
    }
  }
  std::cout << "robotomy failed\n";
  return (false);
}
