/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 128 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_DAT_INT = 4,                    /* DAT_INT  */
  YYSYMBOL_DAT_REAL = 5,                   /* DAT_REAL  */
  YYSYMBOL_DAT_CHAR = 6,                   /* DAT_CHAR  */
  YYSYMBOL_T_TIPO_INT = 7,                 /* T_TIPO_INT  */
  YYSYMBOL_T_TIPO_REAL = 8,                /* T_TIPO_REAL  */
  YYSYMBOL_T_TIPO_CHAR = 9,                /* T_TIPO_CHAR  */
  YYSYMBOL_T_ATRIBUICAO = 10,              /* T_ATRIBUICAO  */
  YYSYMBOL_T_LEIA = 11,                    /* T_LEIA  */
  YYSYMBOL_T_ESCREVE = 12,                 /* T_ESCREVE  */
  YYSYMBOL_T_SE = 13,                      /* T_SE  */
  YYSYMBOL_T_SENAO = 14,                   /* T_SENAO  */
  YYSYMBOL_T_ENQUANTO = 15,                /* T_ENQUANTO  */
  YYSYMBOL_T_FACA = 16,                    /* T_FACA  */
  YYSYMBOL_T_IGUAL = 17,                   /* T_IGUAL  */
  YYSYMBOL_T_MAIOR_IGUAL = 18,             /* T_MAIOR_IGUAL  */
  YYSYMBOL_T_MENOR_IGUAL = 19,             /* T_MENOR_IGUAL  */
  YYSYMBOL_T_MAIOR = 20,                   /* T_MAIOR  */
  YYSYMBOL_T_MENOR = 21,                   /* T_MENOR  */
  YYSYMBOL_T_DIFERENTE = 22,               /* T_DIFERENTE  */
  YYSYMBOL_T_E = 23,                       /* T_E  */
  YYSYMBOL_T_OU = 24,                      /* T_OU  */
  YYSYMBOL_T_NAO = 25,                     /* T_NAO  */
  YYSYMBOL_T_SOMA = 26,                    /* T_SOMA  */
  YYSYMBOL_T_SUB = 27,                     /* T_SUB  */
  YYSYMBOL_T_MULT = 28,                    /* T_MULT  */
  YYSYMBOL_T_DIV = 29,                     /* T_DIV  */
  YYSYMBOL_T_MOD = 30,                     /* T_MOD  */
  YYSYMBOL_T_VIRGULA = 31,                 /* T_VIRGULA  */
  YYSYMBOL_T_PONTO = 32,                   /* T_PONTO  */
  YYSYMBOL_T_DOIS_PONTOS = 33,             /* T_DOIS_PONTOS  */
  YYSYMBOL_T_PONTO_VIRGULA = 34,           /* T_PONTO_VIRGULA  */
  YYSYMBOL_T_ABRE_CHAVE = 35,              /* T_ABRE_CHAVE  */
  YYSYMBOL_T_FECHA_CHAVE = 36,             /* T_FECHA_CHAVE  */
  YYSYMBOL_T_ABRE_PAR = 37,                /* T_ABRE_PAR  */
  YYSYMBOL_T_FECHA_PAR = 38,               /* T_FECHA_PAR  */
  YYSYMBOL_T_INICIO = 39,                  /* T_INICIO  */
  YYSYMBOL_T_FIM = 40,                     /* T_FIM  */
  YYSYMBOL_T_UNARY_MINUS = 41,             /* T_UNARY_MINUS  */
  YYSYMBOL_THEN = 42,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_programa = 44,                  /* programa  */
  YYSYMBOL_lista_comandos = 45,            /* lista_comandos  */
  YYSYMBOL_comando = 46,                   /* comando  */
  YYSYMBOL_tipo = 47,                      /* tipo  */
  YYSYMBOL_declaracao = 48,                /* declaracao  */
  YYSYMBOL_atribuicao = 49,                /* atribuicao  */
  YYSYMBOL_entrada = 50,                   /* entrada  */
  YYSYMBOL_saida = 51,                     /* saida  */
  YYSYMBOL_lista_vars = 52,                /* lista_vars  */
  YYSYMBOL_condicional = 53,               /* condicional  */
  YYSYMBOL_repeticao = 54,                 /* repeticao  */
  YYSYMBOL_expressao = 55                  /* expressao  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 63 "parser.y"

    void registrar_variavel(char* nome) {
        for (int i = 0; i < num_variaveis; i++) {
            if (strcmp(variaveis_declaradas[i], nome) == 0) return;
        }
        if (num_variaveis < MAX_SYMBOLS) {
            variaveis_declaradas[num_variaveis++] = strdup(nome);
        }
    }

#line 229 "parser.tab.c"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   122,   123,   132,   133,   134,   135,   136,
     137,   138,   142,   143,   144,   148,   167,   175,   198,   238,
     242,   251,   256,   264,   269,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "DAT_INT",
  "DAT_REAL", "DAT_CHAR", "T_TIPO_INT", "T_TIPO_REAL", "T_TIPO_CHAR",
  "T_ATRIBUICAO", "T_LEIA", "T_ESCREVE", "T_SE", "T_SENAO", "T_ENQUANTO",
  "T_FACA", "T_IGUAL", "T_MAIOR_IGUAL", "T_MENOR_IGUAL", "T_MAIOR",
  "T_MENOR", "T_DIFERENTE", "T_E", "T_OU", "T_NAO", "T_SOMA", "T_SUB",
  "T_MULT", "T_DIV", "T_MOD", "T_VIRGULA", "T_PONTO", "T_DOIS_PONTOS",
  "T_PONTO_VIRGULA", "T_ABRE_CHAVE", "T_FECHA_CHAVE", "T_ABRE_PAR",
  "T_FECHA_PAR", "T_INICIO", "T_FIM", "T_UNARY_MINUS", "THEN", "$accept",
  "programa", "lista_comandos", "comando", "tipo", "declaracao",
  "atribuicao", "entrada", "saida", "lista_vars", "condicional",
  "repeticao", "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,   -48,     6,     4,   -48,     8,   -48,   -48,   -48,    -2,
      -1,     0,     5,    15,   -48,   -48,   -48,    40,   -48,   -48,
     -48,   -48,   -48,   -48,    42,    53,    57,    42,    42,    60,
      31,   -48,   -48,   -48,   -48,    42,    42,    42,   208,    28,
     -48,   -17,   120,   142,    35,   -48,   257,   257,   164,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,   -48,    36,    68,    38,    39,    41,    42,   -48,
     271,   271,   271,   271,   271,   271,   257,   243,   -26,   -26,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   226,    46,
      78,    42,    59,   -48,   186,    43,    48,   -48,   -48,    89,
     119,   -48,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,    12,    13,    14,     0,
       0,     0,     0,     0,    11,     2,     4,     0,     5,     6,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,    28,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    15,    42,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,    43,
      36,    40,    41,    38,    39,    37,    34,    35,    29,    30,
      31,    32,    33,    17,    20,    18,     3,     3,     0,     0,
       0,     0,    21,    23,     0,     0,     0,     3,     3,     0,
       0,    22,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -47,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    16,    17,    18,    19,    20,    21,    41,
      22,    23,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    43,    59,    60,    61,     1,     4,     5,    46,    47,
      48,     6,     7,     8,    64,     9,    10,    11,    24,    12,
      13,    65,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    25,    26,    27,    14,    89,
      90,    88,    28,    30,    15,    31,    32,    33,    34,     5,
      99,   100,    29,     6,     7,     8,    39,     9,    10,    11,
      40,    12,    13,    44,    94,    45,    63,    35,    68,    36,
      83,    84,    85,    95,    86,     0,    87,     0,    97,    37,
      14,     5,    92,    98,     0,     6,     7,     8,     0,     9,
      10,    11,     5,    12,    13,     0,     6,     7,     8,     0,
       9,    10,    11,     0,    12,    13,     0,     0,     0,     0,
       0,     0,    14,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     5,    14,     0,   101,     6,     7,     8,     0,
       9,    10,    11,     0,    12,    13,     0,    49,    50,    51,
      52,    53,    54,    55,    56,     0,    57,    58,    59,    60,
      61,     0,     0,    14,     0,   102,     0,     0,    66,    49,
      50,    51,    52,    53,    54,    55,    56,     0,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
      67,    49,    50,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,     0,    69,    49,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,    60,    61,     0,     0,     0,
       0,     0,     0,     0,    96,    49,    50,    51,    52,    53,
      54,    55,    56,     0,    57,    58,    59,    60,    61,     0,
       0,     0,    62,    49,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,    60,    61,     0,     0,    91,
      49,    50,    51,    52,    53,    54,    55,     0,     0,    57,
      58,    59,    60,    61,    49,    50,    51,    52,    53,    54,
       0,     0,     0,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     0,     0,    57,    58,    59,
      60,    61
};

static const yytype_int8 yycheck[] =
{
      27,    28,    28,    29,    30,    39,     0,     3,    35,    36,
      37,     7,     8,     9,    31,    11,    12,    13,    10,    15,
      16,    38,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    37,    37,    37,    34,    86,
      87,    68,    37,     3,    40,     3,     4,     5,     6,     3,
      97,    98,    37,     7,     8,     9,     3,    11,    12,    13,
       3,    15,    16,     3,    91,    34,    38,    25,    33,    27,
      34,     3,    34,    14,    35,    -1,    35,    -1,    35,    37,
      34,     3,    36,    35,    -1,     7,     8,     9,    -1,    11,
      12,    13,     3,    15,    16,    -1,     7,     8,     9,    -1,
      11,    12,    13,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    34,    -1,    36,     7,     8,     9,    -1,
      11,    12,    13,    -1,    15,    16,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    -1,    -1,    34,    -1,    36,    -1,    -1,    38,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    34,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    -1,    -1,    33,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    44,    45,     0,     3,     7,     8,     9,    11,
      12,    13,    15,    16,    34,    40,    46,    47,    48,    49,
      50,    51,    53,    54,    10,    37,    37,    37,    37,    37,
       3,     3,     4,     5,     6,    25,    27,    37,    55,     3,
       3,    52,    55,    55,     3,    34,    55,    55,    55,    17,
      18,    19,    20,    21,    22,    23,    24,    26,    27,    28,
      29,    30,    34,    38,    31,    38,    38,    38,    33,    38,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    34,     3,    34,    35,    35,    55,    45,
      45,    33,    36,    36,    55,    14,    38,    35,    35,    45,
      45,    36,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    48,    49,    50,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     5,     5,     1,
       3,     7,    11,     7,    11,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: T_INICIO lista_comandos T_FIM  */
