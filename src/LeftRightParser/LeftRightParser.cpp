#include "LeftRightParser.hpp"

LeftRightParser::LeftRightParser(LookupTable* lkt) { this->lkt = lkt; }

LeftRightParser::~LeftRightParser() { delete this->lkt; }

std::string LeftRightParser::parse(std::string stream) {
  this->readedSymbols = "";
  this->lookAhead = "";

  for (char el : stream) {
    if (std::string("123456789").find(el) != std::string::npos) {
      this->lookAhead = "int";
    } else if (el == '*') {
      this->lookAhead = "*";
    } else {
      this->lookAhead = "end";
    }

    this->readedSymbols =
        this->readedSymbols +
        this->lkt->getValue(this->readedSymbols, this->lookAhead);
  }

  return this->readedSymbols;
}
