#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  RobotomyRequestForm();

 public:
  RobotomyRequestForm(std::string name);
  RobotomyRequestForm(const RobotomyRequestForm& rhs);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

  virtual ~RobotomyRequestForm();
};
