#include <gtest/gtest.h>

#include "LeftRightParser.hpp"
#include "SimpleGrammarLKT.hpp"

TEST(LeftRightParserTests, SimpleInput) {
  LeftRightParser *lr = new LeftRightParser(new SimpleGrammarLKT());

  ASSERT_EQ(lr->parse("1"), "S");

  delete lr;
}

TEST(LeftRightParserTests, SimpleMultiplication) {
  LeftRightParser *lr = new LeftRightParser(new SimpleGrammarLKT());

  ASSERT_EQ(lr->parse("1*2"), "S");

  delete lr;
}

TEST(LeftRightParserTests, MultipleMultiplication) {
  LeftRightParser *lr = new LeftRightParser(new SimpleGrammarLKT());

  ASSERT_EQ(lr->parse("1*2*3"), "S");

  delete lr;
}