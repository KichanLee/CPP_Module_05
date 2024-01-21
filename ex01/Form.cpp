#include "Form.hpp"

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
}

std::string Form::get_Name() const { return (this->_name); }

bool Form::get_Signed() const { return (this->_signed); }

int Form::get_required_Sign_Grade() const {
  return (this->_required_Sign_Grade);
}

int Form::get_required_Execute_Grade() const {
  return (this->_required_Execute_Grade);
}

void Form::beSigned(const Bureaucrat& rhs) {
  if (!_signed) {
    if (this->_required_Sign_Grade < rhs.getGrade()) {
      std::cout << "Grade is too Low!\n";
      return;
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
  os << "\nIs the Form Signed ? " << rhs.get_Signed();
  os << "\nRequired_Sign_Grade : " << rhs.get_required_Sign_Grade();
  os << "\nRequired_Execute_Grade : " << rhs.get_required_Execute_Grade();
  return os;
}