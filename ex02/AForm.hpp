#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  const std::string _name;
  bool _signed;
  bool _executed;
  unsigned int _required_Sign_Grade;
  unsigned int _required_Execute_Grade;
  AForm();

 public:
  virtual ~AForm();
  AForm(const AForm &rhs);
  AForm &operator=(const AForm &rhs);
  AForm(std::string name, unsigned required_Sign_Grade,
        unsigned int _required_Execute_Grade);

  std::string get_Name() const;
  bool get_Sigend() const;
  bool get_Executed() const;
  bool check_Executed() const;
  int get_required_Sign_Grade() const;
  int get_required_Execute_Grade() const;
  void set_Name(std::string name);
  void set_Signed(bool sign);
  void set_Required_Sign_Grade(unsigned int sign_grade);
  void set_Required_Execute_Grade(unsigned int execute_grade);
  void beSigned(const Bureaucrat &rhs);
  void signForm();
  bool virtual execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw() { return "grade too High.\n"; }
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw() { return "grade too Low.\n"; }
  };
};
std::ostream &operator<<(std::ostream &os, const AForm &rhs);
#endif