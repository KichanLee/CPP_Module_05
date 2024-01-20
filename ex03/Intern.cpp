#include "Intern.hpp"
Form* (Intern::*Intern::forms[3])(const std::string) = {
    &Intern::getShruberry, &Intern::getRobo, &Intern::getPardon};
Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& rhs) { *this = rhs; }
Intern& Intern::operator=(const Intern& rhs) {
  if (this != &rhs) return (*this);
  return (*this);
}

Form* Intern::getShruberry(const std::string fname) {
  return new ShrubberyCreationForm(fname);
}

Form* Intern::getRobo(const std::string fname) {
  return new RobotomyRequestForm(fname);
}

Form* Intern::getPardon(const std::string fname) {
  return new PresidentialPardonForm(fname);
}

Form* Intern::makeForm(std::string formType, std::string target) {
  for (size_t i = 0; i < sizeof(formTypes) / sizeof(formTypes[0]); ++i) {
    if (formType == formTypes[i]) {
      std::cout << "Intern creates " << formType << std::endl;
      return (this->*forms[i])(target);
    }
  }
  std::cout << "Error: Unknown form type." << std::endl;
  return nullptr;
}