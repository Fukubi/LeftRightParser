#pragma once

#include <iostream>
#include "LookupTable.hpp" 

class LeftRightParser {
 private:
    std::string lookAhead;
    std::string readedSymbols;
    LookupTable *lkt;
 public:
    LeftRightParser(LookupTable *lkt);
    ~LeftRightParser();
    std::string parse(std::string stream);
};