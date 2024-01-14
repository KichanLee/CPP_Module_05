#include "Bureaucrat.hpp"

#include <string>

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) { *this = rhs; }
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
  if (this != &rhs) {
    this->_grade = rhs._grade;
  }
  return (*this);
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  this->check_sign = 0;
  try {
    this->_grade = grade;
    if (_grade > 150) throw Bureaucrat::GradeTooLowException();
    if (_grade < 1) throw Bureaucrat::GradeTooHighException();
  } catch (const GradeTooHighException& ge) {
    this->setGradeMax();
    std::cout << ge.what();
  } catch (const GradeTooLowException& le) {
    this->setGradeMin();
    std::cout << le.what();
  }
}

std::string Bureaucrat::getName() const { return (this->_name); }
unsigned int Bureaucrat::getGrade() const { return (this->_grade); }
void Bureaucrat::setGradeMax() { this->_grade = 1; }
void Bureaucrat::setGradeMin() { this->_grade = 150; }
void Bureaucrat::plusGrade() {
  try {
    this->_grade--;
    if (this->_grade < 1) throw GradeTooHighException();
  } catch (const GradeTooHighException& ge) {
    std::cout << ge.what();
    this->setGradeMax();
    return;
  }
}

void Bureaucrat::signForm(Form& rhs) {
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

void Bureaucrat::minusGrade() {
  try {
    this->_grade++;
    if (this->_grade > 150) throw GradeTooLowException();
  } catch (const GradeTooLowException& ge) {
    std::cout << ge.what();
    this->setGradeMin();
    return;
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
  return "grade 는 1 초과는 불가능합니다.\n";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "grade 는 150 미만은 불가능합니다.\n";
}