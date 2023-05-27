# LR(1) Parser

A Bottom Up LR(1) Parser done in C++ to recognize a simple language, but still extensible enough to be expanded.

## Usage

It was used CMake to make it easier to test, compile and run the project. To make a runnable file you can use
```bash
# Create the build directory
mkdir build
# Change to it
cd build
# Generate files
cmake ..
# Compile
make
```

And then run
```bash
# Assuming you are in the build directory
./src/parser
```

To execute the tests you can run in the build directory the command
```bash
# Assuming you are in the build directory
ctest
```

## Descriptions

```mermaid
classDiagram
	class LeftRightParser
	LeftRightParser: -String lookAhead
	LeftRightParser: -String readedSymbols
	LeftRightParser: -LookupTable *lkt
	LeftRightParser: +LeftRightParser(LookupTable *lkt)
	LeftRightParser: +~LeftRightParser()
	LeftRightParser: +String parse(String stream)

	class LookupTable
	<<Interface>> LookupTable
	LookupTable: -int actualRow
	LookupTable: -Matrix lookupTable
	LookupTable: +String getValue(String readed, String lookAhead)

	class SimpleGrammarLKT
	SimpleGrammarLKT: +SimpleGrammarLKT()
	SimpleGrammarLKT: +String getValue(String readed, String lookAhead)

	SimpleGrammarLKT --|> LookupTable

	LeftRightParser ..* LookupTable
```

## Test Grammar
- S : S * S | A
- A : 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | $\epsilon$

## Lookup Table:
| state | regra atual               | int | *   | eof |
| ----- | ------------------------- | --- | --- | --- |
| 0     | Objetivo -> $\cdot$ S * S | 2    |    |     |
| 1     | Objetivo -> Value * $\cdot$ S | 2   | 0   | Finalizado   |
| 2     | S -> Value $\cdot$               |     | 1   |     |
