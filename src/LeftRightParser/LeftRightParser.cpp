#include "LeftRightParser.hpp"

LeftRightParser::LeftRightParser(LookupTable* lkt) { this->lkt = lkt; }

LeftRightParser::~LeftRightParser() { delete this->lkt; }

std::string LeftRightParser::parse(std::string stream) {
  this->readedSymbols = "";
  this->lookAhead = "";

  if (stream.empty()) {
    return "S";
  }

  int counterChar = 0;
  int counterNumber = 0;
  std::string value;

  for (char el : stream) {
    if (el == '*' || el == ' ') {
      counterChar++;
    } else if (std::string("123456789").find(el) != std::string::npos) {
      counterNumber++;
    } else {
      std::cerr << "Entrada nao aceita na regra gramatical\n";
      return "";
    }
  }

  if ((counterChar + 1) != counterNumber && stream.size() != 1) {
    std::cerr << "Entrada nao aceita na regra gramatical\n";
    return "";
  }

  stream.push_back(';');

  for (char el : stream) {
    if (std::string("123456789").find(el) != std::string::npos) {
      this->lookAhead = "int";
    } else if (el == '*') {
      this->lookAhead = "*";
    } else {
      this->lookAhead = "end";
    }

    value = this->lkt->getValue(this->readedSymbols, this->lookAhead);

    if (this->lookAhead.compare("end") != 0) {
      std::cout << value << "->" << el << "\n";
      this->readedSymbols = this->readedSymbols + value;
    }
  }

  value = this->lkt->getValue(this->readedSymbols, this->lookAhead);
  std::cout << value << "->" << this->readedSymbols << "\n";

  return value;
}
