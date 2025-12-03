#include <stdio.h>
#include <stdlib.h>
#include "../include/stock.h"
#include "../include/affichage.h"
#include "../include/commun.h"
#include "../include/modif.h"
#include "../include/avis.h"

#define TMAX 100
#define TPANIER 15
#define TCAMION 20

void defChoix(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[],int panier[],float prixArtPanier[],int nbArt[], int tlog, int tlogPanier, int tlogV,int tabRefV[],int tabNbArtV[],float prixArtPanierV[],int refAAjouter[], int stockAAjouter[],int seuilAAjouter[],float prixUAAjouter[]) //alexandre
{

    int choix, refCam, stockCam,seuilCam, tlogNvelem;
    float prixUCam;
    choix = menu();

    if (choix == 1) {
        afficherAjoutProduit();
        tlog = fAjouterProduit(tabRef,tabStock,tabPrixU,tabSeuil,tlog,TMAX);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 2) {
        afficherEtatStock();
        afficheEtatStock(tabRef,tabStock,tabPrixU,tabSeuil,tlog);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 3) {
        afficherProduitsRisque();
        afficheRisqueRupt(tabRef,tabStock,tabPrixU,tabSeuil,tlog);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 4) {
        afficherModificationDonnees();
        modifierDonnee(tabRef,tabPrixU,tabSeuil,tlog);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 5) {
        afficherSuppressionProduit();
        tlog = supprimerRef(tabRef, tabStock, tabPrixU, tabSeuil, tlog);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 6) {
        afficherTraitementCommande();
        tlogPanier = passerCommande(tabRef,tabStock,tabPrixU,panier,prixArtPanier,nbArt,tlog,tlogPanier);
        if(tlogPanier == -1){
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
        }
        recapCommande(panier,prixArtPanier,nbArt,tlogPanier);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 7) {
        afficherReapprovisionnementCamion();
        tlogNvelem = saisieCamion(tabRef,tlog,&refCam,&stockCam,&seuilCam,&prixUCam,refAAjouter,stockAAjouter,seuilAAjouter,prixUAAjouter);
        tlog = livraisonCamion(tabRef,tabStock,tabPrixU,tabSeuil,tlog,refAAjouter,stockAAjouter,prixUAAjouter,seuilAAjouter,tlogNvelem);

        if (tlog == -2) {
            printf("  ❌ ERREUR : Échec de la livraison du camion (tableau plein) !\n");
        }

        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if(choix == 8){
        afficherHistoriqueVentes();
        historique(tabRefV,tabNbArtV,prixArtPanierV,tlogV);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 9) {
        afficherProduitMinMax();
        minMaxPrix(tabRef, tabPrixU, tlog);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 10) {
        afficherApplicationSoldes();
        appliquerSoldes(tabRef, tabPrixU, tlog);
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 11) {
        afficherFonctionnalitesAvis();
        globalAvis();
        defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanierV, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);
    }

    else if (choix == 12) {
        sauvegarder(tabRef, tabStock, tabPrixU, tabSeuil, tlog);
        saveVentes(panier,prixArtPanier,nbArt,tlogPanier);

        if (sauvegarder(tabRef, tabStock, tabPrixU, tabSeuil, tlog) == -1) {
            printf("  ❌ ERREUR : Échec de la sauvegarde du stock !\n");
        }
        if (saveVentes(panier,prixArtPanier,nbArt,tlogPanier) == -1) {
            printf("  ❌ ERREUR : Échec de la sauvegarde des ventes !\n");
        }

        afficherQuitter();
        return;
    }
}

void fSaisieProduitAAjouter(int tabRef[], int *refProduit, int *qte, float *prix, int *seuilSecu, int tlog, int*pos) //alexandre
{
    int trouve;

    printf("\n  📝 Saisissez la référence du produit (0 pour quitter) : ");
    scanf("%d", refProduit);
    if (*refProduit == 0)
        return;

    *pos = recherche(tabRef, tlog, *refProduit, &trouve);

    while (*refProduit < 0 || trouve == 1)
    {
        printf("  ❌ Référence invalide ou déjà existante ! Réessayez (0 pour quitter) : ");
        scanf("%d", refProduit);
        *pos = recherche(tabRef, tlog, *refProduit, &trouve);
    }

    printf("  📦 Quantité à ajouter : ");
    scanf("%d", qte);

    while (*qte < 0)
    {
        printf("  ❌ Quantité invalide ! Réessayez : ");
        scanf("%d", qte);
    }

    printf("  💰 Prix unitaire : ");
    scanf("%f", prix);

    while (*prix < 0)
    {
        printf("  ❌ Prix invalide ! Réessayez : ");
        scanf("%f", prix);
    }

    printf("  ⚠️  Seuil de sécurité : ");
    scanf("%d", seuilSecu);

    while (*seuilSecu < 0)
    {
        printf("  ❌ Seuil invalide ! Réessayez : ");
        scanf("%d", seuilSecu);
    }
}

