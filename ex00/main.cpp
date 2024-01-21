#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat bp("leekichan", 4);
    std::cout << bp << std::endl;
    bp.plusGrade();
    std::cout << bp << std::endl;
    bp.plusGrade();
    std::cout << bp << std::endl;
    bp.plusGrade();
    std::cout << bp << std::endl;
    bp.plusGrade();
    std::cout << bp << std::endl;
    bp.plusGrade();
    std::cout << bp << std::endl;
  } catch (const Bureaucrat::GradeTooHighException& ge) {
    std::cout << "Caught GradeTooHighException: " << ge.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException& le) {
    std::cout << "Caught GradeTooLowException: " << le.what() << std::endl;
  }

  std::cout << "\n=============================================\n";

  try {
    Bureaucrat bp_two("honhond", 148);
    bp_two.minusGrade();
    std::cout << bp_two << std::endl;
    bp_two.minusGrade();
    std::cout << bp_two << std::endl;
    bp_two.plusGrade();
    std::cout << bp_two << std::endl;
    bp_two.minusGrade();
    std::cout << bp_two << std::endl;
    bp_two.minusGrade();
  } catch (const Bureaucrat::GradeTooHighException& ge) {
    std::cout << "Caught GradeTooHighException: " << ge.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException& le) {
    std::cout << "Caught GradeTooLowException: " << le.what() << std::endl;
  }

  return 0;
}