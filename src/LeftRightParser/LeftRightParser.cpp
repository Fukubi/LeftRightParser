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

  for (char el : stream) {
    if (el == '*' || el == ' ') {
      counterChar++;
    } else if (std::string("123456789").find(el) != std::string::npos) {
      counterNumber++;
    } else {
      std::cerr << "Entrada não aceita na regra gramátical\n";
      return "";
    }
  }

  // A quantidade de números sempre será par a menos que seja a cadeia vazia, aqui é utilizado
  // isso para ter certeza que a entrada é, ao menos, do tipo S*S ou S*S*S*S
  if (counterNumber % 2 != 0) {
    std::cerr << "Entrada não aceita na regra gramátical\n";
    return "";
  }

  for (char el : stream) {
    if (std::string("123456789").find(el) != std::string::npos) {
      this->lookAhead = "int";
    } else if (el == '*') {
      this->lookAhead = "*";
    } else {
      this->lookAhead = "end";
    }

    std::string value =
        this->lkt->getValue(this->readedSymbols, this->lookAhead);

    std::cout << value << "->" << el << "\n";

    this->readedSymbols = this->readedSymbols + value;
  }

  return this->readedSymbols;
}