int fAjouterProduit(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog, int tmax)//alexandre
{
    int refProduit, qte, seuilSecu, pos;
    float prix;
    fSaisieProduitAAjouter(tabRef, &refProduit, &qte, &prix, &seuilSecu, tlog, &pos);

    while (refProduit != 0)
    {
        if (tlog >= tmax)
        {
            printf("  ❌ Le tableau de stock est plein !");
            return tlog;
        }

        decalerADroite(tabRef,tabStock,tabPrixU,tabSeuil,tlog,pos,TMAX);

        tabRef[pos] = refProduit;
        tabStock[pos] = qte;
        tabPrixU[pos] = prix;
        tabSeuil[pos] = seuilSecu;
        
        tlog ++;
        printf("  ✅ Produit ajouté avec succès ! Nombre total de produits : %d\n", tlog);
        fSaisieProduitAAjouter(tabRef, &refProduit, &qte, &prix, &seuilSecu, tlog, &pos);
    }
    return tlog;
}


int supprimerRef(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog){//sasha
    int cible, pos, trouve;
    
    printf("  🗑️  Saisissez la référence du produit à supprimer (0 pour quitter) : ");
    scanf("%d", &cible);

    if(cible == 0){
        return tlog;
    }
    pos = recherche(tabRef, tlog, cible, &trouve);
    
    while (trouve == 0)
    {
        printf("  ❌ Référence introuvable ! Réessayez (0 pour quitter) : ");
        scanf("%d",&cible);
        if (cible == 0) return tlog;
        pos = recherche(tabRef, tlog, cible, &trouve);
    }
    
    if (pos >= 0 && pos < tlog && tabStock[pos] > 0) {
        printf("  ⚠️  Impossible de supprimer : il reste %d articles en stock !\n", tabStock[pos]);
        return tlog;
    }

    return decalerAGauche(tabRef, tabStock, tabPrixU, tabSeuil, tlog, pos);
}

void afficheRisqueRupt(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog){ //sasha
    
    int i;
    
    printf("  📋 Articles en risque de rupture de stock :\n");
    printf("  ┌─────────────┬─────────┬─────────┬─────────┐\n");
    printf("  │ Référence   │ Stock   │ Prix    │ Seuil   │\n");
    printf("  ├─────────────┼─────────┼─────────┼─────────┤\n");
    
    for(i = 0;i < tlog; i++){
        if(tabSeuil[i] >= tabStock[i] && tabStock[i] != 0){
            printf("  │ %-11d │ %-7d │ %-7.2f │ %-7d │\n",tabRef[i],tabStock[i],tabPrixU[i],tabSeuil[i]);
        }
    }
    printf("  └─────────────┴─────────┴─────────┴─────────┘\n");
    
    if(i <= 0){
        printf("  ✅ Aucun article en risque de rupture de stock !\n");
    }
}

void afficheEtatStock(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog){ //sasha
    printf("  📊 État du stock :\n");
    printf("  ┌─────────────┬─────────┬─────────┬─────────┬─────────────┐\n");
    printf("  │ Référence   │ Stock   │ Prix    │ Seuil   │ Statut      │\n");
    printf("  ├─────────────┼─────────┼─────────┼─────────┼─────────────┤\n");
    
    for(int i = 0;i < tlog; i++){
        if(tabSeuil[i] >= tabStock[i] && tabStock[i] != 0){
            printf("  │ %-11d │ %-7d │ %-7.2f │ %-7d │ ⚠️  Alerte   │\n",tabRef[i],tabStock[i],tabPrixU[i],tabSeuil[i]);
        }
        else if(tabStock[i] == 0){
            printf("  │ %-11d │ %-7d │ %-7.2f │ %-7d │ ❌ Rupture  │\n",tabRef[i],tabStock[i],tabPrixU[i],tabSeuil[i]);
        }
        else{
            printf("  │ %-11d │ %-7d │ %-7.2f │ %-7d │ ✅ OK       │\n",tabRef[i],tabStock[i],tabPrixU[i],tabSeuil[i]);
        }
    }
    printf("  └─────────────┴─────────┴─────────┴─────────┴─────────────┘\n");
}

