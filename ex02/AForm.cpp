#include "AForm.hpp"

AForm::~AForm() {}
AForm::AForm(const AForm& rhs)
    : _name(rhs._name),
      _required_Sign_Grade(rhs._required_Sign_Grade),
      _required_Execute_Grade(rhs._required_Execute_Grade) {
  *this = rhs;
}
AForm& AForm::operator=(const AForm& rhs) {
  if (this != &rhs) this->_signed = rhs._signed;
  return (*this);
}

AForm::AForm(std::string name, unsigned required_Sign_Grade,
             unsigned int _required_Execute_Grade)
    : _name(name),
      _required_Sign_Grade(required_Sign_Grade),
      _required_Execute_Grade(_required_Execute_Grade) {
  try {
    if (required_Sign_Grade < 1) throw GradeTooHighException();
    if (required_Sign_Grade > 150) throw GradeTooHighException();
  } catch (GradeTooHighException& ge) {
    std::cout << ge.what() << std::endl;
  }
  _signed = false;
}

std::string AForm::get_Name() const { return (this->_name); }

bool AForm::get_Sigend() const { return (this->_signed); }

int AForm::get_required_Sign_Grade() const {
  return (this->_required_Sign_Grade);
}

int AForm::get_required_Execute_Grade() const {
  return (this->_required_Execute_Grade);
}

bool AForm::get_Executed() const { return (this->_executed); }

void AForm::beSigned(const Bureaucrat& rhs) {
  if (!_signed) {
    if (this->_required_Sign_Grade < rhs.getGrade()) {
      throw GradeTooLowException();
    }
    this->_signed = true;
    const_cast<Bureaucrat&>(rhs).check_sign = 1;
    std::cout << "Sign Success!\n";
  } else {
    std::cout << "Already Signed it\n";
  }
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
  os << "AForm name is : " << rhs.get_Name();
  os << "\nIs the AForm Signed ? " << rhs.get_Sigend();
  os << "\nRequired_Sign_Grade : " << rhs.get_required_Sign_Grade();
  os << "\nRequired_Execute_Grade : " << rhs.get_required_Execute_Grade();
  return os;
}