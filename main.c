#include<stdio.h>
#include<stdlib.h>
#include"header.h"

int main(){

    // fichier : Valide
    // char nomFichier[20];
    // printf("Entrer le nom de fichier : ");
    // scanf("%s", nomFichier);

    // Lecture a partir d'un fichier 
    FILE* monFichier = fopen("./test.txt", "r");

    if (monFichier == NULL)
    {
        printf("Oops : Le fichier n'existe pas");
        exit(1);
    }
    Token* tokens = NULL;
    char ch;
    
    while ((ch = getc(monFichier)) != EOF) {
        if (isalpha(ch) != 0)
        {
            int nv = lireMot(monFichier, ch);
            tokens = inserer(tokens, nv);
        }else
        {
            if (isdigit(ch) != 0)
            {
                int num = lireNum(monFichier, ch);
                tokens = inserer(tokens, num);
            }else
            {
                if(espace(ch) == 0){
                    int car = lireCaractereSpec(monFichier, ch);
                    tokens = inserer(tokens, car);
                }
            }  
        }  
    }
    if(ch == EOF){ 
        tokens = inserer(tokens, FIN_TOKEN);
    }
    
    fclose(monFichier);

    printf("*********** ANALYSE LEXICALE : \n");
    //afficherListe(tokens);
    printf("*********** FIN ANALYSE LEXICALE\n");

    printf("*********** ANALYSE Syntaxique : \n");
    PROGRAM(tokens);
    printf("*********** FIN ANALYSE Syntaxique : \n");
    return 0;
}