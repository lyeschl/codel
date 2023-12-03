#!/bin/bash

flex -o src/lexer/lex.yy.c src/lexer/codel-lex.l
bison -d -o src/parser/codel-syn.tab.c src/parser/codel-syn.y
gcc -g -o codel src/main/main.c src/lexer/lex.yy.c src/parser/codel-syn.tab.c src/utils/*.c -ly -lfl

# Run tests
# for file in tests/correct_code/*.txt; do
#     echo "Running test: $file"
#     ./codel "$file"
# done

# for file in tests/incorrect_code/*.txt; do
#     echo "Running test: $file"
#     ./codel "$file"
# done
