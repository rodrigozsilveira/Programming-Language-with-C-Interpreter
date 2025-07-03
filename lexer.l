%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h" // Arquivo gerado pelo Bison com as definições dos tokens

FILE *lista_token;

%}

%option yylineno
%option noyywrap

letra   [a-zA-Z_]
digito  [0-9]

%%

[ \t\r\n]+        { /* Ignora espaços, tabs e quebras de linha */ }

"inicio"          {
                    fprintf(lista_token, "%s -> T_INICIO\n", yytext);
                    return T_INICIO;
                  }
"fim"             {
                    fprintf(lista_token, "%s -> T_FIM\n", yytext);
                    return T_FIM;
                  }
"leia"            {
                    fprintf(lista_token, "%s -> T_LEIA\n", yytext);
                    return T_LEIA;
                  }
"escreve"         {
                    fprintf(lista_token, "%s -> T_ESCREVE\n", yytext);
                    return T_ESCREVE;
                  }
"se"              {
                    fprintf(lista_token, "%s -> T_SE\n", yytext);
                    return T_SE;
                  }
"senao"           {
                    fprintf(lista_token, "%s -> T_SENAO\n", yytext);
                    return T_SENAO;
                  }
"enquanto"        {
                    fprintf(lista_token, "%s -> T_ENQUANTO\n", yytext);
                    return T_ENQUANTO;
                  }
"faca"            {
                    fprintf(lista_token, "%s -> T_FACA\n", yytext);
                    return T_FACA;
                  }
"inteiro"         {
                    fprintf(lista_token, "%s -> T_TIPO_INT\n", yytext);
                    return T_TIPO_INT;
                  }
"real"            {
                    fprintf(lista_token, "%s -> T_TIPO_REAL\n", yytext);
                    return T_TIPO_REAL;
                  }
"caracter"        {
                    fprintf(lista_token, "%s -> T_TIPO_CHAR\n", yytext);
                    return T_TIPO_CHAR;
                  }

"AND"             {
                    fprintf(lista_token, "%s -> T_E\n", yytext);
                    return T_E;
                  }
"OR"              {
                    fprintf(lista_token, "%s -> T_OU\n", yytext);
                    return T_OU;
                  }
"NOT"             {
                    fprintf(lista_token, "%s -> T_NAO\n", yytext);
                    return T_NAO;
                  }
">="              {
                    fprintf(lista_token, "%s -> T_MAIOR_IGUAL\n", yytext);
                    return T_MAIOR_IGUAL;
                  }
"<="              {
                    fprintf(lista_token, "%s -> T_MENOR_IGUAL\n", yytext);
                    return T_MENOR_IGUAL;
                  }
"!!"              {
                    fprintf(lista_token, "%s -> T_DIFERENTE\n", yytext);
                    return T_DIFERENTE;
                  }
"="               {
                    fprintf(lista_token, "%s -> T_IGUAL\n", yytext);
                    return T_IGUAL;
                  }
">"               {
                    fprintf(lista_token, "%s -> T_MAIOR\n", yytext);
                    return T_MAIOR;
                  }
"<"               {
                    fprintf(lista_token, "%s -> T_MENOR\n", yytext);
                    return T_MENOR;
                  }

"<<"              {
                    fprintf(lista_token, "%s -> T_ATRIBUICAO\n", yytext);
                    return T_ATRIBUICAO;
                  }

"+"               {
                    fprintf(lista_token, "%s -> T_SOMA\n", yytext);
                    return T_SOMA;
                  }
"-"               {
                    fprintf(lista_token, "%s -> T_SUB\n", yytext);
                    return T_SUB;
                  }
"*"               {
                    fprintf(lista_token, "%s -> T_MULT\n", yytext);
                    return T_MULT;
                  }
"/"               {
                    fprintf(lista_token, "%s -> T_DIV\n", yytext);
                    return T_DIV;
                  }
"md"              {
                    fprintf(lista_token, "%s -> T_MOD\n", yytext);
                    return T_MOD;
                  }

","               {
                    fprintf(lista_token, "%s -> T_VIRGULA\n", yytext);
                    return T_VIRGULA;
                  }
"."               {
                    fprintf(lista_token, "%s -> T_PONTO\n", yytext);
                    return T_PONTO;
                  }
":"               {
                    fprintf(lista_token, "%s -> T_DOIS_PONTOS\n", yytext);
                    return T_DOIS_PONTOS;
                  }
";"               {
                    fprintf(lista_token, "%s -> T_PONTO_VIRGULA\n", yytext);
                    return T_PONTO_VIRGULA;
                  }
"{"               {
                    fprintf(lista_token, "%s -> T_ABRE_CHAVE\n", yytext);
                    return T_ABRE_CHAVE;
                  }
"}"               {
                    fprintf(lista_token, "%s -> T_FECHA_CHAVE\n", yytext);
                    return T_FECHA_CHAVE;
                  }
"("               {
                    fprintf(lista_token, "%s -> T_ABRE_PAR\n", yytext);
                    return T_ABRE_PAR;
                  }
")"               {
                    fprintf(lista_token, "%s -> T_FECHA_PAR\n", yytext);
                    return T_FECHA_PAR;
                  }

{digito}+"."{digito}+ {
                    yylval.str = strdup(yytext);
                    fprintf(lista_token, "%s -> DAT_REAL\n", yytext);
                    return DAT_REAL;
                  }

{digito}+ {
                    yylval.str = strdup(yytext);
                    fprintf(lista_token, "%s -> DAT_INT\n", yytext);
                    return DAT_INT;
                  }

"\""({letra}|{digito})"\"" {
                    yylval.str = strdup(yytext);
                    fprintf(lista_token, "%s -> DAT_CHAR\n", yytext);
                    return DAT_CHAR;
                  }

{letra}({letra}|{digito})* {
                    yylval.str = strdup(yytext);
                    fprintf(lista_token, "%s -> VAR\n", yytext);
                    return VAR;
                  }


.                 { printf("Erro Léxico: Caractere inválido na linha %d: '%s'\n", yylineno, yytext); }

%%