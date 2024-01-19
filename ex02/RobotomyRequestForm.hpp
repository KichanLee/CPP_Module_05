#include <cstdlib>
#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  RobotomyRequestForm();

 public:
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(const std::string name);
  RobotomyRequestForm(const RobotomyRequestForm& rhs);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
  bool fiftyPercentChance() const;
  bool virtual execute(Bureaucrat const& executor) const;
};
