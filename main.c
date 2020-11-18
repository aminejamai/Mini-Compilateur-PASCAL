/*
    *** Auteur : JAMAI Mohammed Amine
    *** Date : 18-11-2020
*/
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
    
    char ch;
    while ((ch = getc(monFichier)) != EOF) {
        if (isalpha(ch) != 0)
        {
            int nv = lireMot(monFichier, ch);
            printf("%s \n", affichage(nv));
        }else
        {
            if (isdigit(ch) != 0)
            {
                int num = lireNum(monFichier, ch);
                printf("%s \n", affichage(num));
            }else
            {
                if(espace(ch) == 0){
                    int car = lireCaractereSpec(monFichier, ch);
                    printf("%s \n", affichage(car));
                }
            }  
        }  
    }
    if(ch == EOF) printf("FIN_TOKEN");
    fclose(monFichier);
    return 0;
}
