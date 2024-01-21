#include "AForm.hpp"

Form::~Form() {}
Form::Form(const Form& rhs)
    : _name(rhs._name),
      _required_Sign_Grade(rhs._required_Sign_Grade),
      _required_Execute_Grade(rhs._required_Execute_Grade) {
  *this = rhs;
}
Form& Form::operator=(const Form& rhs) {
  if (this != &rhs) this->_signed = rhs._signed;
  return (*this);
}

Form::Form(std::string name, unsigned required_Sign_Grade,
           unsigned int _required_Execute_Grade)
    : _name(name),
      _required_Sign_Grade(required_Sign_Grade),
      _required_Execute_Grade(_required_Execute_Grade) {
  if (required_Sign_Grade < 1) throw GradeTooHighException();
  if (required_Sign_Grade > 150) throw GradeTooHighException();
  _signed = false;
  _executed = false;
}

void Form::set_Executed() { this->_executed = true; }

std::string Form::get_Name() const { return (this->_name); }

bool Form::get_Sigend() const { return (this->_signed); }

unsigned int Form::get_required_Sign_Grade() const {
  return (this->_required_Sign_Grade);
}

unsigned int Form::get_required_Execute_Grade() const {
  return (this->_required_Execute_Grade);
}

bool Form::get_Executed() const { return (this->_executed); }

void Form::beSigned(const Bureaucrat& rhs) {
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

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
  os << "Form name is : " << rhs.get_Name();
  os << "\nIs the Form Signed ? " << rhs.get_Sigend();
  os << "\nRequired_Sign_Grade : " << rhs.get_required_Sign_Grade();
  os << "\nRequired_Execute_Grade : " << rhs.get_required_Execute_Grade();
  return os;
}