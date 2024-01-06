#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat bp("Leekichan", 160);

  Form form("Finacial Form", 2, 3);
  catc form.beSigned(bp);
  form.beSigned(bp);
}