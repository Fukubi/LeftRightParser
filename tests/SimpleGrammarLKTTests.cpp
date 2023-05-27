#include <gtest/gtest.h>

#include "SimpleGrammarLKT.hpp"

TEST(SimpleGrammarLKT, SingleInput) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_EQ(lkt->getValue("", "int"), "S");
  delete lkt;
}

TEST(SimpleGrammarLKT, BeginMultiply) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_EQ(lkt->getValue("", "int"), "S");
  ASSERT_EQ(lkt->getValue("int", "*"), "*");
  delete lkt;
}

TEST(SimpleGrammarLKT, FullMultiplication) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_EQ(lkt->getValue("", "int"), "S");
  ASSERT_EQ(lkt->getValue("int", "*"), "*");
  ASSERT_EQ(lkt->getValue("*", "int"), "S");
  ASSERT_EQ(lkt->getValue("int", "end"), "");
  delete lkt;
}

TEST(SimpleGrammarLKT, MultiplicationWith3Numbers) {
  LookupTable *lkt = new SimpleGrammarLKT();
  ASSERT_EQ(lkt->getValue("", "int"), "S");
  ASSERT_EQ(lkt->getValue("int", "*"), "*");
  ASSERT_EQ(lkt->getValue("*", "int"), "S");
  ASSERT_EQ(lkt->getValue("int", "*"), "*");
  ASSERT_EQ(lkt->getValue("*", "int"), "S");
  ASSERT_EQ(lkt->getValue("int", "end"), "");
  delete lkt;
}