#pragma once

#include "LookupTable.hpp"

class SimpleGrammarLKT : public LookupTable {
 public:
  SimpleGrammarLKT();
  std::string getValue(std::string readed, std::string lookAhead);
};