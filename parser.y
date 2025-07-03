%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necessário para strcmp, strdup, etc.

// Definição para o tamanho da tabela de símbolos
#define MAX_SYMBOLS 100

// --- Tabela de Símbolos Modificada ---
struct symbol {
    char *name;
    int type; // Armazenará T_TIPO_INT ou T_TIPO_REAL
};

struct symbol symtab[MAX_SYMBOLS];
int sym_count = 0;

void declarar_variavel(char *name, int type) {
    // Verifica se a variável já foi declarada
    for (int i = 0; i < sym_count; i++) {
        if (strcmp(symtab[i].name, name) == 0) {
            perror("Erro semantico: Variavel redeclarada");
            return;
        }
    }
    if (sym_count >= MAX_SYMBOLS) {
        perror("Tabela de simbolos cheia!");
        return;
    }
    symtab[sym_count].name = strdup(name);
    symtab[sym_count].type = type;
    sym_count++;
}

// Função para procurar uma variável e retornar sua struct
struct symbol *lookup(char *sym_name) {
    for (int i = 0; i < sym_count; i++) {
        if (strcmp(symtab[i].name, sym_name) == 0) {
            return &symtab[i];
        }
    }
    return NULL;
}

// Protótipos e variáveis globais
extern int yylex();
extern int yylineno;
extern FILE *yyin;
extern FILE *lista_token;
void yyerror(const char *s);
void registrar_variavel(char* nome);

FILE *saida;
char* variaveis_declaradas[MAX_SYMBOLS];
int num_variaveis = 0;
%}

%union {
    char *str;
}

// Função para registrar variáveis (para declaração no C final)
%code {
    void registrar_variavel(char* nome) {
        for (int i = 0; i < num_variaveis; i++) {
            if (strcmp(variaveis_declaradas[i], nome) == 0) return;
        }
        if (num_variaveis < MAX_SYMBOLS) {
            variaveis_declaradas[num_variaveis++] = strdup(nome);
        }
    }
}

// Definição de todos os tokens e não-terminais que carregam strings
%type <str> declaracao tipo
%token <str> VAR DAT_INT DAT_REAL DAT_CHAR T_TIPO_INT T_TIPO_REAL T_TIPO_CHAR
%token <str> T_ATRIBUICAO T_LEIA T_ESCREVE T_SE T_SENAO T_ENQUANTO T_FACA
%token <str> T_IGUAL T_MAIOR_IGUAL T_MENOR_IGUAL T_MAIOR T_MENOR T_DIFERENTE
%token <str> T_E T_OU T_NAO T_SOMA T_SUB T_MULT T_DIV T_MOD
%token <str> T_VIRGULA T_PONTO T_DOIS_PONTOS T_PONTO_VIRGULA
%token <str> T_ABRE_CHAVE T_FECHA_CHAVE T_ABRE_PAR T_FECHA_PAR
%token <str> T_INICIO T_FIM

// Tipos para os não-terminais
%type <str> programa lista_comandos comando atribuicao entrada saida lista_vars condicional repeticao expressao

// CORREÇÃO: Precedência sem <str>
%right T_ATRIBUICAO
%left  T_OU
%left  T_E
%right T_NAO
%right T_UNARY_MINUS
%nonassoc T_IGUAL T_DIFERENTE T_MAIOR T_MENOR T_MAIOR_IGUAL T_MENOR_IGUAL
%left  T_SOMA T_SUB
%left  T_MULT T_DIV T_MOD
%nonassoc THEN
%nonassoc T_SENAO

%start programa

%%

programa:
    T_INICIO lista_comandos T_FIM {
        // Ação final: agora temos o corpo do programa completo em $2
        fprintf(saida, "#include <stdio.h>\n\n");
        fprintf(saida, "int main() {\n");

        fprintf(saida, "\n");

        // Escreve o corpo do programa traduzido
        fprintf(saida, "%s", $2);

        fprintf(saida, "\n\treturn 0;\n}\n");
        free($2); // Libera a string final do corpo do programa
        printf("Arquivo 'output.c' gerado com sucesso!\n");
    }
    ;

lista_comandos:
    /* Vazio: retorna uma string vazia */
    { $$ = strdup(""); }
    | lista_comandos comando {
        // Concatena o código do bloco anterior com o novo comando
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1); free($2); // Libera as strings componentes
    }
    ;

