#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  PresidentialPardonForm();

 public:
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &rhs);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
  bool execute(Bureaucrat const &executor) const;
};