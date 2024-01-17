#ifndef __INTERN_HPP
#define __INTERN_HPP

#include <string>

class Intern {
 public:
  Intern();
  Intern(const Intern& rhs);
  void makeForm(std::string form_name, std::string form);
  Intern& operator=(const Intern& rhs);
  virtual ~Intern();
};

#endif