#line 104 "parser.y"
                                  {
        // Ação final: agora temos o corpo do programa completo em $2
        fprintf(saida, "#include <stdio.h>\n\n");
        fprintf(saida, "int main() {\n");

        fprintf(saida, "\n");

        // Escreve o corpo do programa traduzido
        fprintf(saida, "%s", (yyvsp[-1].str));

        fprintf(saida, "\n\treturn 0;\n}\n");
        free((yyvsp[-1].str)); // Libera a string final do corpo do programa
        printf("Arquivo 'output.c' gerado com sucesso!\n");
    }
#line 1299 "parser.tab.c"
    break;

  case 3: /* lista_comandos: %empty  */
#line 122 "parser.y"
    { (yyval.str) = strdup(""); }
#line 1305 "parser.tab.c"
    break;

  case 4: /* lista_comandos: lista_comandos comando  */
#line 123 "parser.y"
                             {
        // Concatena o código do bloco anterior com o novo comando
        (yyval.str) = malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        sprintf((yyval.str), "%s%s", (yyvsp[-1].str), (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str)); // Libera as strings componentes
    }
#line 1316 "parser.tab.c"
    break;

  case 5: /* comando: declaracao  */
#line 132 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1322 "parser.tab.c"
    break;

  case 6: /* comando: atribuicao  */
