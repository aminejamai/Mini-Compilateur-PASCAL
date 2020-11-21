#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

// Lire mot :
int lireMot(FILE* monFichier, char ch){
    char token[20];
    token[0] = ch;
    char car;
    int i = 1;

    while ((car = fgetc(monFichier)) != EOF) {
        if (isalpha(car) || isdigit(car)) {
            token[i]= car;
            i++;
        }
        else{
            break;
        }
    }
    token[i]='\0';
    // printf("token : %s", token);
    // retour au caractere qui precede ch
    fseek(monFichier, -1L, SEEK_CUR);

    // Verifier s'il est un mot cle
    int nv = estMotCle(token);

    return nv;
}


// 
int estMotCle(char* token){
    if(strcmp(token, "program") == 0) return PROGRAM_TOKEN;
    if(strcmp(token, "const") == 0) return CONST_TOKEN;
    if(strcmp(token, "var") == 0) return VAR_TOKEN;
    if(strcmp(token, "begin") == 0) return BEGIN_TOKEN;
    if(strcmp(token, "end") == 0) return END_TOKEN;
    if(strcmp(token, "if") == 0) return IF_TOKEN;
    if(strcmp(token, "then") == 0) return THEN_TOKEN;
    if(strcmp(token, "while") == 0) return WHILE_TOKEN;
    if(strcmp(token, "Do") == 0) return DO_TOKEN;
    if(strcmp(token, "read") == 0) return READ_TOKEN;
    if(strcmp(token, "write") == 0) return WRITE_TOKEN;
         
    return ID_TOKEN;
}

// Lire num :
int lireNum(FILE* monFichier, char ch){
    char token[20];
    token[0] = ch;
    char car;
    int i = 1;

    while ((car = fgetc(monFichier)) != EOF) {
        if (isdigit(car)) {
            token[i]= car;
            i++;
        }
        else{
            break;
        }
    }
    token[i]='\0';
    // printf("token : %s", token);
    // retour au caractere qui precede ch
    fseek(monFichier, -1L, SEEK_CUR);

    return NUM_TOKEN;
}

// Lire caractere speciaux
int lireCaractereSpec(FILE* monFichier, char ch){
    if(ch == ';') return PV_TOKEN;
    if(ch == '.') return PT_TOKEN;
    if(ch == '+') return PLUS_TOKEN;
    if(ch == '*') return MULT_TOKEN;
    if(ch == '/') return DIV_TOKEN;
    if(ch == ',') return VIR_TOKEN;
    if(ch == '(') return PO_TOKEN;
    if(ch == ')') return PF_TOKEN;
    if(ch == '=') return EG_TOKEN;
    if (ch == '<')
    {
        char car;
        car = fgetc(monFichier);
        if(car == '>') return DIFF_TOKEN;
        if(car == '=') return INFEG_TOKEN;
        fseek(monFichier, -1L, SEEK_CUR);
        return INF_TOKEN;
    }
    if(ch == ':'){
        char car;
        car = fgetc(monFichier);
        if(car == '=') return AFF_TOKEN;
    }
    
    return ERREUR_TOKEN;
}

// Espace :
int espace(char ch){
    if(ch == ' ') return 1;
    if(ch == '\t') return 1;
    if(ch == '\n') return 1;
    return 0;
}

