#include "Bureaucrat.hpp"

#include <string>

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) { *this = rhs; }
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
  if (this != &rhs) this->_grade = rhs._grade;
  return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
    : _name(name) {
  if (grade > 150) {
    throw GradeTooLowException();
  }
  if (grade < 1) {
    throw GradeTooHighException();
  }
  this->_grade = grade;
}

std::string Bureaucrat::getName() const { return (this->_name); }
unsigned int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::plusGrade() {
  if (this->_grade == 1) {
    throw GradeTooHighException();
  }
  this->_grade--;
}

void Bureaucrat::minusGrade() {
  if (this->_grade == 150) {
    throw GradeTooLowException();
  }
  this->_grade++;
}

void Bureaucrat::signForm(AForm& rhs) {
  if (rhs.get_Sigend()) {
    if (this->check_sign == 1) {
      std::cout << this->getName() << "signed it!\n";
    } else if (this->check_sign == 0) {
      std::cout << "< " << this->getName() << " > couldn't sign < "
                << rhs.get_Name()
                << " > because < Someone Already Signed it >\n";
    }
  } else
    throw GradeTooLowException();
}

void Bureaucrat::executeForm(AForm const& form) {
  if (form.execute(*this)) {
    std::cout << this->getName() << " Executed " << form.get_Name() << "\n";
  } else {
    std::cout << "Your executation failed\n";
  }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
  os << " name is : ";
  os << rhs.getName();
  os << "  /  grade is : ";
  os << rhs.getGrade();

  return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "grade is too High\n";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "grade is Too low\n";
}