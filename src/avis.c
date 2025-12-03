#include <stdio.h>
#include <stdlib.h>

#include "../include/stock.h"

#define TAVIS 30


int chargementAvis(int tabRef[], float tabNotes[], int tmax) { //alexandre
    
    FILE *fe;
    int ref, tlog = 0;
    float note;

    fe = fopen("data/avis.txt", "r");
    if (fe == NULL)
    {
        printf("  ❌ ERREUR : Impossible d'ouvrir le fichier de données !\n");
        return -1;
    }
    fscanf(fe, "%d%f", &ref, &note);
    while (!feof(fe))
    {
        if (tlog >= tmax)
        {
            printf("  ⚠️  ERREUR : Le tableau d'avis est plein !\n");
            fclose(fe);
            return -2;
        }
        tabRef[tlog] = ref;
        tabNotes[tlog] = note;
        tlog++;
       
        fscanf(fe, "%d%f", &ref, &note);
    }
    fclose(fe);
    return tlog;
}

int rechercheRef(int tabRef[], int tlog, int ref, int *pos) { //alexandre

    int i;

    for (i=0; i<tlog; i++) {
        
        if (tabRef[i] == ref) {
            *pos = i;
            return 1;
        }
    }

    return 0;
}

void ajouterAvis(int tabRef[], float tabNotes[], int *tlog, int tmax) { //alexandre

    int ref, pos;
    float note;
    char continuer = 'O';

    while (continuer == 'O' || continuer == 'o') {
        printf("À quelle référence voulez-vous ajouter une note ? : ");
        scanf("%d", &ref);

        if (rechercheRef(tabRef, *tlog, ref, &pos) == 1) {
            printf("❌ Désolé, cette référence a déjà une note.\n");
        } 
        else if (*tlog >= tmax) {
            printf("❌ Le tableau est plein, impossible d'ajouter une nouvelle note.\n");
            return;
        } 
        else {
            printf("Quelle note voulez-vous ajouter ? : ");
            scanf("%f", &note);

            tabRef[*tlog] = ref;
            tabNotes[*tlog] = note;
            (*tlog)++;

            printf("✅ Note ajoutée avec succès !\n");
        }

        printf("Voulez-vous ajouter une autre note ? (O/N) : ");
        scanf(" %c", &continuer);
        
        while(continuer != 'O' && continuer != 'o' && continuer != 'N' && continuer != 'n') {
            printf("❌ Réponse invalide ! Veuillez entrer 'O' pour OUI ou 'N' pour NON : ");
            scanf(" %c", &continuer);
        }
    }

    printf("📝 Saisie des notes terminée.\n");
}

void afficherRefMinMax(int refMin, float noteMin, int refMax, float noteMax) { //alexandre

    printf("\n==============================================\n");
    printf("           📊 Résultats des notes\n");
    printf("==============================================\n");

    printf(" 🔽  Note minimale\n");
    printf("     • Référence : %d\n", refMin);
    printf("     • Note      : %.2f\n\n", noteMin);

    printf(" 🔼  Meilleure note\n");
    printf("     • Référence : %d\n", refMax);
    printf("     • Note      : %.2f\n", noteMax);

    printf("==============================================\n\n");
}

void afficherMinMaxNotes(int tabRef[], float tabNotes[], int tlog) { //alexandre

    if (tlog == 0) {
        printf("Aucune note disponible.\n");
        return;
    }

    //déclaré seulement si pas d'erreur, evite de remplir la mémoire pour lancer un return après
    int i, posMax = 0, posMin = 0;
    float min = tabNotes[0], max = tabNotes[0];

    for (i=1; i<tlog; i++) {
        if (tabNotes[i] < min) {
            min = tabNotes[i];
            posMin = i;
        }
    }

    for (i=1; i<tlog; i++) {
        if (tabNotes[i] > max) {
            max = tabNotes[i];
            posMax = i;
        }
    }

    afficherRefMinMax(tabRef[posMin], min, tabRef[posMax], max);
}

void supprimerAvis(int tabRef[], float tabNotes[], int *tlog) { //alexandre
    
    int ref, pos;

    printf("Saisissez la référence que vous voulez supprimer : ");
    scanf("%d", &ref);

    if (rechercheRef(tabRef, *tlog, ref, &pos) == 1) {
        for (int i = pos; i < *tlog - 1; i++) {
            tabRef[i] = tabRef[i + 1];
            tabNotes[i] = tabNotes[i + 1];
        }
        (*tlog)--;
        printf("✅ Note supprimée avec succès !\n");
    } else {
        printf("❌ Désolé, cette référence n'existe pas.\n");
    }
}

void modifierAvis(int tabRef[], float tabNotes[], int tlog) { //alexandre

    int refAM, pos;
    float note;

    printf("Saisissez la référence que vous voulez modifier : ");
    scanf("%d", &refAM);

    if (rechercheRef(tabRef, tlog, refAM, &pos) == 1) {
        
        printf("Saisissez la nouvelle note : ");
        scanf("%f", &note);

        tabNotes[pos] = note;
        printf("✅ Note modifiée avec succès !\n");
    }
    
    else {
        printf("❌ Désolé, cette référence n'existe pas.");
    }
}

int sauvegarderAvis(int tabRef[], float tabNotes[], int tlog) { //alexandre
    
    FILE *fe;

    fe = fopen("data/avis.txt", "w");
    if (fe == NULL)
    {
        printf("  ❌ ERREUR : Impossible de sauvegarder les nouvelles notes !\n");
        return -1;
    }
    for (int i = 0; i < tlog; i++)
    {
        fprintf(fe, "%d %.2f\n", tabRef[i], tabNotes[i]);
    }
    fclose(fe);

    return 0;
}

void globalAvis(void) { //alexandre
    
    int tabRef[TAVIS], tlog, choix = 0;
    float tabNotes[TAVIS];

    tlog = chargementAvis(tabRef, tabNotes, TAVIS);
    
    if (tlog < 0) {
        return;
    }

    printf("Bienvenue dans les fonctionnalités d'avis !\n");
    
    while (choix != 5) {
        printf("\n==============================================\n");
        printf("                 📚 MENU NOTES\n");
        printf("==============================================\n\n");

        printf("  1 → Consulter les références (note min & max)\n");
        printf("  2 → Ajouter une note\n");
        printf("  3 → Supprimer une note\n");
        printf("  4 → Modifier une note\n");
        printf("  5 → Revenir au menu principal\n\n");
        
        printf("Votre choix : ");
        scanf("%d", &choix);

        while (choix<1 || choix>5) {
            printf("\n❌ Choix invalide. Veuillez entrer un nombre entre 1 et 5 : ");
            scanf("%d", &choix);
        }

        if (choix == 1) {
            afficherMinMaxNotes(tabRef, tabNotes, tlog);
        } 
        
        else if (choix == 2) {
            ajouterAvis(tabRef, tabNotes, &tlog, TAVIS);
        } 
        
        else if (choix == 3) {
            supprimerAvis(tabRef, tabNotes, &tlog);
        } 
        
        else if (choix == 4) {
            modifierAvis(tabRef, tabNotes, tlog);
        }
    }

    sauvegarderAvis(tabRef, tabNotes, tlog);
    printf("\n👋🏻 Vous avez quitté les fonctionnalités d'avis...\n");

    return;
}