#line 133 "parser.y"
                        { (yyval.str) = (yyvsp[0].str); }
#line 1328 "parser.tab.c"
    break;

  case 7: /* comando: entrada  */
#line 134 "parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 1334 "parser.tab.c"
    break;

  case 8: /* comando: saida  */
#line 135 "parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 1340 "parser.tab.c"
    break;

  case 9: /* comando: condicional  */
#line 136 "parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 1346 "parser.tab.c"
    break;

  case 10: /* comando: repeticao  */
#line 137 "parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 1352 "parser.tab.c"
    break;

  case 11: /* comando: T_PONTO_VIRGULA  */
#line 138 "parser.y"
                      { (yyval.str) = strdup(";\n"); }
#line 1358 "parser.tab.c"
    break;

  case 12: /* tipo: T_TIPO_INT  */
#line 142 "parser.y"
                   { (yyval.str) = strdup("int"); }
#line 1364 "parser.tab.c"
    break;

  case 13: /* tipo: T_TIPO_REAL  */
#line 143 "parser.y"
                   { (yyval.str) = strdup("float"); }
#line 1370 "parser.tab.c"
    break;

  case 14: /* tipo: T_TIPO_CHAR  */
#line 144 "parser.y"
                   { (yyval.str) = strdup("char"); }
