clear
flex --outfile="lex.c" codel-lex.l
bison -d codel-syn.y -o synt.c -Wcounterexamples
# gcc -w lex.c synt.c -lfl -ly -o codel-lex
# rm *.c
# rm *.h
# echo 'end of compilation, analysing _test.txt...'
# ./codel-lex </tests/correct_code/test1.txt