int passerCommande(int tabRef[], int tabStock[], float tabPrixU[], int panier[], float prixPanier[], int nbArticles[], int tlog, int tlogPanier) { //sasha
    
    int nbArt, article, trouve, pos;
    char choix, conf;
    int tentatives;

    printf("  🛒 Voulez-vous ajouter un article à votre panier ? (O/N) : ");
    scanf(" %c", &choix);
    
    while (choix != 'O' && choix != 'N') {
        printf("  ⚠️ Réponse invalide ! Entrez O ou N : ");
        scanf(" %c", &choix);
    }
    
    while (choix == 'O') {
        if (tlogPanier == TPANIER) {
            printf("  📦 Votre panier est plein ! Voulez-vous valider la commande ? (O/N) : ");
            scanf(" %c", &conf);
            
            while (conf != 'O' && conf != 'N') {
                printf("  ⚠️ Réponse invalide ! Entrez O ou N : ");
                scanf(" %c", &conf);
            }
            
            if (conf == 'O') return tlogPanier;
            else return -1;
        }
        
        tentatives = 0;
        trouve = 0;
        
        while (!trouve && tentatives < 3) {
            printf("  📝 Article à ajouter (référence) : ");
            scanf("%d", &article);
            pos = recherche(tabRef, tlog, article, &trouve);
            
            if (!trouve) {
                tentatives++;
                if (tentatives < 3) {
                    printf("  ❌ Article introuvable ! (%d/3 tentatives)\n", tentatives);
                } else {
                    printf("  ❌ Article introuvable après 3 tentatives. Abandon.\n");
                    break;
                }
            } else if (tabStock[pos] == 0) {
                printf("  ❌ Cet article n'est plus en stock !\n");
                trouve = 0;
                tentatives++;
                if (tentatives >= 3) {
                    printf("  ❌ Impossible de trouver un article disponible. Abandon.\n");
                    break;
                }
            }
        }
        
        if (trouve && tabStock[pos] > 0) {
            tentatives = 0;
            nbArt = 0;
            
            while (tentatives < 3) {
                printf("  📦 Quantité désirée (disponible: %d) : ", tabStock[pos]);
                scanf("%d", &nbArt);
                
                if (nbArt <= 0) {
                    printf("  ❌ La quantité doit être positive !\n");
                    tentatives++;
                } else if (nbArt > tabStock[pos]) {
                    printf("  ❌ Stock insuffisant ! Maximum disponible : %d\n", tabStock[pos]);
                    tentatives++;
                } else {
                    panier[tlogPanier] = article;
                    nbArticles[tlogPanier] = nbArt;
                    prixPanier[tlogPanier] = nbArt * tabPrixU[pos];
                    tlogPanier++;
                    modifierStock(tabStock, pos, nbArt);
                    
                    printf("  ✅ Article ajouté au panier avec succès !\n");
                    break;
                }
                
                if (tentatives >= 3) {
                    printf("  ❌ Trop de tentatives invalides. Article non ajouté.\n");
                }
            }
        }
        
        printf("  🛒 Voulez-vous ajouter un autre article ? (O/N) : ");
        scanf(" %c", &choix);
        
        while (choix != 'O' && choix != 'N') {
            printf("  ⚠️ Réponse invalide ! Entrez O ou N : ");
            scanf(" %c", &choix);
        }
    }
    
    return tlogPanier;
}