// Affichage :
char* affichage(int i){
    switch (i)
    {
        case 0: return "ID_TOKEN";
        case 1: return "NUM_TOKEN";
        case 2: return "PV_TOKEN";
        case 3: return "PT_TOKEN";
        case 4: return "PLUS_TOKEN";
        case 5: return "MOINS_TOKEN";
        case 6: return "MULT_TOKEN";
        case 7: return "DIV_TOKEN";
        case 8: return "VIR_TOKEN";
        case 9: return "AFF_TOKEN";
        case 10: return "INF_TOKEN";
        case 11: return "INFEG_TOKEN";
        case 12: return "SUP_TOKEN";
        case 13: return "SUPEG_TOKEN";
        case 14: return "DIFF_TOKEN";
        case 15: return "PO_TOKEN";
        case 16: return "PF_TOKEN";
        case 17: return "FIN_TOKEN";
        case 18: return "PROGRAM_TOKEN";
        case 19: return "CONST_TOKEN";
        case 20: return "VAR_TOKEN";
        case 21: return "BEGIN_TOKEN";
        case 22: return "END_TOKEN";
        case 23: return "IF_TOKEN";
        case 24: return "THEN_TOKEN";
        case 25: return "WHILE_TOKEN";
        case 26: return "DO_TOKEN";
        case 27: return "READ_TOKEN";
        case 28: return "WRITE_TOKEN";
        case 29: return "EG_TOKEN";
        default:
            return "ERREUR_TOKEN";
    }
    return "ERREUR_TOKEN";
}


// Inserer dans la liste : 
Token* inserer(Token* token, int code){
    
    if (token == NULL)
    {
        token = (Token*)malloc(sizeof(Token));
        token->code = code;
        token->indice = 0;
        token->next = NULL;
        return token;
    }

    int indice=0; // pour recuperer l'indice du dernier element
    Token* nvToken = (Token*)malloc(sizeof(Token));
    nvToken->code = code;
    nvToken->next = NULL;

    Token* p = token;
    while (p->next != NULL)
    {
        p = p->next;
        indice = p->indice;
    }
    nvToken->indice = indice+1;
    p->next = nvToken;
    
    return token;
}

// Affichage de la liste :
void afficherListe(Token* token){
    Token* p = token;
    if (token == NULL)
    {
        printf("Pas de token !! \n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%s \n", affichage(p->code));
            p = p->next;
        }
        
    }
}

// Generer Erreur :
char* genererErreur(int code){
    switch (code)
    {
        case 0: return "ID_ERREUR";
        case 1: return "NUM_ERREUR";
        case 2: return "PV_ERREUR";
        case 3: return "PT_ERREUR";
        case 4: return "PLUS_ERREUR";
        case 5: return "MOINS_ERREUR";
        case 6: return "MULT_ERREUR";
        case 7: return "DIV_ERREUR";
        case 8: return "VIR_ERREUR";
        case 9: return "AFF_ERREUR";
        case 10: return "INF_ERREUR";
        case 11: return "INFEG_ERREUR";
        case 12: return "SUP_ERREUR";
        case 13: return "SUPEG_ERREUR";
        case 14: return "DIFF_ERREUR";
        case 15: return "PO_ERREUR";
        case 16: return "PF_ERREUR";
        case 17: return "FIN_ERREUR";
        case 18: return "PROGRAM_ERREUR";
        case 19: return "CONST_ERREUR";
        case 20: return "VAR_ERREUR";
        case 21: return "BEGIN_ERREUR";
        case 22: return "END_ERREUR";
        case 23: return "IF_ERREUR";
        case 24: return "THEN_ERREUR";
        case 25: return "WHILE_ERREUR";
        case 26: return "DO_ERREUR";
        case 27: return "READ_ERREUR";
        case 28: return "WRITE_ERREUR";
        case 29: return "EG_ERREUR";
        default:
            return "INCONNU_ERREUR";
    }
    return "ERREUR";
}

// Program fonction: Analyse syntaxique
void PROGRAM(Token* token){
    if (token == NULL)
    {
        printf("Ooops pas de resultat pour faire analyse syntaxique !");
        exit(0);
    }
    
    Token* p = token;
    switch(p->code){
          case PROGRAM_TOKEN : 
                              p = p->next;
                              if(p->code == ID_TOKEN){
                                    p = p->next;
                                    if(p->code == PV_TOKEN){
                                            p = BLOCK(p->next);
                                            if(p->code == PT_TOKEN)
                                                    p = p->next;
                                            else
                                                printf("%s \n",genererErreur(PT_ERREUR));
                                    }
                                    else 
                                        printf("%s \n",genererErreur(PV_ERREUR));
                              }
                              else 
                                  printf("%s \n",genererErreur(ID_ERREUR));
                              break;
          default : 
                    printf("%s \n", genererErreur(PROGRAM_ERREUR));                              
    }
    if(p->code != FIN_TOKEN)
        printf("%s \n", genererErreur(FIN_ERREUR));
}

