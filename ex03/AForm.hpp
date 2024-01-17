#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 protected:
  const std::string _name;
  bool _signed;
  const unsigned int _required_Sign_Grade;
  const unsigned int _required_Execute_Grade;
  std::string err_msg;
  AForm();
  virtual ~AForm();
  std::string get_Name() const;
  bool get_Sigend() const;
  int get_required_Sign_Grade() const;
  int get_required_Execute_Grade() const;
  void beSigned(const Bureaucrat &rhs);
  void signForm();
  int beExecute() const;
  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };

 public:
  AForm(const AForm &rhs);
  AForm &operator=(const AForm &rhs);
  AForm(std::string name, unsigned required_Sign_Grade,
        unsigned int _required_Execute_Grade);
  virtual int execute(Bureaucrat const &executor) const = 0;
};
std::ostream &operator<<(std::ostream &os, const AForm &rhs);
#endif