#line 1376 "parser.tab.c"
    break;

  case 15: /* declaracao: tipo VAR T_PONTO_VIRGULA  */
#line 148 "parser.y"
                             {
        // Usa o token original para registrar o tipo
        int tipo_token;
        if (strcmp((yyvsp[-2].str), "int") == 0)
            tipo_token = T_TIPO_INT;
        else if (strcmp((yyvsp[-2].str), "float") == 0)
            tipo_token = T_TIPO_REAL;
        else
            tipo_token = T_TIPO_CHAR;
        declarar_variavel((yyvsp[-1].str), tipo_token);

        // Gera o código C para a declaração
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[-1].str)) + 5);
        sprintf((yyval.str), "\t%s %s;\n", (yyvsp[-2].str), (yyvsp[-1].str));
        free((yyvsp[-2].str)); free((yyvsp[-1].str));
    }
#line 1397 "parser.tab.c"
    break;

  case 16: /* atribuicao: VAR T_ATRIBUICAO expressao T_PONTO_VIRGULA  */
#line 167 "parser.y"
                                               {
        registrar_variavel((yyvsp[-3].str));
        (yyval.str) = malloc(strlen((yyvsp[-3].str)) + strlen(" = ") + strlen((yyvsp[-1].str)) + strlen(";\n") + 5);
        sprintf((yyval.str), "\t%s = %s;\n", (yyvsp[-3].str), (yyvsp[-1].str));
        free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1408 "parser.tab.c"
    break;

  case 17: /* entrada: T_LEIA T_ABRE_PAR VAR T_FECHA_PAR T_PONTO_VIRGULA  */
#line 175 "parser.y"
                                                      {
        struct symbol *s = lookup((yyvsp[-2].str));
        if (!s) {
            yyerror("Erro semantico: Variavel nao declarada");
            (yyval.str) = strdup(""); // Retorna string vazia em caso de erro
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
            (yyval.str) = malloc(strlen("scanf(\"\")") + strlen(formato) + strlen((yyvsp[-2].str)) + 10);
            sprintf((yyval.str), "\tscanf(\"%s\", &%s);\n", formato, (yyvsp[-2].str));
        }
        free((yyvsp[-2].str));
    }
#line 1434 "parser.tab.c"
    break;

  case 18: /* saida: T_ESCREVE T_ABRE_PAR lista_vars T_FECHA_PAR T_PONTO_VIRGULA  */
#line 198 "parser.y"
                                                                {
        char formato[256] = "";
        char argumentos[256] = "";
        char *entrada = strdup((yyvsp[-2].str));
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

        (yyval.str) = malloc(strlen("printf(\"\")") + strlen(formato) + strlen(argumentos) + 10);
        sprintf((yyval.str), "\tprintf(\"%s\", %s);\n", formato, argumentos);
        free((yyvsp[-2].str));
        free(entrada);
    }
#line 1476 "parser.tab.c"
    break;

  case 19: /* lista_vars: VAR  */
#line 238 "parser.y"
        {
        registrar_variavel((yyvsp[0].str));
        (yyval.str) = (yyvsp[0].str);
    }
#line 1485 "parser.tab.c"
    break;

  case 20: /* lista_vars: lista_vars T_VIRGULA VAR  */
#line 242 "parser.y"
                               {
        registrar_variavel((yyvsp[0].str));
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen(", ") + strlen((yyvsp[0].str)) + 1);
        sprintf((yyval.str), "%s, %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1496 "parser.tab.c"
    break;

  case 21: /* condicional: T_SE T_ABRE_PAR expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE  */
#line 251 "parser.y"
                                                                                               {
        (yyval.str) = malloc(strlen("if () {\n\n}\n") + strlen((yyvsp[-4].str)) + strlen((yyvsp[-1].str)) + 5);
        sprintf((yyval.str), "if (%s) {\n%s}\n", (yyvsp[-4].str), (yyvsp[-1].str));
        free((yyvsp[-4].str)); free((yyvsp[-1].str));
    }
#line 1506 "parser.tab.c"
    break;

  case 22: /* condicional: T_SE T_ABRE_PAR expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE T_SENAO T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE  */
#line 256 "parser.y"
                                                                                                                                        {
        (yyval.str) = malloc(strlen("if () {\n\n} else {\n\n}\n") + strlen((yyvsp[-8].str)) + strlen((yyvsp[-5].str)) + strlen((yyvsp[-1].str)) + 5);
        sprintf((yyval.str), "if (%s) {\n%s} else {\n%s}\n", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-1].str));
        free((yyvsp[-8].str)); free((yyvsp[-5].str)); free((yyvsp[-1].str));
    }