void recapCommande(int panier[],float prixPanier[], int nbArticles[], int tlogPanier) { //sasha et alexandre
    
    float prixFin = 0;
    float tva=0;
    
    if (nbArticles == 0) {
        printf("❌ Vous n'avez rien commandé.");
    }
    
    printf("\n  🧾 RÉCAPITULATIF DE VOTRE COMMANDE :\n");
    printf("  ╔══════════════════════════════════════════════════════════╗\n");
    printf("  ║                    DÉTAIL DE LA COMMANDE                 ║\n");
    printf("  ╠══════════════════════════════════════════════════════════╣\n");
    
    for(int i = 0; i < tlogPanier; i++){
        printf("  ║ %-2d articles N°%-3d                       : %8.2f€      ║\n",nbArticles[i],panier[i],prixPanier[i]);
        prixFin += prixPanier[i];
    }

    tva = 0.2*prixFin;

    printf("  ╠══════════════════════════════════════════════════════════╣\n");
    printf("  ║ COÛT DE LA TVA                          : %8.2f€      ║\n",tva);
    printf("  ║ TOTAL DE LA COMMANDE                    : %8.2f€      ║\n",prixFin);
    printf("  ╚══════════════════════════════════════════════════════════╝\n");
}

void historique(int tabRefV[],int tabNbArtV[],float prixTotalV[], int tlogV) { //sasha
    int nb, choix;

    printf("\n╔════════════════════════════════════════╗\n");
    printf("║                HISTORIQUE              ║\n");
    printf("╚════════════════════════════════════════╝\n\n");

    printf("  1 ➜  Personalisé\n");
    printf("  2 ➜  10 dernières ventes\n");
    printf("  3 ➜  20 dernières ventes\n");
    printf("  4 ➜  tout l'historique\n");
    printf("  5 ➜  Quitter\n");

    printf("\n  ────────────────────────────────────────\n");
    printf("  Votre choix : ");
    scanf("%d%*c", &choix);

    while (choix < 1 || choix > 5)
    {
        printf("  ❌ Choix invalide ! Réessayez : ");
        scanf("%d%*c", &choix);
    }
    printf("\n");
    if(choix == 1){
        printf("Nombre de lignes a afficher : ");
        scanf("%d",&nb);
        while(nb < 1){
            printf(" ❌ Nombre de lignes a afficher : ");
            scanf("%d",&nb);
        }
        affichXComm(tabRefV,tabNbArtV,prixTotalV,tlogV,nb);
    }
    else if(choix == 2){
        affichXComm(tabRefV,tabNbArtV,prixTotalV,tlogV,10);
    }
    else if(choix == 3){
        affichXComm(tabRefV,tabNbArtV,prixTotalV,tlogV,20);
    }
    else if(choix == 4){
        affichXComm(tabRefV,tabNbArtV,prixTotalV,tlogV,tlogV);
    }
    else{
        return;
    }
}

void affichXComm(int tabRefV[],int tabNbArtV[],float prixTotalV[], int tlogV,int n) { //sasha
    
    if(n > tlogV){
        n = tlogV;
    }

    if(n < 1){
        printf("❌ Impossible d'afficher moins d'une commande.");
    }

    printf("\n  🧾 HISTORIQUE DES COMMANDES :\n");
    printf("  ╔══════════════════════════════════════════════════════════╗\n");
    printf("  ║                    HISTORIQUE DES COMMANDES              ║\n");
    printf("  ╠══════════════════════════════════════════════════════════╣\n");

    for(int i = tlogV - 1; i >= tlogV - n; i--){
        printf("  ║ %-2d articles N°%-3d                       : %8.2f€      ║\n",tabNbArtV[i],tabRefV[i],prixTotalV[i]);
    }

    printf("  ╚══════════════════════════════════════════════════════════╝\n");
}

int saisieRefEtQuantite(int *ref, int *quantite) {
    printf("\n  📝 Saisissez la référence du produit (0 pour quitter) : ");
    scanf("%d", ref);
    
    if (*ref == 0) return 0;
    
    if (*ref < 0) {
        printf("  ❌ Référence invalide ! ");
        return -1;
    }
    
    printf("  📦 Quantité à ajouter : ");
    scanf("%d", quantite);
    while (*quantite < 0) {
        printf("  ❌ Quantité invalide ! Réessayez : ");
        scanf("%d", quantite);
    }
    
    return 1;
}

void saisiePrixEtSeuil(float *prix, int *seuil) {
    printf("  💰 Prix unitaire : ");
    scanf("%f", prix);
    while (*prix < 0) {
        printf("  ❌ Prix invalide ! Réessayez : ");
        scanf("%f", prix);
    }
    
    printf("  ⚠️  Seuil de sécurité : ");
    scanf("%d", seuil);
    while (*seuil < 0) {
        printf("  ❌ Seuil invalide ! Réessayez : ");
        scanf("%d", seuil);
    }
}

