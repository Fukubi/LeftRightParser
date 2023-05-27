#include <gtest/gtest.h>

#include "SimpleGrammarLKT.hpp"

TEST(SimpleGrammarLKT, SingleInput) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_STREQ(lkt->getValue("", "int").c_str(), "S");
  delete lkt;
}

TEST(SimpleGrammarLKT, BeginMultiply) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_STREQ(lkt->getValue("", "int").c_str(), "S");
  ASSERT_STREQ(lkt->getValue("int", "*").c_str(), "*");
  delete lkt;
}

TEST(SimpleGrammarLKT, FullMultiplication) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_STREQ(lkt->getValue("", "int").c_str(), "S");
  ASSERT_STREQ(lkt->getValue("int", "*").c_str(), "*");
  ASSERT_STREQ(lkt->getValue("*", "int").c_str(), "S");
  ASSERT_STREQ(lkt->getValue("int", "end").c_str(), "");
  delete lkt;
}

TEST(SimpleGrammarLKT, MultiplicationWith3Numbers) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_STREQ(lkt->getValue("", "int").c_str(), "S");
  ASSERT_STREQ(lkt->getValue("int", "*").c_str(), "*");
  ASSERT_STREQ(lkt->getValue("*", "int").c_str(), "S");
  ASSERT_STREQ(lkt->getValue("int", "*").c_str(), "*");
  ASSERT_STREQ(lkt->getValue("*", "int").c_str(), "S");
  ASSERT_STREQ(lkt->getValue("int", "end").c_str(), "");
  delete lkt;
}