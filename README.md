# ANALYSEUR LYXICAL PASCAL
 Travail fait pour le TP du module compilation, qui consiste a realiser un analyseur lyxicale du langage PASCAL. 

# GRAMMAIRE :

PROGRAM ::= program ID ;BLOCK .

BLOCK   ::= CONSTS VARS INSTS 

CONSTS  ::= const ID = NUM ;{ ID =NUM ;} | epsilon 

VARS    ::= var ID { ,ID } ;| epsilon

INSTS   ::= begin INST { ;INST } end

INST    ::= INSTS | AFFEC | SI | TANTQUE | ECRIRE | LIRE | epsilon 

AFFEC   ::= ID := EXPR 

SI      ::= if COND then INST 

TANTQUE ::= while COND do INST 

ECRIRE  ::= write(EXPR { ,EXPR } ) 

LIRE    ::= read(ID { ,ID } )

COND    ::= EXPR [=| <>| < | >| <=| >=] EXPR

EXPR    ::= TERM { [+| -] TERM } 

TERM    ::= FACT {[*| /] FACT }

FACT    ::= ID | NUM | (EXPR )
