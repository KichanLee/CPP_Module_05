#include "Intern.hpp"

Intern::Intern(const Intern& rhs) { *this = rhs; }
Intern& Intern::operator=(const Intern& rhs) {
  if (this != &rhs) return (*this);
}

AForm* Intern::getShruberry(const std::string fname) {
  return new ShrubberyCreationForm(fname);
}

AForm* Intern::getRobo(const std::string fname) {
  return new RobotomyRequestForm(fname);
}

AForm* Intern::getPardon(const std::string fname) {
  return new PresidentialPardonForm(fname);
}

AForm* Intern::makeForm(std::string formType, std::string target) {
  for (size_t i = 0; i < sizeof(formTypes) / sizeof(formTypes[0]); ++i) {
    if (formType == formTypes[i]) {
      std::cout << "Intern creates " << formType << std::endl;
      return (this->*forms[i])(target);
    }
  }
  std::cout << "Error: Unknown form type." << std::endl;
  return nullptr;
}