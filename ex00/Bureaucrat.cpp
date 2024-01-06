#include "Bureaucrat.hpp"

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
void Bureaucrat::setGradeMax() { this->_grade = 1; }
void Bureaucrat::setGradeMin() { this->_grade = 150; }

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
  os << " name is : ";
  os << rhs.getName();
  os << "  /  grade is : ";
  os << rhs.getGrade();

  return (os);
}