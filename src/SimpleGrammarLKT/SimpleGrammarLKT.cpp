#include "SimpleGrammarLKT.hpp"

SimpleGrammarLKT::SimpleGrammarLKT() {
  this->lookupTable.push_back({"", "2", "", ""});
  this->lookupTable.push_back({"*", "2", "0", "0"});
  this->lookupTable.push_back({"S", "", "1", "0"});

  this->actualRow = 0;
}

std::string SimpleGrammarLKT::getValue(std::string readed,
                                       std::string lookAhead) {
  if (!lookAhead.compare("int")) {
    this->actualRow = std::stoi(this->lookupTable[this->actualRow][1]);
  } else if (!lookAhead.compare("*")) {
    this->actualRow = std::stoi(this->lookupTable[this->actualRow][2]);
  } else if (!lookAhead.compare("end")) {
    this->actualRow = std::stoi(this->lookupTable[this->actualRow][3]);
  }

  std::string output = this->lookupTable[this->actualRow][0];

  return output;
}
