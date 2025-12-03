/**
 * @file commun.h
 * @brief Déclarations des fonctions communes et utilitaires
 * @author Sasha Lorenc & alexandre Triniol--Crozatier
 * @date Octobre - Novembre 2025
 *
 * Ce fichier contient les prototypes des fonctions utilitaires communes
 * utilisées dans toute l'application : chargement/sauvegarde, recherche, décalages.
 */

/**
 * @brief Charge les données depuis les fichiers vers les tableaux mémoire.
 * @param tabRef Tableau des références produits.
 * @param tabStock Tableau des quantités en stock par référence.
 * @param tabPrixU Tableau des prix unitaires par référence.
 * @param tabSeuil Tableau des seuils de sécurité par référence.
 * @param tmax Capacité maximale des tableaux.
 * @return Taille logique après chargement (nombre d'éléments chargés), ou code d'erreur.
 */
int chargement(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tmax);

/**
 * @brief Sauvegarde les tableaux mémoire vers les fichiers persistants.
 * @param tabRef Tableau des références produits.
 * @param tabStock Tableau des quantités en stock par référence.
 * @param tabPrixU Tableau des prix unitaires par référence.
 * @param tabSeuil Tableau des seuils de sécurité par référence.
 * @param tlog Taille logique des tableaux (nombre d'éléments à sauvegarder).
 * @return 0 en cas de succès, sinon un code d'erreur.
 */
int sauvegarder(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog);

/**
 * @brief Recherche dichotomique d'une référence dans le tableau trié.
 * @param tabRef Tableau des références trié par ordre croissant.
 * @param tlog Taille logique du tableau.
 * @param cible Référence recherchée.
 * @param trouve Indique 1 si la référence est trouvée, 0 sinon.
 * @return Position d'insertion si non trouvé, position exacte si trouvé.
 */
int recherche(int tabRef[], int tlog, int cible, int *trouve);

/**
 * @brief Décale vers la gauche les éléments des tableaux à partir d'une position.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param tlog Taille logique actuelle.
 * @param pos Position de départ du décalage.
 * @return Nouvelle taille logique après suppression/décalage.
 */
int decalerAGauche(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog, int pos);

/**
 * @brief Décale vers la gauche les tableaux de ventes pour supprimer les ventes les plus anciennes.
 * @param tabRefV Tableau des références vendues.
 * @param tabNbArtV Tableau des quantités vendues.
 * @param prixTotalV Tableau des prix totaux.
 * @param tlog Taille logique actuelle.
 * @param nbSuppressions Nombre de ventes anciennes à supprimer.
 * @return Nouvelle taille logique après suppression.
 */
int decalerAGaucheVentes(int tabRefV[], int tabNbArtV[], float prixTotalV[], int tlog, int nbSuppressions);

/**
 * @brief Décale vers la droite pour libérer une place à une position donnée.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param tlog Taille logique actuelle (sera augmentée après insertion).
 * @param pos Position à libérer.
 * @param tmax Capacité maximale des tableaux.
 */
void decalerADroite(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog, int pos,int tmax);
/**
 * @brief Charge uniquement les X dernières ventes depuis le fichier.
 * @param tabRefV Tableau des références vendues (sortie).
 * @param tabNbartV Tableau des quantités vendues par référence (sortie).
 * @param prixTotalV Tableau des prix totaux par ligne de vente (sortie).
 * @param tmax Nombre maximal de lignes à charger (X).
 * @return Nombre de lignes effectivement chargées, ou code négatif en cas d'erreur.
 */
int chargementVentes(int tabRefV[],int tabNbartV[],float prixTotalV[],int tmax);
/**
 * @brief Ajoute les lignes de vente au fichier pour persistance.
 * @param panier Références vendues.
 * @param prixPanier Prix total par référence.
 * @param nbArticles Quantité vendue par référence.
 * @param tlogPanier Nombre de lignes à écrire.
 * @return 0 si succès, négatif sinon.
 */
int saveVentes(int panier[],float prixPanier[], int nbArticles[],int tlogPanier);