// code BLOCK()
Token* BLOCK(Token* token){
      Token* p = token;
      p = CONSTS(p);
      p = VAR(p);
      p = INSTS(p);
      return p;
}

// code de CONST()
Token* CONSTS(Token* token){
      Token* p = token;
      switch(p->code){
          case CONST_TOKEN : p = p->next;
                            if(p->code == ID_TOKEN){
                                p = p->next;
                                if(p->code == EG_TOKEN){
                                    p = p->next;
                                    if(p->code == NUM_TOKEN){
                                        p = p->next;
                                        if (p->code == PV_TOKEN){
                                            p = p->next;
                                            while (p->code == ID_TOKEN){
                                                p = p->next;
                                                if(p->code == EG_TOKEN){
                                                    p = p->next;
                                                    if(p->code == NUM_TOKEN){
                                                        p = p->next;
                                                        if (p->code == PV_TOKEN)
                                                            p = p->next;
                                                        else 
                                                            printf("%s \n", genererErreur(PV_ERREUR));
                                                    }
                                                    else printf("%s \n", genererErreur(NUM_ERREUR));
                                                }
                                                else printf("%s \n", genererErreur(EG_ERREUR));
                                            }
                                        }
                                        else printf("%s \n", genererErreur(PV_ERREUR));
                                    }
                                    else printf("%s \n", genererErreur(NUM_ERREUR));
                                }
                                else printf("%s \n", genererErreur(EG_ERREUR));
                            }
                            else printf("%s \n", genererErreur(ID_ERREUR));
                            break;
            case VAR_TOKEN : break;
            case BEGIN_TOKEN : break;
            default :
                    printf("%s \n", genererErreur(CONST_ERREUR));
      }  
      return p;
}

// code du VAR() :
Token* VAR(Token* token){
    Token* p = token;
    switch(p->code){
        case VAR_TOKEN :p = p->next;
                        if(p->code == ID_TOKEN){
                            p = p->next;
                            while (p->code == VIR_TOKEN){
                                p = p->next;
                                if(p->code == ID_TOKEN){
                                    p = p->next;
                                }
                                else {
                                    printf("%s \n", genererErreur(ID_ERREUR));
                                    p = p->next;
                                }
                            }
                            if (p->code == PV_TOKEN){
                                p = p->next;
                            }
                            else {
                                printf("%s \n", genererErreur(PV_ERREUR));
                                p = p->next;
                            }
                        }
                        else {
                                printf("%s \n", genererErreur(ID_ERREUR));
                            p = p->next;
                        }
                        break;
        case BEGIN_TOKEN : break;
        default : printf("%s \n", genererErreur(INCONNU_ERREUR));
    }
    return p;
}

// code INSTS()
Token* INSTS(Token* token){
    Token* p = token;
    switch (p->code){
    case BEGIN_TOKEN:
        p = INST(p->next);
        while (p->code == PV_TOKEN){
            p = INST(p->next);
        }
        if(p->code == END_TOKEN)
            p = p->next;
        break;
    
    default: printf("%s \n", genererErreur(BEGIN_ERREUR));
        break;
    }
    return p;
}

// code INST
Token* INST(Token* token){
    Token* p = token;
    switch (p->code)
    {
    case BEGIN_TOKEN:
        p = INSTS(p);
        break;
    
    case ID_TOKEN:
        p = AFFECT(p->next);
        break;

    case IF_TOKEN:
        p = SI(p->next);
        break;

    case WHILE_TOKEN:
        p = TANTQUE(p->next);
        break;

    case WRITE_TOKEN:
        p = ECRIRE(p->next);
        break;
    
    case READ_TOKEN:
        p = LIRE(p->next);
        break;
    
    case END_TOKEN : break;
    default:
        printf("INSTRUCTION_ERREUR \n");
        break;
    }
    return p;
}

