#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test1();
void test2();
void test3();

int main() {
  test1();
  test2();
  test3();

  return 0;
}

void test1() {
  try {
    Bureaucrat bureaucrat("shrubbery executor", 1);
    Intern intern;
    Form* form;

    form = intern.makeForm("shrubbery creation", "shrubbery form");
    if (form == 0) return;

    form->beSigned(bureaucrat);
    form->execute(bureaucrat);
    delete form;
  } catch (std::exception& e) {
    std::cout << "catch exception of shrubberyCreationFormTest" << std::endl;
  }
}

void test2() {
  try {
    Bureaucrat bureaucrat("robotomy executor", 1);
    Intern intern;
    Form* form;

    form = intern.makeForm("robotomy request", "robotomy form");
    if (form == 0) return;
    form->beSigned(bureaucrat);
    form->execute(bureaucrat);
    delete form;
  } catch (std::exception& e) {
    std::cout << "catch exception of robotomyRequestFormTest" << std::endl;
  }
}

void test3() {
  try {
    Bureaucrat bureaucrat("presidential executor", 1);
    Intern intern;
    Form* form;

    form = intern.makeForm("presidential pardon", "presidential form");
    if (form == 0) return;
    form->beSigned(bureaucrat);
    form->execute(bureaucrat);
    delete form;
  } catch (std::exception& e) {
    std::cout << "catch exception of presidentialPardonFormTest" << std::endl;
  }
}
