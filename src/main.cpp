#include <algorithm>
#include <iostream>

#include "LeftRightParser.hpp"
#include "SimpleGrammarLKT.hpp"

int main() {
  LeftRightParser *lr = new LeftRightParser(new SimpleGrammarLKT());
  std::string in;

  int space_counter;
  int size_after_input;

  std::cout << "Type the string inside the gramatical rule: ";
  std::getline(std::cin, in);

  size_after_input = in.length();

  // Removing any extra space
  space_counter = std::count(in.begin(), in.end(), ' ');
  std::remove(in.begin(), in.end(), ' ');
  in.resize(size_after_input - space_counter);

  std::cout << lr->parse(in) << "\n";

  delete lr;

  return 0;
}