#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) { *this = rhs; }
Bureaucrat& operator=(const Bureaucrat& rhs) {
  if (this != &rhs) {
    this->_grade = rhs._grade;
    this->_name = rhs._name;
  }
  return (*this);
}
Bureaucrat::Bureaucrat(std::string name, int grade) {
  try {
    this->_name = name;
    this->_grade = grade;
    if (_grade > 150) throw GradeTooHighException();
    if (_grade < 1) throw GradeTooLowException();
  } catch (const GradeTooHighException& ge) {
    ge.what();
  } catch (const GradeTooLowException& le) {
    le.what();
  }
}
std::string Bureaucrat::getName() const { return (this->_name); }
unsigned int Bureaucrat::getGrade() const { return (this->_grade); }