comando:
    declaracao      { $$ = $1; }
    | atribuicao        { $$ = $1; } // Apenas passa a string gerada para cima
    | entrada         { $$ = $1; }
    | saida           { $$ = $1; }
    | condicional     { $$ = $1; }
    | repeticao       { $$ = $1; }
    | T_PONTO_VIRGULA { $$ = strdup(";\n"); } // Um ';' sozinho é um comando válido
    ;

tipo:
      T_TIPO_INT   { $$ = strdup("int"); }
    | T_TIPO_REAL  { $$ = strdup("float"); }
    | T_TIPO_CHAR  { $$ = strdup("char"); }
    ;

declaracao:
    tipo VAR T_PONTO_VIRGULA {
        // Usa o token original para registrar o tipo
        int tipo_token;
        if (strcmp($1, "int") == 0)
            tipo_token = T_TIPO_INT;
        else if (strcmp($1, "float") == 0)
            tipo_token = T_TIPO_REAL;
        else
            tipo_token = T_TIPO_CHAR;
        declarar_variavel($2, tipo_token);

        // Gera o código C para a declaração
        $$ = malloc(strlen($1) + strlen($2) + 5);
        sprintf($$, "\t%s %s;\n", $1, $2);
        free($1); free($2);
    }
    ;

atribuicao:
    VAR T_ATRIBUICAO expressao T_PONTO_VIRGULA {
        registrar_variavel($1);
        $$ = malloc(strlen($1) + strlen(" = ") + strlen($3) + strlen(";\n") + 5);
        sprintf($$, "\t%s = %s;\n", $1, $3);
        free($1); free($3);
    };

entrada:
    T_LEIA T_ABRE_PAR VAR T_FECHA_PAR T_PONTO_VIRGULA {
        struct symbol *s = lookup($3);
        if (!s) {
            yyerror("Erro semantico: Variavel nao declarada");
            $$ = strdup(""); // Retorna string vazia em caso de erro
        } else {
            // Escolhe o formato (%d ou %f) com base no tipo
            const char* formato;
            if (s->type == T_TIPO_INT)
                formato = "%d";
            else if (s->type == T_TIPO_REAL)
                formato = "%f";
            else if (s->type == T_TIPO_CHAR)
                formato = " %c"; // espaço antes para ignorar \n anterior
            else
                formato = "%d"; // fallback
            $$ = malloc(strlen("scanf(\"\")") + strlen(formato) + strlen($3) + 10);
            sprintf($$, "\tscanf(\"%s\", &%s);\n", formato, $3);
        }
        free($3);
    };

saida:
    T_ESCREVE T_ABRE_PAR lista_vars T_FECHA_PAR T_PONTO_VIRGULA {
        char formato[256] = "";
        char argumentos[256] = "";
        char *entrada = strdup($3);
        char *token = strtok(entrada, ", ");

        int first = 1;
        while (token != NULL) {
            struct symbol *s = lookup(token);
            if (!s) {
                yyerror("Erro semantico: Variavel nao declarada");
            } else {
                // Adiciona o formato correto
                if (s->type == T_TIPO_INT)
                    strcat(formato, "%d ");
                else if (s->type == T_TIPO_CHAR)
                    strcat(formato, "%c ");
                else if (s->type == T_TIPO_REAL)
                    strcat(formato, "%.2f ");
                else
                    strcat(formato, "? ");
                
                // Concatena o nome da variável
                if (!first) strcat(argumentos, ", ");
                strcat(argumentos, token);
                first = 0;
            }
            token = strtok(NULL, ", ");
        }

        strcat(formato, "\\n");

        $$ = malloc(strlen("printf(\"\")") + strlen(formato) + strlen(argumentos) + 10);
        sprintf($$, "\tprintf(\"%s\", %s);\n", formato, argumentos);
        free($3);
        free(entrada);
    };


lista_vars:
    VAR {
        registrar_variavel($1);
        $$ = $1;
    }
    | lista_vars T_VIRGULA VAR {
        registrar_variavel($3);
        $$ = malloc(strlen($1) + strlen(", ") + strlen($3) + 1);
        sprintf($$, "%s, %s", $1, $3);
        free($1); free($3);
    }
    ; 

condicional:
    T_SE T_ABRE_PAR expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE %prec THEN {
        $$ = malloc(strlen("if () {\n\n}\n") + strlen($3) + strlen($6) + 5);
        sprintf($$, "if (%s) {\n%s}\n", $3, $6);
        free($3); free($6);
    }
    | T_SE T_ABRE_PAR expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE T_SENAO T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE {
        $$ = malloc(strlen("if () {\n\n} else {\n\n}\n") + strlen($3) + strlen($6) + strlen($10) + 5);
        sprintf($$, "if (%s) {\n%s} else {\n%s}\n", $3, $6, $10);
        free($3); free($6); free($10);
    }
    ;

