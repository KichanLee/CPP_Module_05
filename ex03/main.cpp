#include "AForm.hpp"
#include "Intern.hpp"

int main() {
  {
    Intern someRandomIntern;
    AForm* rrf;

    // 첫번재는 폼의 이름 , 두번째는 폼의 대상
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  }
}
