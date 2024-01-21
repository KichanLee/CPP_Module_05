#include "ShrubberyCreationForm.hpp"

#define ASCII_TREES             \
  "\t***************\n"         \
  "\t****************\n"        \
  "\t****************\n"        \
  "\t*****************\n"       \
  "\t******************\n"      \
  "\t*********************\n"   \
  "*************************\n" \
  "        |||\n"               \
  "        |||\n"               \
  "        |||\n"               \
  "        |||\n"
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
    : Form(name, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
    : Form(rhs) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& rhs) {
  if (this != &rhs) {
    Form::operator=(rhs);
  }
  return *this;
}
bool ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  std::ofstream outputFile((this->get_Name() + "__shrubbery").c_str());

  if (this->get_Sigend() &&
      this->get_required_Execute_Grade() > executor.getGrade()) {
    if (outputFile.is_open()) {
      outputFile << ASCII_TREES;
      outputFile.close();
      return (true);
    } else {
      std::cerr << "Unable to open the file." << std::endl;
    }
    return (false);
  }
  std::cout << "You need to Sign!\n";
  return (false);
}