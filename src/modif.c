#include <stdio.h>
#include <stdlib.h>
#include "../include/modif.h"
#include "../include/commun.h"

void modifierSeuil(int tabSeuil[],int pos, int val) { //sasha
    
    if (pos >= 0) {
        tabSeuil[pos] = val;
    }
}
void modifierStock(int tabStock[],int pos, int val) { //sasha
    
    if (pos >= 0 && tabStock[pos] >= val) {
        tabStock[pos] = tabStock[pos] - val;
    }
}
void modifierPrix(float tabPrixU[],int pos, float val) { //sasha
    
    if (pos >= 0) {
        tabPrixU[pos] = val;
    }
}

int saisirModif(int* valS, float* valP,int tabRef[], int tlog, int* pos) { //sasha
    
    int ref, trouve, choix;

    printf("\n  📝 Saisissez la référence du produit à modifier (0 pour quitter) : ");
    scanf("%d",&ref);
    if (ref == 0)
        return 0;

    *pos = recherche(tabRef, tlog, ref, &trouve);

    while (ref < 0 || trouve == 0)
    {
        printf("  ❌ Référence invalide ! Réessayez (0 pour quitter) : ");
        scanf("%d", &ref);
        *pos = recherche(tabRef, tlog, ref, &trouve);
    }

    if(ref == 0){
        return 0;
    }

    printf("\n  🔧 Que voulez-vous modifier ?\n");
    printf("    1 ➜ Prix unitaire\n");
    printf("    2 ➜ Seuil de sécurité\n");
    printf("    3 ➜ Les deux\n");
    printf("    0 ➜ Annuler\n");
    printf("  Votre choix : ");
    scanf("%d", &choix);
    
    while(choix != 1 && choix != 2 && choix != 3 && choix != 0){
        printf("  ❌ Choix invalide ! Réessayez : ");
        scanf("%d", &choix);
    }

    if (choix == 0) {
        
    }
    else if (choix == 1) {
        printf("  💰 Nouveau prix unitaire : ");
        scanf("%f", valP);
        while(*valP < 0) {
            printf("  ❌ Prix invalide ! Réessayez : ");
            scanf("%f", valP);
        }
    }
    else if (choix == 2) {
        printf("  ⚠️  Nouveau seuil de sécurité : ");
        scanf("%d", valS);
        while(*valS < 0) {
            printf("  ❌ Seuil invalide ! Réessayez : ");
            scanf("%d", valS);
        }
    }
    else if (choix == 3) {
        printf("  💰 Nouveau prix unitaire : ");
        scanf("%f", valP);
        while(*valP < 0) {
            printf("  ❌ Prix invalide ! Réessayez : ");
            scanf("%f", valP);
        }
        printf("  ⚠️  Nouveau seuil de sécurité : ");
        scanf("%d", valS);
        while(*valS < 0) {
            printf("  ❌ Seuil invalide ! Réessayez : ");
            scanf("%d", valS);
        }
    }
    return choix;

}

void modifierDonnee(int tabRef[], float tabPrixU[], int tabSeuil[], int tlog) { //sasha
    
    int valS, pos, choix;
    float valP;

    choix = saisirModif(&valS,&valP,tabRef,tlog,&pos);

    if (choix == 0) {
        return;
    }
    else if (choix == 1) {
        modifierPrix(tabPrixU,pos,valP);
    }
    else if (choix == 2) {
        modifierSeuil(tabSeuil,pos,valS);
    }
    else if (choix == 3) {
        modifierSeuil(tabSeuil,pos,valS);
        modifierPrix(tabPrixU,pos,valP);
    }
}