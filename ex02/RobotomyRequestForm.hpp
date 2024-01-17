#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  RobotomyRequestForm();

 public:
  RobotomyRequestForm(const std::string& _name);
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& ref);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

  int execute(Bureaucrat const& robot) const;
};