// AFFECT()
Token* AFFECT(Token* token){
    Token* p = token;
    switch (p->code)
    {
    case AFF_TOKEN:
        p = EXPR(p->next);
        break;
    
    default:
        printf("%s \n", genererErreur(AFF_ERREUR));
        break;
    }
    return p;
}

// EXPR()
Token* EXPR(Token* token){
    Token* p = token;
    p = TERM(p);
    if((p->code == PLUS_TOKEN) || (p->code == MOINS_TOKEN))
        p = TERM(p->next);

    return p;
}

// TERM()
Token* TERM(Token* token){
    Token* p = token;
    p = FACT(p);
    if((p->code == MULT_TOKEN) || (p->code == DIV_TOKEN))
        p = FACT(p->next);

    return p;
}

// FACT()
Token* FACT(Token* token){
    Token* p = token;
    switch (p->code)
    {
    case ID_TOKEN:
        p = p->next;
        break;
    
    case NUM_TOKEN:
        p = p->next;
        break;

    case PO_TOKEN:
        p = EXPR(p->next);
        if (p->code == PF_TOKEN)
            p = p->next;
        else printf("%s \n", genererErreur(PF_ERREUR));
        break;    

    default:
        printf("FACTEUR_ERREUR \n");
        break;
    }
}

// COND()
Token* COND(Token* token){
    Token* p = token;
    p = EXPR(p);
    if(Operation(p->code) == 1){
        p = p->next;
        p = EXPR(p);
    }
    return p;
}

// Operation()
int Operation(int code){
    switch (code)
    {
    case EG_TOKEN:
        return 1;
        break;
    
    case DIFF_TOKEN :
        return 1;

    case INF_TOKEN :
        return 1;

    case INFEG_TOKEN :
        return 1;  

    case SUP_TOKEN :
        return 1; 

    case SUPEG_TOKEN :
        return 1;    
    default:
        return -1;
        break;
    }
    return -1;
}

// SI()
Token* SI(Token* token){
    Token* p = token;
    p = COND(p);
    if (p->code == THEN_TOKEN)
        p = INST(p->next);
    else printf("%s \n", genererErreur(THEN_ERREUR));

    return p;
}

// TANTQUE()
Token* TANTQUE(Token* token){
    Token* p = token;
    p = COND(p);
    if (p->code == DO_TOKEN)
        p = INST(p->next);
    else printf("%s \n", genererErreur(DO_ERREUR));

    return p;
}

// ECRIRE()
Token* ECRIRE(Token* token){
    Token* p = token;
    if (p->code == PO_TOKEN){
        p = EXPR(p->next);
        while (p->code == VIR_TOKEN)
        {
            p = EXPR(p->next);
        }
        if(p->code == PF_TOKEN)
            p = p->next;
        else  printf("%s \n", genererErreur(PF_ERREUR));
    }
    else printf("%s \n", genererErreur(PO_ERREUR));
    
    return p;
}

// LIRE()
Token* LIRE(Token* token){
    Token* p = token;
    if (p->code == PO_TOKEN){
        p = p->next;
        if (p->code == ID_TOKEN){
            p = p->next;
            while (p->code == VIR_TOKEN){
                p = p->next;
                if (p->code == ID_TOKEN)
                    p = p->next;
                else printf("%s \n", genererErreur(ID_ERREUR));
            }
            if(p->code == PF_TOKEN)
                p = p->next;
            else  printf("%s \n", genererErreur(PF_ERREUR));
        }
        else printf("%s \n", genererErreur(ID_ERREUR));
    }
    else printf("%s \n", genererErreur(PO_ERREUR));
    
    return p;
}