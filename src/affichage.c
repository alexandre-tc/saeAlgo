#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"

int menu(void) { //alexandre
    
    int choix;

    printf("\n");
    printf("                🏪 GESTION DES STOCKS 🏪\n");
    printf("                ========================\n\n");

    printf("   1.  📥    Ajouter un produit\n");
    printf("   2.  📊    État du stock\n");
    printf("   3.  ⚠️     Produits en risque de rupture\n");
    printf("   4.  ✏️     Modifier des données\n");
    printf("   5.  🗑️     Supprimer un produit\n");
    printf("   6.  🛒    Traiter une commande\n");
    printf("   7.  📦    Réapprovisionnement\n");
    printf("   8.  📈    Historique des ventes\n");
    printf("   9.  💎    Produit le plus/moins cher\n");
    printf("   10. 🏷️     Appliquer des soldes\n");
    printf("   11. ⭐    Fonctionnalités d'avis\n");
    printf("   12. 🚪    Quitter\n");

    printf("\n");
    printf("   ──────────────────────────────────\n");
    printf("   Votre choix : ");
    scanf("%d%*c", &choix);

    while (choix < 1 || choix > 12)
    {
        printf("   ❌ Choix invalide ! Réessayez : ");
        scanf("%d%*c", &choix);
    }
    
    printf("\n");
    return choix;
}

void afficherAjoutProduit() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║       ➕  AJOUT D'UN PRODUIT           ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  📝 Veuillez saisir les informations du nouveau produit.\n\n");
}

void afficherEtatStock() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║         📦  ÉTAT DU STOCK              ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
}

void afficherProduitsRisque() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║    ⚠️  PRODUITS EN RISQUE DE RUPTURE   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  ⚠️  Liste des produits dont le stock atteint le seuil critique.\n\n");
}

void afficherModificationDonnees() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║      ✏️  MODIFICATION DES DONNÉES       ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  📝 Sélectionnez le produit à modifier.\n\n");
}

void afficherSuppressionProduit() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║      🗑️  SUPPRESSION D'UN PRODUIT      ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  ⚠️  Attention : cette action est irréversible !\n\n");
}

void afficherTraitementCommande() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║      🛒  TRAITEMENT DE COMMANDE        ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  📦 Le stock sera automatiquement mis à jour.\n\n");
}

void afficherReapprovisionnementCamion() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   🚚  RÉAPPROVISIONNEMENT PAR CAMION   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  📝 Veuillez saisir les informations pour le réapprovisionnement.\n\n");
}

void afficherHistoriqueVentes() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   📜  HISTORIQUE DES VENTES            ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  🛒 Voici l'historique des ventes enregistrées.\n\n");
}

void afficherProduitMinMax() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   💰  PRODUIT LE PLUS CHER / MOINS CHER║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  🔍 Sélectionnez si vous voulez voir le produit le plus cher ou le moins cher.\n\n");
}

void afficherApplicationSoldes() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   🏷️  APPLICATION DE SOLDES            ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  💸 Appliquez des réductions sur certaines références.\n\n");
}


void afficherFonctionnalitesAvis() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   ⭐  FONCTIONNALITÉS D'AVIS           ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  📝 Accédez aux fonctionnalités liées aux avis des produits.\n\n");
}

void afficherQuitter() { //alexandre
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║    👋  FERMETURE DU PROGRAMME          ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  ✨ Merci d'avoir utilisé le gestionnaire de stock.\n");
    printf("  👋 À bientôt !\n\n");
}