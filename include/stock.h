/**
 * @file stock.h
 * @brief Déclarations des fonctions de gestion de stock et de commandes
 * @author Sasha Lorenc & alexandre Triniol--Crozatier
 * @date Octobre - Novembre 2025
 *
 * Ce fichier contient les prototypes de toutes les fonctions liées à la gestion
 * du stock de produits, des commandes clients et de l'historique des ventes.
 */

/**
 * @brief Ajoute un produit aux tableaux s'il n'existe pas déjà.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités en stock.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param tlog Taille logique actuelle.
 * @param tmax Capacité maximale des tableaux.
 * @return Nouvelle taille logique après insertion, ou code d'erreur.
 */
int fAjouterProduit(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog, int tmax);

/**
 * @brief Ajoute un produit dans le fichier de données persistantes.
 * @param ref Référence produit.
 * @param qte Quantité initiale en stock.
 * @param prix Prix unitaire.
 * @param seuil Seuil de sécurité.
 */
void ajouterProduitFichier(int ref, int qte, float prix, int seuil);

/**
 * @brief Saisit un nouveau produit et calcule sa position d'insertion.
 * @param tabRef Tableau des références.
 * @param refProduit Référence saisie (sortie).
 * @param qte Quantité saisie (sortie).
 * @param prix Prix unitaire saisi (sortie).
 * @param seuilSecu Seuil de sécurité saisi (sortie).
 * @param tlog Taille logique actuelle.
 * @param pos Position d'insertion calculée (sortie).
 */
void fSaisieProduitAAjouter(int tabRef[], int *refProduit, int *qte, float *prix, int *seuilSecu, int tlog, int*pos);

/**
 * @brief Supprime une référence de produit des tableaux.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités en stock.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param tlog Taille logique actuelle.
 * @return Nouvelle taille logique après suppression, ou code d'erreur.
 */
int supprimerRef(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog);

/**
 * @brief Affiche les produits dont le stock est sous le seuil de sécurité.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités en stock.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param tlog Taille logique actuelle.
 */
void afficheRisqueRupt(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog);

/**
 * @brief Affiche un état détaillé du stock pour toutes les références.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités en stock.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param tlog Taille logique actuelle.
 */
void afficheEtatStock(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog);

/**
 * @brief Définit les choix d'articles à ajouter dans le panier.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités en stock.
 * @param tabPrixU Tableau des prix unitaires.
 * @param tabSeuil Tableau des seuils de sécurité.
 * @param panier Tableau des références sélectionnées.
 * @param prixArtPanier Tableau des prix unitaires des articles dans le panier.
 * @param nbArt Tableau des quantités par article dans le panier.
 * @param tlog Taille logique des références.
 * @param tlogPanier Taille logique du panier.
 * @param tlogV Taille logique de l'historique des ventes.
 * @param tabRefV Tableau des références de l'historique des ventes.
 * @param tabNbArtV Tableau des quantités de l'historique des ventes.
 * @param prixArtPanierV Tableau des prix totaux de l'historique des ventes.
 */
void defChoix(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[],int panier[],float prixArtPanier[],int nbArt[], int tlog, int tlogPanier, int tlogV,int tabRefV[],int tabNbArtV[],float prixArtPanierV[], int refAAjouter[], int stockAAjouter[],int seuilAAjouter[],float prixUAAjouter[]);
/**
 * @brief Décrémente le stock selon le panier et calcule le total.
 * @param tabRef Tableau des références.
 * @param tabStock Tableau des quantités en stock.
 * @param tabPrixU Tableau des prix unitaires.
 * @param panier Tableau des références sélectionnées.
 * @param prixPanier Tableau des prix totaux par article (sortie).
 * @param nbArticles Tableau des quantités par article du panier.
 * @param tlog Taille logique des références.
 * @param tlogPanier Nombre d'articles dans le panier.
 * @return Montant total de la commande.
 */