#line 1516 "parser.tab.c"
    break;

  case 23: /* repeticao: T_ENQUANTO T_ABRE_PAR expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE  */
#line 264 "parser.y"
                                                                                          {
        (yyval.str) = malloc(strlen("while () {\n\n}\n") + strlen((yyvsp[-4].str)) + strlen((yyvsp[-1].str)) + 5);
        sprintf((yyval.str), "while (%s) {\n%s}\n", (yyvsp[-4].str), (yyvsp[-1].str));
        free((yyvsp[-4].str)); free((yyvsp[-1].str));
    }
#line 1526 "parser.tab.c"
    break;

  case 24: /* repeticao: T_FACA T_ABRE_PAR VAR T_DOIS_PONTOS expressao T_DOIS_PONTOS expressao T_FECHA_PAR T_ABRE_CHAVE lista_comandos T_FECHA_CHAVE  */
#line 269 "parser.y"
                                                                                                                                  {
        // Traduzindo 'faca(i: 1 : 10)' para 'for(i=1; i<=10; i++)'
        registrar_variavel((yyvsp[-8].str));
        (yyval.str) = malloc(strlen("for ( = ; <= ; ++;) {\n\n}\n") + strlen((yyvsp[-8].str))*3 + strlen((yyvsp[-6].str)) + strlen((yyvsp[-4].str)) + strlen((yyvsp[-1].str)) + 5);
        sprintf((yyval.str), "for (%s = %s; %s <= %s; %s++) {\n%s}\n", (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-8].str), (yyvsp[-4].str), (yyvsp[-8].str), (yyvsp[-1].str));
        free((yyvsp[-8].str)); free((yyvsp[-6].str)); free((yyvsp[-4].str)); free((yyvsp[-1].str));
    }
#line 1538 "parser.tab.c"
    break;

  case 25: /* expressao: VAR  */
#line 279 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1544 "parser.tab.c"
    break;

  case 26: /* expressao: DAT_INT  */
#line 280 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1550 "parser.tab.c"
    break;

  case 27: /* expressao: DAT_REAL  */
#line 281 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1556 "parser.tab.c"
    break;

  case 28: /* expressao: DAT_CHAR  */
