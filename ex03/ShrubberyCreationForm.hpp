#pragma once

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public Form {
 private:
  ShrubberyCreationForm();

 public:
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string name);
  ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
  bool execute(Bureaucrat const& executor) const;
};
