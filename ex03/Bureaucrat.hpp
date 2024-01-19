#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <exception>
#include <iostream>

#include "Form.hpp"

class Form;

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
  void signForm(Form& rhs);
  void check_sign();
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