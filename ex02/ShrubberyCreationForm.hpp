
#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm {
 private:
  ShrubberyCreationForm();

 public:
  ShrubberyCreationForm(const std::string& _name);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& ref);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

  int execute(Bureaucrat const& Shrub) const;
};