# Programming Language Project "C--"
This language was based in c, we used **Bison** as the parser (syntax analyzer) and **FLEX** as the lexer (lexical analyzer).

## Dependencies

```
Flex : https://gnuwin32.sourceforge.net/packages/flex.htm
Bison : https://gnuwin32.sourceforge.net/packages/bison.htm
```
Make sure you have a C compiler installed.

## Program Execution (powershell)

There are 3 example programs in (C--) already, but to run your own you have to:

 * CCreates parser and lex -> run this if changes are made to lexer.l or parser.y.
```powershell
flex lexer.l
bison -d parser.y
```

 * Creates interpreter -> skippable if no changes were made.
```powershell
gcc -o interpreter parser.tab.c lex.yy.c
```
 * Runs the interpreter for desired txt example code, then compiles the translated code and runs it.
```powershell
.\interpreter example.txt
gcc output.c -o program
program.exe
```
 * The Interpreter can translate code like this:
```powershell
inicio
inteiro x;
x << 10;
escreve(x);
fim
```
```powershell
#include <stdio.h>

int main() {

	int x;
	x = 10;
	printf("%d \n", x);

	return 0;
}
```
 * It also generates a .txt file containing all tokens used in the example:
```powershell
inicio -> T_INICIO
inteiro -> T_TIPO_INT
x -> VAR
; -> T_PONTO_VIRGULA
x -> VAR
<< -> T_ATRIBUICAO
10 -> DAT_INT
; -> T_PONTO_VIRGULA
escreve -> T_ESCREVE
( -> T_ABRE_PAR
x -> VAR
) -> T_FECHA_PAR
; -> T_PONTO_VIRGULA
fim -> T_FIM
```
## Development

Project developed for Compilers (ECOM06A) class, by **Rodrigo Zaparoli Silveira** and **Luis Felipe de Moraes**.
