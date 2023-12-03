
### TODO
- tried debuging with gdb, seems like there is an error inside yyparse()
- is the new complexity i added to main really necessary?
- codel executes, but every program gets this error
Error at line 1: syntax erro

- make start: declist endl BEGIN endl inst_list END // add endl
- IDs are inserted in sym table in flex, in bison, when finding an ID in a cst dec , modify its Entry with new details
- double declarations: everytime we read a variable, exec function that checks if it exists in symbol table
- add in for loops to check the condition statement

# Notes
- Q:does my grammar has to be LL(1) , so that it doesnt , recursive gauche  
- A: no it doesn't have to be LL or LR but it must be written in a way to resolve the shift/reduce conflicts

string            \"(\\.|[^\\"])*\"
