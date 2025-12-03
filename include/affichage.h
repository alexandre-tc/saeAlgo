/**
 * @file affichage.h
 * @brief Déclarations des fonctions d'affichage de l'interface utilisateur
 * @author Sasha Lorenc & alexandre Triniol--Crozatier
 * @date Octobre - Novembre 2025
 *
 * Ce fichier contient les prototypes de toutes les fonctions d'affichage
 * utilisées dans l'application de gestion de stock.
 */

/**
 * @brief Affiche le menu principal et retourne le choix utilisateur.
 * @return Choix saisi par l'utilisateur.
 */
int menu(void);

/**
 * @brief Affiche l'écran d'ajout d'un produit.
 */
void afficherAjoutProduit();

/**
 * @brief Affiche l'état actuel du stock.
 */
void afficherEtatStock();

/**
 * @brief Affiche les produits en risque de rupture.
 */
void afficherProduitsRisque();

/**
 * @brief Affiche le menu de modification des données produit.
 */
void afficherModificationDonnees();

/**
 * @brief Affiche l'écran de suppression d'un produit.
 */
void afficherSuppressionProduit();

/**
 * @brief Affiche l'écran de traitement de commande.
 */
void afficherTraitementCommande();

/**
 * @brief Affiche le message lorsque le réapprovisionnement été sélectionné.
 */
void afficherReapprovisionnementCamion();

/**
 * @brief Affiche le message de l'historique.
 */
void afficherHistoriqueVentes();

/**
 * @brief Affiche le message de du prix minimum et maximum.
 */
void afficherProduitMinMax();

/**
 * @brief Affiche le message de la fonctionnalité pour les soldes.
 */
void afficherApplicationSoldes();

/**
 * @brief Affiche le message pour les fonctionnalités d'avis.
 */
void afficherFonctionnalitesAvis();

/**
 * @brief Affiche le message de sortie de l'application.
 */
void afficherQuitter();
