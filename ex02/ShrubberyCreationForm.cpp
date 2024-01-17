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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _name)
    : AForm(_name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : AForm(ref) {
  *this = ref;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& ref) {
  if (this != &ref) {
    return *this;
  }
  return *this;
}

int ShrubberyCreationForm::execute(Bureaucrat const& Shrub) const {
  std::ofstream file;
  std::string filename;
  filename = Shrub.getName() + "_shrubbery";

  if (beExecute() == 0) {
    std::cout << Shrub.getName()
              << "'s grade is lower than ShrubberyCreation's execute grade."
              << std::endl;
    return false;
  }
  file.open(filename.c_str());
  if (file.fail()) {
    std::cout << "check, this " << filename << " file." << std::endl;
    return false;
  }

  file << ASCII_TREES;

  return false;
}