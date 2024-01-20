#ifndef __INTERN_HPP
#define __INTERN_HPP

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& rhs);
  Intern& operator=(const Intern& rhs);
  ~Intern();
  Form* getShruberry(const std::string fname);
  Form* getRobo(const std::string fname);
  Form* getPardon(const std::string fname);
  Form* makeForm(std::string formType, std::string target);
  static Form* (Intern::*forms[3])(const std::string);
};
static const std::string formTypes[] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};

#endif