repeticao:
    T_ENQUANTO T_ABRE_PAR expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE {
        $$ = malloc(strlen("while () {\n\n}\n") + strlen($3) + strlen($6) + 5);
        sprintf($$, "while (%s) {\n%s}\n", $3, $6);
        free($3); free($6);
    }
    | T_FACA T_ABRE_PAR VAR T_DOIS_PONTOS expressao T_DOIS_PONTOS expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE {
        // Traduzindo 'faca(i: 1 : 10)' para 'for(i=1; i<=10; i++)'
        registrar_variavel($3);
        $$ = malloc(strlen("for ( = ; <= ; ++;) {\n\n}\n") + strlen($3)*3 + strlen($5) + strlen($7) + strlen($10) + 5);
        sprintf($$, "for (%s = %s; %s <= %s; %s++) {\n%s}\n", $3, $5, $3, $7, $3, $10);
        free($3); free($5); free($7); free($10);
    }
    ;

expressao:
    VAR      { $$ = $1; }
    | DAT_INT  { $$ = $1; }
    | DAT_REAL { $$ = $1; }
    | DAT_CHAR { $$ = $1; }
    | expressao T_SOMA expressao { $$ = malloc(strlen($1)+strlen($3)+4); sprintf($$, "%s + %s", $1, $3); free($1); free($3); }
    | expressao T_SUB expressao  { $$ = malloc(strlen($1)+strlen($3)+4); sprintf($$, "%s - %s", $1, $3); free($1); free($3); }
    | expressao T_MULT expressao { $$ = malloc(strlen($1)+strlen($3)+4); sprintf($$, "%s * %s", $1, $3); free($1); free($3); }
    | expressao T_DIV expressao  { $$ = malloc(strlen($1)+strlen($3)+4); sprintf($$, "%s / %s", $1, $3); free($1); free($3); }
    | expressao T_MOD expressao  { $$ = malloc(strlen($1)+strlen($3)+4); sprintf($$, "%s %% %s", $1, $3); free($1); free($3); }
    | expressao T_E expressao    { $$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s && %s", $1, $3); free($1); free($3); }
    | expressao T_OU expressao   { $$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s || %s", $1, $3); free($1); free($3); }
    | expressao T_IGUAL expressao { $$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s == %s", $1, $3); free($1); free($3); }
    | expressao T_DIFERENTE expressao { $$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s != %s", $1, $3); free($1); free($3); }
    | expressao T_MAIOR expressao { $$ = malloc(strlen($1)+strlen($3)+4); sprintf($$, "%s > %s", $1, $3); free($1); free($3); }
    | expressao T_MENOR expressao { $$ = malloc(strlen($1)+strlen($3)+4); sprintf($$, "%s < %s", $1, $3); free($1); free($3); }
    | expressao T_MAIOR_IGUAL expressao { $$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s >= %s", $1, $3); free($1); free($3); }
    | expressao T_MENOR_IGUAL expressao { $$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s <= %s", $1, $3); free($1); free($3); }
    | T_NAO expressao { $$ = malloc(strlen($2)+3); sprintf($$, "!%s", $2); free($2); }
    | T_ABRE_PAR expressao T_FECHA_PAR { $$ = malloc(strlen($2)+3); sprintf($$, "(%s)", $2); free($2); }
    | T_SUB expressao %prec T_UNARY_MINUS {
        // Gera o código C para negação, ex: "-(5 + 2)"
        $$ = malloc(strlen($2) + 4); // Espaço para -(...) e \0
        sprintf($$, "(-%s)", $2); // Usar parênteses é uma boa prática
        free($2);
    }
%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de Sintaxe na Linha %d: %s\n", yylineno, s);
}

// ...
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }
    yyin = file;

    saida = fopen("output.c", "w");
    if (!saida) {
        perror("Erro ao criar output.c");
        fclose(file);
        return 1;
    }
    lista_token = fopen("lista_tokens.txt", "w");
    if(!lista_token){
        perror("Erro ao criar a lista de tokens usados");
        return 1;
    }
    // A ação na regra 'programa' fará todo o trabalho de escrita.
    yyparse();

    fclose(lista_token);
    fclose(file);
    fclose(saida);

    return 0;
}