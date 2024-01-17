#include "Intern.hpp"

Intern::Intern(const Intern& rhs) { *this = rhs; }
Intern& Intern::operator=(const Intern& rhs) {
  if (this != &rhs) return (*this);
}