
# Notes
### DONE:

- comments
- seperate to flex file and bison file
- learn yylval
- add more depth to for loop counter
routine symantique ; check symboles table
semantic 5/0 type float 
add table symboles , idfs no repition ; check presence before insertion ; afficher table symbole at the end (this is done normally in C)
fonction recherch ; insertion ; afficher
- remove column count
use fopen to read from text file
- Q:does my grammar has to be LL(1) , so that it doesnt , recursive gauche  
- A: no it doesn't have to be LL or LR but it must be written in a way to resolve the shift/reduce conflicts
### TODO
- resolve the last conflicts
- add bool to 
- can i remove the 40 shift/reduce conflicts by optimizing the grammar
- check cours genration gauche , droite
- add precedence between operators + - * 
- can bison print syntax tree ?? ask gpt
- add constant (yes/no) to symbol table
- ask chatgot do i add sym table .c and .h when compiling flex and bison
- remove comment prints
- check what does the point . rule d
- remove current_line variable
- remove printing every time parenth is opened/closed
- add ALL CAPS letter for ID ,
- improve IDs RegEx
- double declarations: everytime we read a variable, exec function that checks if it exists in symbol table
- add in for loops to check the condition statement

#### on assign
- a space between IDs should be optional (use ? op)

####
INSTRUC     ({SVAR}|{CST}|{MULTI_SVAR})";"
- add for and if 

### Tests:
```
CONST INT bism=33;
INT A83_n,app,reste;
FLOAT Kms,LL6,Jn5;
BOOL reponse;
// correct
BEGIN x:=10; END
BEGIN if(x>0){x++;} END
// incorrect // 
BEGIN x=10; END 
BEGIN if(x>0(){x++;} END

```
- fix nibba_ being recognized as an ID, IDs shouldnt have _ in the end
- IDs length should be <10


string            \"(\\.|[^\\"])*\"
