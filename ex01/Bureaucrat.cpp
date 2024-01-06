#include "Bureaucrat.hpp"

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
/**
 *    <관료>가 <양식>에 서명했습니다.
      그렇지 않으면 다음과 같이 출력됩니다:
      <관료>가 <이유> 때문에 <양식>에 서명할 수 없습니다.
*/

void Bureaucrat::signForm(Form& rhs) {
  if (rhs.get_Sigend()) {
    std::cout << "< " << this->getName() << " > signed < " << rhs.get_Name()
              << " >\n";
  } else {
    std::cout << "< " << this->getName() << " > couldn't sign < "
              << rhs.get_Name() << " > because < \n";
  }
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