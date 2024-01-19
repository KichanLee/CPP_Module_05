#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
    : AForm(name, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& rhs)
    : AForm(rhs) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& rhs) {
  AForm::operator=(rhs);
  return (*this);
}
bool PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (this->get_required_Execute_Grade() > executor.getGrade())
    throw GradeTooLowException();
  std::cout << this->get_Name() << "has been pardoned by Zaphod Beeblebrox.\n";
}