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