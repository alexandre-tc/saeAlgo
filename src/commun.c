#include <stdio.h>
#include <stdlib.h>
#include "../include/commun.h"
#include "../include/stock.h"

int chargement(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tmax) //sasha
{
    FILE *fe;
    int ref, stock, seuil, tlog = 0;
    float prix;

    fe = fopen("Data/produits.txt", "r");
    if (fe == NULL)
    {
        printf("  ❌ ERREUR : Impossible d'ouvrir le fichier de données !\n");
        return -1;
    }
    fscanf(fe, "%d%d%f%d", &ref, &stock, &prix, &seuil);
    while (!feof(fe))
    {
        if (tlog >= tmax)
        {
            printf("  ⚠️  ERREUR : Le tableau de stock est plein !\n");
            fclose(fe);
            return -2;
        }
        tabRef[tlog] = ref;
        tabStock[tlog] = stock;
        tabPrixU[tlog] = prix;
        tabSeuil[tlog] = seuil;
        tlog++;
       
        fscanf(fe, "%d%d%f%d", &ref, &stock, &prix, &seuil);
    }
    fclose(fe);
    return tlog;
}

int chargementVentes(int tabRefV[],int tabNbartV[],float prixTotalV[],int tmax){ //sasha et alexandre

    FILE* fe;
    int ref,nbArt,tlog = 0;
    float prixTotal;

    fe = fopen("Data/ventes.txt","r");
    if(fe == NULL){
        printf("  ❌ ERREUR : Impossible d'ouvrir le fichier de données !\n");
        return -1;
    }

    fscanf(fe,"%d%d%f",&ref,&nbArt,&prixTotal);
    
    while(!feof(fe)){
        if (tlog >= tmax)
        {
            printf("  ⚠️  ERREUR : Le tableau de ventes est plein !\n");
            fclose(fe);
            return -2;
        }
        tabRefV[tlog] = ref;
        tabNbartV[tlog] = nbArt;
        prixTotalV[tlog] = prixTotal;
        tlog++;
        fscanf(fe,"%d%d%f",&ref,&nbArt,&prixTotal);
    }
    fclose(fe);

    if(tlog > 80){
        int nbASupprimer = tlog - 80;
        tlog = decalerAGaucheVentes(tabRefV, tabNbartV, prixTotalV, tlog, nbASupprimer);

        fe = fopen("Data/ventes.txt","w");
        if(fe != NULL){
            for(int i = 0; i < tlog; i++){
                fprintf(fe,"%d %d %.2f\n", tabRefV[i], tabNbartV[i], prixTotalV[i]);
            }
            fclose(fe);
        }
    }

    return tlog;
}

int sauvegarder(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog) //sasha
{
    FILE *fs;

    fs = fopen("Data/produits.txt", "w");
    if (fs == NULL)
    {
        printf("  ❌ ERREUR : Impossible de sauvegarder les données !\n");
        return -1;
    }
    for (int i = 0; i < tlog; i++)
    {
        fprintf(fs, "%d %d %.2f %d\n", tabRef[i], tabStock[i], tabPrixU[i], tabSeuil[i]);
    }
    fclose(fs);

    return 0;
}

int saveVentes(int panier[],float prixPanier[], int nbArticles[],int tlogPanier) {
    
    FILE* fs;

    fs = fopen("Data/ventes.txt","a");
    if(fs == NULL){
        printf("  ❌ ERREUR : Impossible de sauvegarder les données !\n");
        return -1;
    }
    for(int i = 0; i < tlogPanier;i++){
        fprintf(fs,"%d %d %.2f\n",panier[i],nbArticles[i],prixPanier[i]);

    }
    
    fclose(fs);
    return 0;
}


int recherche(int tabRef[], int tlog, int cible, int *trouve) //sasha
{
    for (int i = 0; i < tlog; i++)
    {
        if (tabRef[i] == cible)
        {
            *trouve = 1;
            return i;
        }
        else if(cible < tabRef[i]){
            *trouve = 0;
            return i;
        }
    }
    
    *trouve = 0;
    return tlog;
}

int decalerAGauche(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog, int pos) //sasha
{
    if (pos < 0 || pos >= tlog) {
        printf("  ❌ ERREUR : Position invalide pour le décalage !\n");
        return tlog;
    }

    for (int i = pos; i < tlog - 1; i++)
    {
        tabRef[i] = tabRef[i+1];
        tabStock[i] = tabStock[i+1];
        tabPrixU[i] = tabPrixU[i+1];
        tabSeuil[i] = tabSeuil[i+1];
    }
    return tlog - 1;
}

int decalerAGaucheVentes(int tabRefV[], int tabNbArtV[], float prixTotalV[], int tlog, int nbSuppressions) //sasha
{
    if (nbSuppressions <= 0 || nbSuppressions >= tlog) {
        return tlog;
    }

    for (int i = 0; i < tlog - nbSuppressions; i++)
    {
        tabRefV[i] = tabRefV[i + nbSuppressions];
        tabNbArtV[i] = tabNbArtV[i + nbSuppressions];
        prixTotalV[i] = prixTotalV[i + nbSuppressions];
    }
    
    return tlog - nbSuppressions;
}

void decalerADroite(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog, int pos,int tmax){ //sasha
    
    if(tlog >= tmax){
        printf("  ⚠️  ERREUR : Espace insuffisant pour insérer un nouveau produit !\n");
        return ;
    }
    
    if (pos < 0 || pos > tlog) {
        printf("  ❌ ERREUR : Position invalide pour l'insertion !\n");
        return;
    }
    
    for(int i = tlog ; i > pos ; i--){
        tabRef[i] = tabRef[i-1];
        tabStock[i] = tabStock[i-1];
        tabPrixU[i] = tabPrixU[i-1];
        tabSeuil[i] = tabSeuil[i-1];
    }
}