int passerCommande(int tabRef[], int tabStock[], float tabPrixU[],int panier[], float prixPanier[], int nbArticles[], int tlog,int tlogPanier);

/**
 * @brief Affiche le récapitulatif de la commande.
 * @param panier Références commandées.
 * @param prixPanier Prix totaux par article.
 * @param nbArticles Quantités par article.
 * @param tlogPanier Nombre d'articles du panier.
 */
void recapCommande(int panier[],float prixPanier[], int nbArticles[], int tlogPanier);

/**
 * @brief Affiche le menu de l'historique des ventes et gère les choix d'affichage.
 * @param tabRefV Tableau des références vendues.
 * @param tabNbArtV Tableau des quantités vendues.
 * @param prixTotalV Tableau des prix totaux par vente.
 * @param tlogV Taille logique de l'historique.
 */
void historique(int tabRefV[],int tabNbArtV[],float prixTotalV[], int tlogV);

/**
 * \brief Affiche les n dernières commandes de l'historique
 * \param[in] tabRefV Tableau des références de commandes
 * \param[in] tabNbArtV Tableau des nombres d'articles par commande
 * \param[in] prixTotalV Tableau des prix totaux par commande
 * \param[in] tlogV Taille logique des tableaux
 * \param[in] n Nombre de commandes à afficher (les n plus récentes)
 * 
 * Cette fonction affiche les n commandes les plus récentes avec un formatage
 * tabulaire élégant. Si n est supérieur au nombre de commandes disponibles,
 * toutes les commandes sont affichées. Les commandes sont affichées de la
 * plus récente à la plus ancienne.
 */
void affichXComm(int tabRefV[], int tabNbArtV[], float prixTotalV[], int tlogV, int n);

/**
 * \brief Saisie contrôlée de la référence et de la quantité d'un produit
 * 
 * Cette fonction demande à l'utilisateur de saisir la référence d'un produit 
 * et la quantité à ajouter lors d'une livraison par camion.
 * La saisie est validée pour éviter les valeurs négatives.
 * 
 * \param[out] ref Pointeur vers la variable qui stockera la référence saisie
 * \param[out] quantite Pointeur vers la variable qui stockera la quantité saisie
 * \return 1 si la saisie est valide, 0 si l'utilisateur souhaite quitter (référence = 0),
 *         -1 si la référence est invalide (négative)
 * 
 * \note La fonction gère la saisie de la quantité avec validation pour éviter les valeurs négatives
 */
int saisieRefEtQuantite(int *ref, int *quantite);

/**
 * \brief Saisie contrôlée du prix unitaire et du seuil de sécurité d'un produit
 * 
 * Cette fonction demande à l'utilisateur de saisir le prix unitaire et le seuil de sécurité
 * d'un nouveau produit lors d'une livraison par camion.
 * Les saisies sont validées pour éviter les valeurs négatives.
 * 
 * \param[out] prix Pointeur vers la variable qui stockera le prix unitaire saisi
 * \param[out] seuil Pointeur vers la variable qui stockera le seuil de sécurité saisi
 * 
 * \note Les deux valeurs sont validées et doivent être positives ou nulles
 * \warning Cette fonction est destinée aux nouveaux produits uniquement
 */
void saisiePrixEtSeuil(float *prix, int *seuil);

/**
 * \brief Saisie d'une commande à livrer par camion
 * 
 * Cette fonction permet de saisir une commande complète pour livraison par camion.
 * Elle gère à la fois les produits existants (seulement référence et quantité)
 * et les nouveaux produits (toutes les informations).
 * 
 * \param[in] tabRef Tableau des références des produits existants
 * \param[in] tlog Taille logique du tableau des produits existants
 * \param[out] ref Pointeur vers la référence temporaire
 * \param[out] stock Pointeur vers le stock temporaire
 * \param[out] seuil Pointeur vers le seuil temporaire
 * \param[out] prix Pointeur vers le prix temporaire
 * \param[out] refAAjouter Tableau des références à ajouter
 * \param[out] stockAAjouter Tableau des stocks à ajouter
 * \param[out] seuilAAjouter Tableau des seuils à ajouter
 * \param[out] prixUAAjouter Tableau des prix unitaires à ajouter
 * \return Le nombre de nouveaux éléments saisis
 * 
 * \note La fonction s'arrête si l'utilisateur saisit la référence 0
 */
