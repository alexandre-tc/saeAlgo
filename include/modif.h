/**
 * @file modif.h
 * @brief Déclarations des fonctions de modification des données produits
 * @author Sasha Lorenc & alexandre Triniol--Crozatier
 * @date Octobre - Novembre 2025
 *
 * Ce fichier contient les prototypes des fonctions permettant de modifier
 * les prix, seuils et stocks des produits.
 */

/**
 * @brief Modifie le seuil de sécurité d'un produit.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param pos Position de la référence à modifier.
 * @param val Nouveau seuil de sécurité.
 */
void modifierSeuil(int tabSeuil[],int pos, int val);

/**
 * @brief Modifie la quantité en stock d'un produit.
 * @param tabStock Tableau des quantités en stock.
 * @param pos Position de la référence à modifier.
 * @param val Nouvelle quantité en stock (peut être négative pour décrémenter).
 */
void modifierStock(int tabStock[],int pos, int val);

/**
 * @brief Modifie le prix unitaire d'un produit.
 * @param tabPrixU Tableau des prix unitaires.
 * @param pos Position de la référence à modifier.
 * @param val Nouveau prix unitaire.
 */
void modifierPrix(float tabPrixU[],int pos, float val);

/**
 * @brief Saisit l'opération de modification et valide la référence ciblée.
 * @param valS Valeur entière associée (seuil/stock) en sortie.
 * @param valP Valeur de prix en sortie.
 * @param tabRef Tableau des références.
 * @param tlog Taille logique du tableau des références.
 * @param pos Position trouvée pour la référence ciblée (sortie).
 * @return Code indiquant le type de modification choisi ou une erreur.
 */
int saisirModif(int* valS, float* valP,int tabRef[], int tlog, int* pos);

/**
 * @brief Point d'entrée pour modifier une donnée d'un produit (prix/seuil/stock).
 * @param tabRef Tableau des références.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param tlog Taille logique des tableaux.
 */
void modifierDonnee(int tabRef[], float tabPrixU[], int tabSeuil[], int tlog);
