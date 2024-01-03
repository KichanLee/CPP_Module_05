#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>

class Bureaucrat {
 private:
  int _grade;
  std::string _name;
  Bureaucrat();

 public:
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat& rhs);
  Bureaucrat& operator=(const Bureaucrat& rhs);
  Bureaucrat(std::string name, int grade);
  std::string getName() const;
  unsigned int getGrade() const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw() {
      return "grade 는 150 초과는 불가능합니다.";
    }
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw() {
      return "grade 는 1 미만은 불가능합니다.";
    }
  };
};

#endif