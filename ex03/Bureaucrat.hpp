#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>

class Bureaucrat {
 private:
  int _grade;
  const std::string _name;
  Bureaucrat();

 public:
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat& rhs);
  Bureaucrat& operator=(const Bureaucrat& rhs);
  Bureaucrat(std::string name, unsigned int grade);
  std::string getName() const;
  unsigned int getGrade() const;
  void setGradeMax();
  void setGradeMin();
  void plusGrade();
  void minusGrade();

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw() {
      return "grade 는 1 초과는 불가능합니다.\n";
    }
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw() {
      return "grade 는 150 미만은 불가능합니다.\n";
    }
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);
#endif