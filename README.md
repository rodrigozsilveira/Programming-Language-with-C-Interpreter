# Programming Language Project "C--"
This language was based in c, we used **Bison** as the parser (syntax analyzer) and **FLEX** as the lexer (lexical analyzer).

## Dependencies

```
Flex : https://gnuwin32.sourceforge.net/packages/flex.htm
Bison : https://gnuwin32.sourceforge.net/packages/bison.htm
```
Make sure you have a C compiler installed.

## Program Execution

There are 3 example programs in (C--) already, but to run your own you have to:

 * Creates interpreter
```powershell
gcc -o interpreter parser.tab.c lex.yy.c
```
 * Runs the interpreter, compiles the translated code and runs it.
```powershell
.\interpreter example.txt
gcc output.c -o program
program.exe
```

## Development

Project developed for Compilers (ECOM06A) class, by **Rodrigo Zaparoli Silveira** and **Luis Felipe de Moraes**.
