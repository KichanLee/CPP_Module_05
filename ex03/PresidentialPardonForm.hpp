#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  PresidentialPardonForm();

 public:
  PresidentialPardonForm(const std::string& _name);
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& ref);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

  int execute(Bureaucrat const& Presidential) const;
};