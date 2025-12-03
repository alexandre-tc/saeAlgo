/**
 * \file stock.h
 * \brief Fichier d'en-tête pour la gestion des avis sur les produits
 * @author Sasha Lorenc & alexandre Triniol--Crozatier
 * \date Octobre - Novembre 2025
 * 
 * Ce fichier contient les déclarations des fonctions pour la gestion d'un système d'avis :
 * - Chargement et sauvegarde des avis depuis/vers un fichier
 * - Ajout, modification et suppression d'avis
 * - Consultation des notes minimales et maximales
 * - Interface globale de gestion des avis
 */

/**
 * \brief Charge les avis depuis un fichier dans des tableaux
 * \param[out] tabRef Tableau qui recevra les références des produits
 * \param[out] tabNotes Tableau qui recevra les notes des produits
 * \param[in] tmax Taille maximale des tableaux
 * \return Taille logique des tableaux remplis, -1 si erreur d'ouverture, -2 si tableau plein
 * 
 * Cette fonction lit le fichier "data/avis.txt" et remplit les tableaux
 * avec les références et notes des produits.
 */
int chargementAvis(int tabRef[], float tabNotes[], int tmax);

/**
 * \brief Recherche une référence dans le tableau d'avis
 * \param[in] tabRef Tableau des références
 * \param[in] tlog Taille logique du tableau
 * \param[in] ref Référence à rechercher
 * \param[out] pos Position de la référence si trouvée
 * \return 1 si la référence est trouvée, 0 sinon
 * 
 * Cette fonction effectue une recherche linéaire dans le tableau des références.
 */
int rechercheRef(int tabRef[], int tlog, int ref, int *pos);

/**
 * \brief Ajoute un nouvel avis pour une référence
 * \param[in,out] tabRef Tableau des références (mis à jour)
 * \param[in,out] tabNotes Tableau des notes (mis à jour)
 * \param[in,out] tlog Taille logique (incrémentée si ajout réussi)
 * \param[in] tmax Taille maximale des tableaux
 * 
 * Cette fonction permet d'ajouter un nouvel avis après vérification
 * que la référence n'existe pas déjà et qu'il y a de la place.
 */
void ajouterAvis(int tabRef[], float tabNotes[], int *tlog, int tmax);

/**
 * \brief Affiche les références avec les notes minimale et maximale
 * \param[in] refMin Référence avec la note minimale
 * \param[in] noteMin Note minimale
 * \param[in] refMax Référence avec la note maximale
 * \param[in] noteMax Note maximale
 * 
 * Cette fonction affiche formaté les produits avec les notes extrêmes.
 */
void afficherRefMinMax(int refMin, float noteMin, int refMax, float noteMax);

/**
 * \brief Trouve et affiche les notes minimale et maximale
 * \param[in] tabRef Tableau des références
 * \param[in] tabNotes Tableau des notes
 * \param[in] tlog Taille logique des tableaux
 * 
 * Cette fonction parcourt les tableaux pour trouver les notes
 * minimale et maximale et les affiche.
 */
void afficherMinMaxNotes(int tabRef[], float tabNotes[], int tlog);

/**
 * \brief Supprime un avis existant
 * \param[in,out] tabRef Tableau des références (mis à jour)
 * \param[in,out] tabNotes Tableau des notes (mis à jour)
 * \param[in,out] tlog Taille logique (décrémentée si suppression réussie)
 * 
 * Cette fonction supprime un avis en décalant les éléments
 * suivants dans les tableaux.
 */
void supprimerAvis(int tabRef[], float tabNotes[], int *tlog);

/**
 * \brief Modifie la note d'un avis existant
 * \param[in,out] tabRef Tableau des références
 * \param[in,out] tabNotes Tableau des notes (modifié)
 * \param[in] tlog Taille logique des tableaux
 * 
 * Cette fonction permet de modifier la note d'une référence existante.
 */
void modifierAvis(int tabRef[], float tabNotes[], int tlog);

/**
 * \brief Sauvegarde les avis dans un fichier
 * \param[in] tabRef Tableau des références
 * \param[in] tabNotes Tableau des notes
 * \param[in] tlog Taille logique des tableaux
 * \return 0 si succès, -1 si erreur d'ouverture
 * 
 * Cette fonction écrit tous les avis dans le fichier "data/avis.txt".
 */
int sauvegarderAvis(int tabRef[], float tabNotes[], int tlog);

/**
 * \brief Fonction principale de gestion des avis
 * 
 * Cette fonction propose un menu interactif complet pour :
 * - Consulter les notes min/max
 * - Ajouter un nouvel avis
 * - Supprimer un avis existant
 * - Modifier un avis existant
 * - Sauvegarder et quitter
 * 
 * Elle gère le chargement initial et la sauvegarde finale des données.
 */
void globalAvis(void);