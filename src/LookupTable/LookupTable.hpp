#pragma once

#include <string>
#include <vector>

class LookupTable {
 protected:
  int actualRow;
  std::vector<std::vector<std::string>> lookupTable;

 public:
  virtual std::string getValue(std::string readed, std::string lookAhead) = 0;
};