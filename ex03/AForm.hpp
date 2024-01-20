#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool _signed;
  bool _executed;
  unsigned int _required_Sign_Grade;
  unsigned int _required_Execute_Grade;
  Form();

 public:
  virtual ~Form();
  Form(const Form &rhs);
  Form &operator=(const Form &rhs);
  Form(std::string name, unsigned required_Sign_Grade,
       unsigned int _required_Execute_Grade);

  std::string get_Name() const;
  bool get_Sigend() const;
  bool get_Executed() const;
  void set_Executed();
  unsigned int get_required_Sign_Grade() const;
  unsigned int get_required_Execute_Grade() const;
  void set_Name(std::string name);
  void set_Signed(bool sign);
  void set_Required_Sign_Grade(unsigned int sign_grade);
  void set_Required_Execute_Grade(unsigned int execute_grade);
  void beSigned(const Bureaucrat &rhs);
  void signForm();
  virtual bool execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw() { return "grade too High.\n"; }
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw() { return "grade too Low.\n"; }
  };
};
std::ostream &operator<<(std::ostream &os, const Form &rhs);
#endif