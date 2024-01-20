#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
    : Form(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& rhs)
    : Form(rhs) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& rhs) {
  Form::operator=(rhs);
  return (*this);
}
bool PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (this->get_Sigend() &&
      this->get_required_Execute_Grade() > executor.getGrade()) {
    std::cout << this->get_Name()
              << " has been pardoned by Zaphod Beeblebrox.\n";
    return (true);
  } else {
    std::cout << this->get_Name() << " Check Grade\n";
  }

  return (false);
}