int saisieCamion(int tabRef[], int tlog, int *ref, int *stock, int *seuil, float *prix, int refAAjouter[], int stockAAjouter[], int seuilAAjouter[], float prixUAAjouter[]) { //alexandre
    int tlogNvElements = 0;
    char choix;
    int trouve, pos;

    printf("Voulez-vous saisir une commande et la faire livrer en camion ? (O/N) : ");
    scanf(" %c", &choix);

    while(choix != 'O' && choix != 'N' && choix != 'o' && choix != 'n') {
        printf("Voulez-vous saisir une commande et la faire livrer en camion ? (O/N) : ");
        scanf(" %c", &choix);
    }

    while (choix == 'O' || choix == 'o') {
        
        int resultatSaisie = saisieRefEtQuantite(ref, stock);
        
        if (resultatSaisie == 0) return tlogNvElements;
        //sans le continue, on peut juste exécuter le reste seulement si c'est pas égal à -1
        //si c'est exécuté, on remonte au début de la boucle comme si cette fois ne s'était pas passée
        if (resultatSaisie == -1) continue;

        pos = recherche(tabRef, tlog, *ref, &trouve);
        
        if (trouve == 1) {
            refAAjouter[tlogNvElements] = *ref;
            stockAAjouter[tlogNvElements] = *stock;
            prixUAAjouter[tlogNvElements] = 0.0;
            seuilAAjouter[tlogNvElements] = 0;
            
            printf("  ✅ Quantité ajoutée au produit existant.");
        } 
        else {
            printf("  🆕 Nouveau produit détecté - saisie des informations complémentaires :\n");
            saisiePrixEtSeuil(prix, seuil);
            
            refAAjouter[tlogNvElements] = *ref;
            stockAAjouter[tlogNvElements] = *stock;
            prixUAAjouter[tlogNvElements] = *prix;
            seuilAAjouter[tlogNvElements] = *seuil;
            
            printf("  ✅ Nouveau produit ajouté à la commande.");
        }
        
        tlogNvElements++;

        printf("\nVoulez-vous ajouter un autre produit ? (O/N) : ");
        scanf(" %c", &choix);
        while(choix != 'N' && choix != 'n' && choix != 'O' && choix != 'o') {
            printf("Voulez-vous ajouter un autre produit ? (O/N) : ");
            scanf(" %c", &choix);
        }
    }
    
    return tlogNvElements;
}

int livraisonCamion(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog, int refAAjouter[], int stockAAjouter[], float prixUAAjouter[], int seuilAAjouter[], int tlogNvElements) { //alexandre
    
    int pos, trouve;

    for (int i = 0; i < tlogNvElements; i++) {
        pos = recherche(tabRef, tlog, refAAjouter[i], &trouve);

        if (trouve == 0) {
            // Nouveau produit
            if(tlog == TMAX) {
                printf(" ❌ Tableau plein !");
                return -2;
            }
            tabRef[tlog] = refAAjouter[i];
            tabStock[tlog] = stockAAjouter[i];
            tabPrixU[tlog] = prixUAAjouter[i];
            tabSeuil[tlog] = seuilAAjouter[i];
            tlog++;
            printf("  ➕ Nouveau produit %d ajouté au stock.\n", refAAjouter[i]);
        } 
        else {
            tabStock[pos] += stockAAjouter[i];
            printf("  📦 Stock du produit %d mis à jour : +%d unités.\n", refAAjouter[i], stockAAjouter[i]);
        }
    }
    return tlog;
}

void minMaxPrix(int tabRef[], float tabPrixU[], int tlog) { //alexandre

    int i, ref;
    float prix;
    char choix = 'O';

    if (tlog == 0) {
        printf("❌ Aucun produit dans le catalogue !\n");
        return;
    }

    while (choix == 'O' || choix == 'o') {
        
        printf("🌟 Voulez-vous connaitre le produit le plus cher ou le moins cher ? (P/M) : ");
        scanf(" %c", &choix);

        while (choix != 'P' && choix != 'p' && choix != 'M' && choix != 'm') {
            printf("\n❌ ERREUR : Choix invalide. Veuillez entrer 'P' ou 'M'.\n");
            printf("🌟 Voulez-vous connaitre le produit le plus cher ou le moins cher ? (P/M) : ");
            scanf(" %c", &choix);
        }

        ref = tabRef[0];
        prix = tabPrixU[0];

        if (choix == 'P' || choix == 'p') {
            for (i = 1; i < tlog; i++) {
                if (tabPrixU[i] > prix) {
                    ref = tabRef[i];
                    prix = tabPrixU[i];
                }
            }
            affichMinMax(ref, prix, 1);
        } 
        else if (choix == 'M' || choix == 'm') {
            for (i = 1; i < tlog; i++) {
                if (tabPrixU[i] < prix) {
                    ref = tabRef[i];
                    prix = tabPrixU[i];
                }
            }
            affichMinMax(ref, prix, 0);
        }

        printf("\n🔍 Voulez-vous faire une autre recherche ? (O/N) : ");
        scanf(" %c", &choix);
    }
}

