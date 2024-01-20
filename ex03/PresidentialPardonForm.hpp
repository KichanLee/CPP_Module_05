#include "AForm.hpp"

#pragma once

class PresidentialPardonForm : public Form {
 private:
  PresidentialPardonForm();

 public:
  PresidentialPardonForm(const std::string name);
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &rhs);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
  bool execute(Bureaucrat const &executor) const;
};
