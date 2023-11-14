
# Notes
### DONE:
- comments
- seperate to flex file and bison file
### TODO
- add in for loops to check the condition statement
- add more depth to for loop counter
- use yyleng
- learn yylval
routine symantique ; check symboles table
semantic 5/0 type float 
add table symboles , idfs no repition ; check presence before insertion ; afficher table symbole at the end (this is done normally in C)
fonction recherch ; insertion ; afficher
- remove column count
use fopen to read from text file

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
