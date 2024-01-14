#include "Bureaucrat.hpp"
#include "Form.hpp"

void test1(void);
void test2(void);
void test3(void);

int main() {
  test1();
  test2();
  test3();

  // try ;{
  //   Bureaucrat lkc("Leekichan", 1);
  //   Bureaucrat officer("ShinWondie", 1);
  //   // 이기찬 3등급

  //   Form form("Finacial Form", 2, 3);
  //   // 재정 양식 필요사인 양식 2등급 , 필요 실행등급 3등급
  //   form.beSigned(lkc);
  //   form.beSigned(officer);
  //   // 이미 사인되어있는 것에 시도시에는 사인이 불가능하다고 함.
  //   // form.beSigned(bp);
  //   // 재정양식은 사인이 가능하다.

  //   lkc.signForm(form);
  //   officer.signForm(form);
  // } catch (const Bureaucrat::GradeTooHighException& ge) {
  //   std::cout << ge.what();
  // } catch (const Bureaucrat::GradeTooLowException& le) {
  //   std::cout << le.what();
  // }
}

void test1(void) {
  try {
    std::cout << "----------TEST1--------------\n";

    Bureaucrat officer("wonie", 1);
    Form form("주차 위반 건에 관하여", 5, 120);
    form.beSigned(officer);
    officer.signForm(form);
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
    officer.minusGrade();
    officer.minusGrade();
    form.beSigned(officer);
    officer.signForm(form);
    std::cout << form << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}