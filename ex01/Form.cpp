#include "Form.hpp"

Form::~Form() {}
Form::Form(const Form& rhs)
    : _name(rhs._name),
      _required_Sign_Grade(rhs._required_Sign_Grade),
      _required_Execute_Grade(rhs._required_Execute_Grade) {
  *this = rhs;
}
Form& Form::operator=(const Form& rhs) {
  if (this != &rhs) {
    this->_signed = rhs._signed;
  }
  return (*this);
}

Form::Form(std::string name, unsigned required_Sign_Grade,
           unsigned int _required_Execute_Grade)
    : _name(name),
      _required_Sign_Grade(required_Sign_Grade),
      _required_Execute_Grade(_required_Execute_Grade) {
  try {
    if (required_Sign_Grade < 1) throw GradeTooHighException();
    if (required_Sign_Grade > 150) throw GradeTooHighException();
  } catch (GradeTooHighException& ge) {
    std::cout << ge.what() << std::endl;
    this->_required_Sign_Grade = 1;
  }
  if (required_Sign_Grade > 150) throw GradeTooLowException();
  _signed = false;
}

std::string Form::get_Name() const { return (this->_name); }

bool Form::get_Sigend() const { return (this->_signed); }

int Form::get_required_Sign_Grade() const {
  return (this->_required_Sign_Grade);
}

int Form::get_required_Execute_Grade() const {
  return (this->_required_Execute_Grade);
}

void Form::beSigned(const Bureaucrat& rhs) {
  if (!_signed) {
    try {
      if (this->_required_Sign_Grade < rhs.getGrade()) {
        throw GradeTooLowException();
      } else {
        this->_signed = true;
        std::cout << "Sign Success!\n";
      }
    } catch (GradeTooLowException& ge) {
      std::cout << "You can't sign it\n";
      std::cout << ge.what() << std::endl;
    }
  } else
    std::cout << "Already Signed it\n";
}
std::ostream& operator<<(std::ostream& os, const Form& rhs) {
  os << "Form name is : " << rhs.get_Name();
  os << "\nIs the Form Signed ?" << rhs.get_Sigend();
  os << "\nRequired_Sign_Grade : " << rhs.get_required_Sign_Grade();
  os << "\nRequired_Execute_Grade : " << rhs.get_required_Execute_Grade();

  return os;
}