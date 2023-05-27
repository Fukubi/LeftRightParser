add_executable(parser main.cpp)

add_subdirectory(LookupTable)
add_subdirectory(SimpleGrammarLKT)

target_link_libraries(parser simple_grammar_lkt)