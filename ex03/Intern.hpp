#ifndef __INTERN_HPP
#define __INTERN_HPP

#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& rhs);
  Intern& operator=(const Intern& rhs);
  virtual ~Intern();
  AForm* getShruberry(const std::string fname);
  AForm* getRobo(const std::string fname);
  AForm* getPardon(const std::string fname);
  AForm* makeForm(std::string formType, std::string target);
};
static const std::string formTypes[] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};

#endif