int saisieCamion(int tabRef[], int tlog, int *ref, int *stock, int *seuil, float *prix, 
                int refAAjouter[], int stockAAjouter[], int seuilAAjouter[], float prixUAAjouter[]);

/**
 * \brief Intègre une livraison par camion dans le stock
 * 
 * Cette fonction ajoute les produits d'une livraison par camion dans le stock principal.
 * Pour les produits existants, elle met à jour seulement la quantité.
 * Pour les nouveaux produits, elle les ajoute complètement au stock.
 * 
 * \param[in,out] tabRef Tableau des références des produits
 * \param[in,out] tabStock Tableau des stocks des produits
 * \param[in,out] tabPrixU Tableau des prix unitaires des produits
 * \param[in,out] tabSeuil Tableau des seuils de sécurité des produits
 * \param[in] tlog Taille logique actuelle des tableaux
 * \param[in] refAAjouter Tableau des références à ajouter
 * \param[in] stockAAjouter Tableau des stocks à ajouter
 * \param[in] prixUAAjouter Tableau des prix unitaires à ajouter
 * \param[in] seuilAAjouter Tableau des seuils à ajouter
 * \param[in] tlogNvElements Nombre de nouveaux éléments à intégrer
 * \return La nouvelle taille logique des tableaux, ou -2 si le tableau est plein
 * 
 * \note En cas de tableau plein, la fonction retourne -2 et arrête l'intégration
 */
int livraisonCamion(int tabRef[], int tabStock[], float tabPrixU[], int tabSeuil[], int tlog,
                   int refAAjouter[], int stockAAjouter[], float prixUAAjouter[], 
                   int seuilAAjouter[], int tlogNvElements);

/**
 * \brief Recherche et affiche le produit le plus cher ou le moins cher
 * \param[in] tabRef Tableau des références
 * \param[in] tabPrixU Tableau des prix unitaires
 * \param[in] tlog Taille logique du tableau
 * 
 * Cette fonction permet à l'utilisateur de choisir s'il veut voir le produit
 * le plus cher ou le moins cher, puis l'affiche avec un formatage visuel.
 */
void minMaxPrix(int tabRef[], float tabPrixU[], int tlog);

/**
 * \brief Affiche un produit (le plus cher ou le moins cher) avec formatage
 * \param[in] ref Référence du produit à afficher
 * \param[in] prix Prix du produit à afficher
 * \param[in] ifPlusCher 1 pour produit le plus cher, 0 pour le moins cher
 * 
 * Cette fonction affiche élégamment les informations d'un produit avec
 * un encadrement visuel et des emojis.
 */
void affichMinMax(int ref, float prix, int ifPlusCher);

/**
 * \brief Applique des remises sur des produits spécifiques
 * \param[in,out] tabRef Tableau des références
 * \param[in,out] tabPrixU Tableau des prix unitaires (modifié par les remises)
 * \param[in] tlog Taille logique du tableau
 * 
 * Cette fonction permet d'appliquer interactivement des pourcentages de remise
 * sur des produits spécifiques identifiés par leur référence.
 */
void appliquerSoldes(int tabRef[], float tabPrixU[], int tlog);

/**
 * \brief Saisie interactive des paramètres de remise
 * \param[out] remise Pointeur vers le pourcentage de remise
 * \param[out] choix Pointeur vers le choix de l'utilisateur
 * 
 * Cette fonction gère la saisie et la validation du pourcentage de remise
 * et de la confirmation de l'utilisateur.
 */
void saisieSoldes(int *remise, char *choix);

/**
 * @brief Lance le flux global de gestion de stock et de commandes.
 */
void global(void);
