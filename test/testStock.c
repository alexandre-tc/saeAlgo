#include <stdio.h>
#include <stdlib.h>

#include "../include/stock.h"
#include "../include/affichage.h"
#include "../include/commun.h"
#include "../include/modif.h"

#define TMAX 100
void testChargement(){
    int tabRef[TMAX];
    int tabStock[TMAX];
    float tabPrixU[TMAX];
    int tabSeuil[TMAX];
    int nbProduits;
    
    printf("=== TEST DE LA FONCTION CHARGEMENT ===\n\n");
    
    nbProduits = chargement(tabRef, tabStock, tabPrixU, tabSeuil, TMAX);
    
    if(nbProduits == -1){
        printf("Test ECHOUE : Fichier non trouve\n");
        return;
    }
    else if(nbProduits == -2){
        printf("Test ECHOUE : Tableau trop petit\n");
        return;
    }
    else if(nbProduits > 0){
        printf("Test REUSSI : %d produits charges\n\n", nbProduits);
        
        // Affichage des données chargées
        printf("%-10s %-10s %-12s %-10s\n", "Reference", "Stock", "Prix Unit.", "Seuil");
        printf("---------------------------------------------------\n");
        
        for(int i = 0; i < nbProduits; i++){
            printf("%-10d %-10d %-12.2f %-10d", 
                   tabRef[i], tabStock[i], tabPrixU[i], tabSeuil[i]);
            
            // Indicateurs visuels
            if(tabStock[i] == 0){
                printf(" [RUPTURE]");
            }
            else if(tabStock[i] < tabSeuil[i]){
                printf(" [ALERTE]");
            }
            printf("\n");
        }
        
        // Statistiques
        printf("\n=== STATISTIQUES ===\n");
        
        int nbRuptures = 0, nbAlertes = 0;
        float valeurTotale = 0.0;
        
        for(int i = 0; i < nbProduits; i++){
            if(tabStock[i] == 0) nbRuptures++;
            else if(tabStock[i] < tabSeuil[i]) nbAlertes++;
            valeurTotale += tabStock[i] * tabPrixU[i];
        }
        
        printf("Nombre de produits : %d\n", nbProduits);
        printf("Produits en rupture : %d\n", nbRuptures);
        printf("Produits en alerte : %d\n", nbAlertes);
        printf("Valeur totale du stock : %.2f euros\n", valeurTotale);
    }
    else{
        printf("Test ECHOUE : Aucun produit charge\n");
    }
}

int main(){
    //testChargement();$
    global();
    return 0;
}