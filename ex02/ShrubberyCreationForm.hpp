#ifndef __SHRUBBERYCREATIONFORM_HPP
#define __SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  ShrubberyCreationForm();

 public:
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string name);
  ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
  bool execute(Bureaucrat const& executor) const;
};

#endif