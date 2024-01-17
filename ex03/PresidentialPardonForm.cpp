#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& name)
    : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& ref)
    : AForm(ref) {
  *this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& ref) {
  if (this == &ref) return *this;
  return *this;
}

int PresidentialPardonForm::execute(Bureaucrat const& Presidential) const {
  if (beExecute()) {
    std::cout << Presidential.getName()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return 1;
  } else {
    std::cout << Presidential.getName()
              << " has not been pardoned and remains convicted." << std::endl;
    return 0;
  }
}
