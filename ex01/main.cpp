#include "Bureaucrat.hpp"
#include "Form.hpp"

void test1(void);
void test2(void);
void test3(void);

int main() {
  test1();
  test2();
  test3();
}

void test1(void) {
  try {
    std::cout << "----------TEST1--------------\n";

    Bureaucrat officer("wonie", 1);
    Bureaucrat officer22("wonie222", 1);
    Form form("주차 위반 건에 관하여", 5, 120);

    form.beSigned(officer22);
    form.beSigned(officer);
    officer.signForm(form);
    officer22.signForm(form);
    std::cout << form << std::endl;

  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test2(void) {
  std::cout << "----------TEST2--------------\n";
  Bureaucrat officer("konie", 10);
  Form form("식품 위반 건에 관하여", 11, 5);
  try {
    form.beSigned(officer);
    officer.signForm(form);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::cout << form << std::endl;
}

void test3(void) {
  try {
    std::cout << "----------TEST3--------------\n";
    Bureaucrat officer("monie", 149);
    Form form("도박 위반 건에 관하여", 130, 150);
    form.beSigned(officer);
    officer.signForm(form);
    std::cout << form << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}