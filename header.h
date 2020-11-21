#ifndef HEADER_H_   /* Include guard */
#define HEADER_H_

typedef enum{
    ID_TOKEN, NUM_TOKEN, PV_TOKEN, PT_TOKEN, PLUS_TOKEN, MOINS_TOKEN,
    MULT_TOKEN, DIV_TOKEN, VIR_TOKEN, AFF_TOKEN, INF_TOKEN, INFEG_TOKEN,
    SUP_TOKEN, SUPEG_TOKEN, DIFF_TOKEN, PO_TOKEN, PF_TOKEN, FIN_TOKEN,
    PROGRAM_TOKEN, CONST_TOKEN, VAR_TOKEN, BEGIN_TOKEN, END_TOKEN, IF_TOKEN,
    THEN_TOKEN, WHILE_TOKEN, DO_TOKEN, READ_TOKEN, WRITE_TOKEN, EG_TOKEN, ERREUR_TOKEN
}CODES_LEX;

typedef enum{
    ID_ERREUR, NUM_ERREUR, PV_ERREUR, PT_ERREUR, PLUS_ERREUR, MOINS_ERREUR,
    MULT_ERREUR, DIV_ERREUR, VIR_ERREUR, AFF_ERREUR, INF_ERREUR, INFEG_ERREUR,
    SUP_ERREUR, SUPEG_ERREUR, DIFF_ERREUR, PO_ERREUR, PF_ERREUR, FIN_ERREUR,
    PROGRAM_ERREUR, CONST_ERREUR, VAR_ERREUR, BEGIN_ERREUR, END_ERREUR, IF_ERREUR,
    THEN_ERREUR, WHILE_ERREUR, DO_ERREUR, READ_ERREUR, WRITE_ERREUR, EG_ERREUR, INCONNU_ERREUR
}ERR;

typedef struct tokens{
    int code;
    int indice;
    struct tokens* next;
}Token;

int lireMot(FILE*, char);
int estMotCle(char* );
int lireNum(FILE*, char);
int lireCaractereSpec(FILE*, char);
int espace(char);
char* affichage(int);

Token* inserer(Token*, int);
char* genererErreur(int);

void PROGRAM(Token* );
Token* BLOCK(Token* );
Token* CONSTS(Token* );
Token* VAR(Token* );
Token* INSTS(Token* );
Token* INST(Token* );

Token* AFFECT(Token* );
Token* SI(Token* );
Token* TANTQUE(Token* );
Token* ECRIRE(Token* );
Token* LIRE(Token* );
Token* EXPR(Token* );
Token* TERM(Token* );
Token* FACT(Token* );
Token* COND(Token* );

#endif // HEADER_H_