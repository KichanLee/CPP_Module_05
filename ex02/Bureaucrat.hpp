#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <exception>
#include <iostream>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
 private:
  unsigned int _grade;
  const std::string _name;
  Bureaucrat();

 public:
  int check_sign;
  virtual ~Bureaucrat();
  Bureaucrat(const Bureaucrat& rhs);
  Bureaucrat& operator=(const Bureaucrat& rhs);
  Bureaucrat(const std::string name, unsigned int grade);
  std::string getName() const;
  unsigned int getGrade() const;
  void setGradeMax();
  void setGradeMin();
  void plusGrade();
  void minusGrade();
  void signForm(AForm& rhs);
  void executeForm(AForm const& form);
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);
#endif