#line 282 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1562 "parser.tab.c"
    break;

  case 29: /* expressao: expressao T_SOMA expressao  */
#line 283 "parser.y"
                                 { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+4); sprintf((yyval.str), "%s + %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1568 "parser.tab.c"
    break;

  case 30: /* expressao: expressao T_SUB expressao  */
#line 284 "parser.y"
                                 { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+4); sprintf((yyval.str), "%s - %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1574 "parser.tab.c"
    break;

  case 31: /* expressao: expressao T_MULT expressao  */
#line 285 "parser.y"
                                 { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+4); sprintf((yyval.str), "%s * %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1580 "parser.tab.c"
    break;

  case 32: /* expressao: expressao T_DIV expressao  */
#line 286 "parser.y"
                                 { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+4); sprintf((yyval.str), "%s / %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1586 "parser.tab.c"
    break;

  case 33: /* expressao: expressao T_MOD expressao  */
#line 287 "parser.y"
                                 { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+4); sprintf((yyval.str), "%s %% %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1592 "parser.tab.c"
    break;

  case 34: /* expressao: expressao T_E expressao  */
#line 288 "parser.y"
                                 { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+5); sprintf((yyval.str), "%s && %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1598 "parser.tab.c"
    break;

  case 35: /* expressao: expressao T_OU expressao  */
#line 289 "parser.y"
                                 { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+5); sprintf((yyval.str), "%s || %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1604 "parser.tab.c"
    break;

  case 36: /* expressao: expressao T_IGUAL expressao  */
#line 290 "parser.y"
                                  { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+5); sprintf((yyval.str), "%s == %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1610 "parser.tab.c"
    break;

  case 37: /* expressao: expressao T_DIFERENTE expressao  */
#line 291 "parser.y"
                                      { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+5); sprintf((yyval.str), "%s != %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1616 "parser.tab.c"
    break;

  case 38: /* expressao: expressao T_MAIOR expressao  */
#line 292 "parser.y"
                                  { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+4); sprintf((yyval.str), "%s > %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1622 "parser.tab.c"
    break;

  case 39: /* expressao: expressao T_MENOR expressao  */
#line 293 "parser.y"
                                  { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+4); sprintf((yyval.str), "%s < %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1628 "parser.tab.c"
    break;

  case 40: /* expressao: expressao T_MAIOR_IGUAL expressao  */
#line 294 "parser.y"
                                        { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+5); sprintf((yyval.str), "%s >= %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1634 "parser.tab.c"
    break;

  case 41: /* expressao: expressao T_MENOR_IGUAL expressao  */
#line 295 "parser.y"
                                        { (yyval.str) = malloc(strlen((yyvsp[-2].str))+strlen((yyvsp[0].str))+5); sprintf((yyval.str), "%s <= %s", (yyvsp[-2].str), (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); }
#line 1640 "parser.tab.c"
    break;

  case 42: /* expressao: T_NAO expressao  */
#line 296 "parser.y"
                      { (yyval.str) = malloc(strlen((yyvsp[0].str))+3); sprintf((yyval.str), "!%s", (yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1646 "parser.tab.c"
    break;

  case 43: /* expressao: T_ABRE_PAR expressao T_FECHA_PAR  */
#line 297 "parser.y"
                                       { (yyval.str) = malloc(strlen((yyvsp[-1].str))+3); sprintf((yyval.str), "(%s)", (yyvsp[-1].str)); free((yyvsp[-1].str)); }
#line 1652 "parser.tab.c"
    break;

  case 44: /* expressao: T_SUB expressao  */
#line 298 "parser.y"
                                          {
        // Gera o código C para negação, ex: "-(5 + 2)"
        (yyval.str) = malloc(strlen((yyvsp[0].str)) + 4); // Espaço para -(...) e \0
        sprintf((yyval.str), "(-%s)", (yyvsp[0].str)); // Usar parênteses é uma boa prática
        free((yyvsp[0].str));
    }
#line 1663 "parser.tab.c"
    break;


#line 1667 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 304 "parser.y"


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