void affichMinMax(int ref, float prix, int ifPlusCher) { //alexandre

    if (ifPlusCher == 1) {
        printf("\n🌟========================================🌟\n");
        printf("        🏷️  PRODUIT LE PLUS CHER 🏷️\n");
        printf("🌟========================================🌟\n");
        printf("🔹 Référence : %d\n", ref);
        printf("🔹 Prix : %.2f €\n", prix);
        printf("🌟========================================🌟\n");
    }
    else {
        printf("\n🌟========================================🌟\n");
        printf("        🏷️  PRODUIT LE MOINS CHER 🏷️\n");
        printf("🌟========================================🌟\n");
        printf("🔹 Référence : %d\n", ref);
        printf("🔹 Prix : %.2f €\n", prix);
        printf("🌟========================================🌟\n");
    }
}

void appliquerSoldes(int tabRef[], float tabPrixU[], int tlog) { //alexandre
    int remise, ref, trouve;
    char choix;

    saisieSoldes(&remise, &choix);

    while (choix == 'O' || choix == 'o') {
        printf("Entrez la référence à laquelle vous voulez faire une remise : ");
        scanf("%d", &ref);
        
        trouve = 0;
        for (int i = 0; i < tlog; i++) {
            if (tabRef[i] == ref) {
                tabPrixU[i] = tabPrixU[i] * (1 - remise / 100.0);
                trouve = 1;
                break;
            }
        }
        
        if (trouve == 0) {
            printf("❌ Référence introuvable !\n");
        }
        
        saisieSoldes(&remise, &choix);
    }
}

void saisieSoldes(int *remise, char *choix) { //alexandre

    printf("Voulez-vous appliquer une remise à certaines références ? (O/N) : ");
    scanf(" %c", choix);
    while (*choix != 'O' && *choix != 'o' && *choix != 'N' && *choix != 'n') {
        printf("❌ Réponse invalide ! Veuillez entrer 'O' pour OUI ou 'N' pour NON : ");
        scanf(" %c", choix);
    }

    if (*choix == 'O' || *choix == 'o') {
        printf("Saisissez quelle remise vous voulez appliquer (ex : 10 pour -10%%) : ");
        scanf("%d", remise);
        while (*remise <= 0 || *remise > 100) {
            printf("❌ Remise invalide ! Veuillez entrer une valeur entre 1 et 100 : ");
            scanf("%d", remise);
        }
    }
}


void global(void) { //sasha et alexandre

    int tabRef[TMAX], tabStock[TMAX], tabSeuil[TMAX],panier[TPANIER],nbArt[TPANIER],tabRefV[TMAX],tabNbArtV[TMAX], refAAjouter[TCAMION], stockAAjouter[TCAMION], seuilAAjouter[TCAMION], tlogPanier = 0, tlog, tlogV;
    float tabPrixU[TMAX], prixArtPanier[TPANIER], prixTotalV[TMAX], prixUAAjouter[TCAMION];

    tlog = chargement(tabRef, tabStock, tabPrixU, tabSeuil, TMAX);

    if (tlog == -1 || tlog == -2) {
        return;
    }

    tlogV = chargementVentes(tabRefV,tabNbArtV,prixTotalV,TMAX);
    if (tlogV == -1 || tlogV == -2) {
        return;
    }

    defChoix(tabRef, tabStock, tabPrixU, tabSeuil, panier, prixArtPanier, nbArt, tlog, tlogPanier, tlogV, tabRefV, tabNbArtV, prixArtPanier, refAAjouter, stockAAjouter, seuilAAjouter, prixUAAjouter);

    return;
}
