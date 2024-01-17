#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    PresidentialPardonForm ppf("Yun Seok Yeol");
    RobotomyRequestForm("Bill");
    ShrubberyCreationForm("Financial Form");
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}