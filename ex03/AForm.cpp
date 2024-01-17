#include "AForm.hpp"

AForm::~AForm() {}
AForm::AForm(const AForm& rhs)
    : _name(rhs._name),
      _required_Sign_Grade(rhs._required_Sign_Grade),
      _required_Execute_Grade(rhs._required_Execute_Grade) {
  *this = rhs;
}
AForm& AForm::operator=(const AForm& rhs) {
  if (this != &rhs) {
    this->_signed = rhs._signed;
  }
  return (*this);
}

AForm::AForm(std::string name, unsigned required_Sign_Grade,
             unsigned int _required_Execute_Grade)
    : _name(name),
      _required_Sign_Grade(required_Sign_Grade),
      _required_Execute_Grade(_required_Execute_Grade) {
  if (required_Sign_Grade < 1) throw GradeTooHighException();
  if (required_Sign_Grade > 150) throw GradeTooHighException();

  _signed = false;
}
const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade Too Low\n";
}
const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade Too High\n";
}

std::string AForm::get_Name() const { return (this->_name); }

bool AForm::get_Sigend() const { return (this->_signed); }

int AForm::get_required_Sign_Grade() const {
  return (this->_required_Sign_Grade);
}

int AForm::get_required_Execute_Grade() const {
  return (this->_required_Execute_Grade);
}

void AForm::beSigned(const Bureaucrat& rhs) {
  if (!_signed) {
    if (this->_required_Sign_Grade < rhs.getGrade()) {
      throw GradeTooLowException();
    } else {
      this->_signed = true;
      std::cout << "Sign Success!\n";
    }
  } else
    std::cout << "Already Signed it\n";
}

int AForm::beExecute() const {
  if (this->_signed == true &&
      this->get_required_Execute_Grade() <= this->get_required_Sign_Grade()) {
    return true;
  } else {
    return false;
  }
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
  os << "AForm name is : " << rhs.get_Name();
  os << "\nIs the AForm Signed ?" << rhs.get_Sigend();
  os << "\nRequired_Sign_Grade : " << rhs.get_required_Sign_Grade();
  os << "\nRequired_Execute_Grade : " << rhs.get_required_Execute_Grade();

  return os;
}