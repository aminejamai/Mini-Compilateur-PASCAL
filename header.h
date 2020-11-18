#ifndef HEADER_H_   /* Include guard */
#define HEADER_H_

typedef enum{
    ID_TOKEN, NUM_TOKEN, PV_TOKEN, PT_TOKEN, PLUS_TOKEN, MOINS_TOKEN,
    MULT_TOKEN, DIV_TOKEN, VIR_TOKEN, AFF_TOKEN, INF_TOKEN, INFEG_TOKEN,
    SUP_TOKEN, SUPEG_TOKEN, DIFF_TOKEN, PO_TOKEN, PF_TOKEN, FIN_TOKEN,
    PROGRAM_TOKEN, CONST_TOKEN, VAR_TOKEN, BEGIN_TOKEN, END_TOKEN, IF_TOKEN,
    THEN_TOKEN, WHILE_TOKEN, DO_TOKEN, READ_TOKEN, WRITE_TOKEN, EG_TOKEN, ERREUR_TOKEN
}CODES_LEX;

int lireMot(FILE*, char);
int estMotCle(char* );
int lireNum(FILE*, char);
int lireCaractereSpec(FILE*, char);
int espace(char);
char* affichage(int);


#endif // HEADER_H_