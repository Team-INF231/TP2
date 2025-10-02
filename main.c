#include <stdio.h>
#include <stdlib.h>
#include "fich.h"

void afficherMenu() {
    printf("Choisissez une action :\n");
    printf("1. Insertion en tête (Liste simplement chaînée)\n");
    printf("2. Insertion à une position (Liste simplement chaînée)\n");
    printf("3. Tri de la liste (Liste simplement chaînée)\n");
    printf("4. Afficher la liste (Liste simplement chaînée)\n");
    printf("5. Ajouter un élément en fin (Liste circulaire)\n");
    printf("6. Afficher la liste (Liste circulaire)\n");
    printf("7. Insertion en tête (Liste doublement chaînée)\n");
    printf("8. Afficher la liste (Liste doublement chaînée)\n");
    printf("9. Quitter\n");
}

int main() {
    int choix;
    int valeur, position;
    ListeChainee* listeSimple = initialiserListe();
    List listeCirculaire = new_circular_list();
    Liste listeDouble;
    
    // Initialiser la liste double
    initialiserListe(&listeDouble);

    do {
        afficherMenu();
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à insérer en tête : ");
                scanf("%d", &valeur);
                insererEnTete(listeSimple, valeur);
                break;

            case 2:
                printf("Entrez la valeur à insérer : ");
                scanf("%d", &valeur);
                printf("Entrez la position : ");
                scanf("%d", &position);
                insererAPosition(listeSimple, valeur, position);
                break;

            case 3:
                trierListe(listeSimple);
                printf("Liste triée.\n");
                break;

            case 4:
                afficherListe(listeSimple);
                break;

            case 5:
                printf("Entrez la valeur à ajouter en fin (Liste circulaire) : ");
                scanf("%d", &valeur);
                listeCirculaire = push_back_circular_list(listeCirculaire, valeur);
                break;

            case 6:
                printf("Liste circulaire :\n");
                print_circular_list(listeCirculaire);
                break;

            case 7:
                printf("Entrez la valeur à insérer en tête (Liste doublement chaînée) : ");
                scanf("%d", &valeur);
                insertionEnTete(&listeDouble, valeur);
                break;

            case 8:
                printf("Liste doublement chaînée :\n");
                afficherListe(&listeDouble);
                break;

            case 9:
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 9);

    // Libération de mémoire
    libererListe(listeSimple);
    listeCirculaire = clear_circular_list(listeCirculaire);
    // Si vous avez une fonction pour libérer la liste doublement chaînée, appelez-la ici.
    
    return 0;
}
