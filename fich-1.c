#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fich.h"


// 1. Initialisation de la liste chaînée
ListeChainee* initialiserListe() {
    ListeChainee* liste = (ListeChainee*)malloc(sizeof(ListeChainee));
    if (liste != NULL) {
        liste->tete = NULL;
    }
    return liste;
// 2. Insertion en tête
void insererEnTete(ListeChainee* liste, int valeur) {
    if (liste == NULL) return;
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL) {
        printf("Erreur d'allocation mémoire\n");
        }
    nouveauNoeud->donnee = valeur;
    nouveauNoeud->suivant = NULL;
    // Si la liste est vide
    if (liste->tete == NULL) {
        liste->tete = nouveauNoeud;
        return;
    }
    // Parcourir jusqu'au dernier nœud
    Noeud* courant = liste->tete;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    / 4. Insertion à une position spécifique
void insererAPosition(ListeChainee* liste, int valeur, int position) {
    if (liste == NULL || position < 0) {
        printf("Position invalide\n");
        return;
    }
    // Si insertion en tête
    if (position == 0) {
        insererEnTete(liste, valeur);
        return;
    }
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    nouveauNoeud->donnee = valeur; 
    // Trouver le nœud à la position précédente
    Noeud* courant = liste->tete;
    int i;
    for (i = 0; i < position - 1 && courant != NULL; i++) {
        courant = courant->suivant;
    }
    if (courant == NULL) {
        printf("Position hors limites\n");
        free(nouveauNoeud);
        return;
     }
    nouveauNoeud->suivant = courant->suivant;
    courant->suivant = nouveauNoeud;
}
// 5. Tri de la liste (tri à bulles)
void trierListe(ListeChainee* liste) {
    if (liste == NULL || liste->tete == NULL) return;
    
    int echange;
    Noeud* pointeur;
    Noeud* dernierTrie = NULL;
    
    do {
        echange = 0;
        pointeur = liste->tete;
        do {
        echange = 0;
        pointeur = liste->tete;
        
        while (pointeur->suivant != dernierTrie) {
            if (pointeur->donnee > pointeur->suivant->donnee) {
                // Échanger les valeurs
                int temp = pointeur->donnee;
                pointeur->donnee = pointeur->suivant->donnee;
                pointeur->suivant->donnee = temp;
                echange = 1;
            }
            pointeur = pointeur->suivant;
        }
        dernierTrie = pointeur;
    } while (echange);
}
// 6. Afficher la liste
void afficherListe(ListeChainee* liste) {
    if (liste == NULL || liste->tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    Noeud* courant = liste->tete;
    printf("Liste: ");
    while (courant != NULL) {
        printf("%d", courant->donnee);
        if (courant->suivant != NULL) {
            printf(" -> ");
          }
        courant = courant->suivant;
    }
    printf("\n");
}
// Fonction pour libérer la mémoire de la liste
void libererListe(ListeChainee* liste) {do {
        echange = 0;
        pointeur = liste->tete;
        
        while (pointeur->suivant != dernierTrie) {
            if (pointeur->donnee > pointeur->suivant->donnee) {
                // Échanger les valeurs
                int temp = pointeur->donnee;
                pointeur->donnee = pointeur->suivant->donnee;
                pointeur->suivant->donnee = temp;
                echange = 1;
            }
             pointeur = pointeur->suivant;
        }
        dernierTrie = pointeur;
    } while (echange);
}
    if (liste == NULL) return;
    
    Noeud* courant = liste->tete;
    Noeud* suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    free(liste);
}
   
   
  // LISTE SIMPLEMENT CHAINE
  
  / Crée une liste circulaire
List new_circular_list(void) {
    return NULL; // Une liste vide est représentée par NULL
}

 Vérifie si la liste est vide
Bool is_empty_circular_list(List li) {
    return li == NULL;
}

// Ajoute un élément à la fin de la liste
List push_back_circular_list(List li, int x) {
    ListElement *new_element = malloc(sizeof(ListElement));
    new_element->value = x;
    
    if (is_empty_circular_list(li)) {
        new_element->next = new_element; // Pointe vers lui-même
        return new_element;
    }

    ListElement *current = li;
    while (current->next != li) {
        current = current->next;
    }
    current->next = new_element;
    new_element->next = li; // Ferme la boucle
    return li;
}

// Ajoute un élément au début de la liste
List push_front_circular_list(List li, int x) {
    ListElement *new_element = malloc(sizeof(ListElement));
    new_element->value = x;

    if (is_empty_circular_list(li)) {
        new_element->next = new_element; // Pointe vers lui-même
        return new_element;
    }

    ListElement *current = li;
    while (current->next != li) {
        current = current->next;
    }
    current->next = new_element; // Relie le dernier à nouveau
    new_element->next = li; // Nouveau élément pointe vers l'ancien premier
    return new_element; // Nouveau premier
}

// Supprime le dernier élément de la liste
List pop_back_circular_list(List li) {
    if (is_empty_circular_list(li)) return li;

    if (li->next == li) { // Un seul élément
        free(li);
        return NULL;
    }

    ListElement *current = li;
    while (current->next->next != li) {
        current = current->next;
    }
    free(current->next);
    current->next = li; // Met à jour la boucle
    return li;
}

// Supprime le premier élément de la liste
List pop_front_circular_list(List li) {
    if (is_empty_circular_list(li)) return li;

    if (li->next == li) { // Un seul élément
        free(li);
        return NULL;
    }

    ListElement *to_delete = li;
    ListElement *current = li;

    while (current->next != li) {
        current = current->next;
    }
    li = li->next; // Met à jour le premier élément
    current->next = li; // Met à jour le dernier élément
    free(to_delete);
    return li;
}

// Recherche un élément dans la liste
ListElement* search_in_circular_list(List li, int x) {
    if (is_empty_circular_list(li)) return NULL;

    ListElement *current = li;
    do {
        if (current->value == x) {
            return current; // Éléments trouvé
        }
        current = current->next;
    } while (current != li);
    return NULL; // Non trouvé
}
 }
        last->next = sorted; // Ferme la boucle
    }
    return sorted;
}

// Affiche les éléments de la liste
void print_circular_list(List li) {
    if (is_empty_circular_list(li)) {
        printf("La liste est vide.\n");
        return;
    }

    ListElement *current = li;
    do {
        printf("%d -> ", current->value);
        current = current->next;
    } while (current != li);
    printf("(Retour à la tête)\n");
}

// Nettoie la liste
List clear_circular_list(List li) {
    while (!is_empty_circular_list(li)) {
        li = pop_front_circular_list(li);
    }
    return li;
}

    
 // LISTE DOUBLEMENT CHAINE
 ==========================
//Initialiser une liste vide
void initialiserListe(Liste* liste){
        liste->head = NULL;
        liste->head = NULL;
}

//Creer un nouveau noeud
Node* creerNode(int valeur){
     Node* newNode = (Node*)malloc(sizeof(Node));
     if(newNode == NULL){
         printf("Erreur d'allocation memoire\n");
         exit(EXIT_FAILURE);
     }
     newNode->data = valeur;
     newNode->prev = NULL;
     newNode->next = NULL;
     return newNode;
}

//Insertion en tete
void insertionEnTete(Liste* liste, int valeur){
    Node* newNode = creerNode(valeur);
    if(liste->tail == NULL){
        liste->head = liste->tail = newNode;
    }else{
        liste->tail->next = newNode;
        newNode->prev = liste->tail;
        liste->tail = newNode;
    }
}

//Insertion en queue
void insertionEnQueue(Liste* liste, int valeur){
     Node* newNode = creerNode(valeur);
     if(liste->tail == NULL){
          liste->head = liste->tail = newNode;
     }else{
          liste->tail->next = newNode;
          newNode->prev = liste->tail;
          liste->tail = newNode;
      }
}

//Tri de la liste (par ordre croissant) avec le tri à bulles
void trierListe(Liste* liste){
   if(liste->head == NULL){
        int permut;
        Node* ptr;
        Node* last = NULL;
        do{
            permut = 0;
            ptr = liste->head;
            
            while (ptr->next != last){
                  if(ptr->data > ptr->next->data){
                       int temp =ptr->data;
                       ptr->data = ptr->next->data;
                       ptr->next->data = temp;
                       permut = 1;
                  }
                  ptr = ptr->next;
        }
        last = ptr;
   }while (permut);
}

void afficherListe(Liste* liste){
     Node* temp = liste->head;
     printf("Liste:");
     while (temp != NULL){
         temp = temp->next;
     }
     printf("\n");
     
}
// SUPPRESSION
// EN TÊTE DE LISTE
Noeud* supprimerEnTete(Noeud* tete) {
    if (!tete) return NULL;
    Noeud* suivant = tete->suivant;
    free(tete);
    if (suivant) suivant->precedent = NULL;
    return suivant;
}

// EN UNE POSITION DONNÉE
Noeud* supprimerEnPosition(Noeud* tete, int position) {
    if (!tete || position < 0) return tete;
    if (position == 0) return supprimerEnTete(tete);

    Noeud* courant = tete;






// ==============================
// LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE
// ==============================

// INITIALISATION DE LA LISTE
ListeCirculaire* initialiserListeCirculaire() {
    ListeCirculaire* liste = malloc(sizeof(ListeCirculaire));
    liste->tete = NULL;
    return liste;
}

// INSERTION
// EN TÊTE
void insererEnTeteCirculaire(ListeCirculaire* liste, int valeur) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    nouveau->valeur = valeur;

    if (!liste->tete) {
        nouveau->suivant = nouveau;
        nouveau->precedent = nouveau;
        liste->tete = nouveau;
    } else {
     Noeud* dernier = liste->tete->precedent;
        nouveau->suivant = liste->tete;
        nouveau->precedent = dernier;
        dernier->suivant = nouveau;
        liste->tete->precedent = nouveau;
        liste->tete = nouveau;
    }
}

// EN QUEUE
void insererEnQueueCirculaire(ListeCirculaire* liste, int valeur) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    nouveau->valeur = valeur;

    if (!liste->tete) {
        nouveau->suivant = nouveau;
         nouveau->precedent = nouveau;
        liste->tete = nouveau;
    } else {
        Noeud* dernier = liste->tete->precedent;
        nouveau->suivant = liste->tete;
        nouveau->precedent = dernier;
        dernier->suivant = nouveau;
        liste->tete->precedent = nouveau;
    }
}

// AFFICHAGE DE LA LISTE CIRCULAIRE
void afficherListeCirculaire(ListeCirculaire* liste) {
    if (!liste->tete) {
        printf("La liste circulaire est vide.\n");
        return;
    }

    Noeud* courant = liste->tete;
    do {
        printf("%d ", courant->valeur);
        courant = courant->suivant;
    } while (courant != liste->tete);
    printf("\n");
}

struct Node* InsertionenVide(int data){
   struct Node* temp=malloc(sizeof(struct Node));
   temp->prev=temp;
   temp->data=data;
   temp->next=temp;
   return temp;
   }
   
 struct Node* InsertionenTete(struct Node* tail,int data){
   struct Node* newp=InsertionenVide(data);
   if(tail==NULL){
     return newP;
     }
   else{
     struct Node* temp=tail->next;
     
     newP->prev=tail;
     newP->next=temp;
     temp->prev=newP;
     tail->next=newP;
     return tail;
    }
   }
   
struct Node* InsertionenQueue(struct Node* tail,int data){
     struct Node* newP=InsertionenVide(data);
     if(tail==NULL){
      return newP;
      }
     else
     {
       struct Node* temp=tail->next;
       newP->next=temp;
       newP->prev=tail;
       tail->next=newP;
       tail->prev=newP;
       tail=newP;
       return tail;
      }
    }
  
struct Node* InsertionaPosition(struct Node* tail,int data,int pos){
    struct Node* newP=InsertionenVide(data);
    if(tail==NULL){
     return newP;
     }
    struct Node* temp=tail->next;
    while(pos>1){
     temp=temp->next;
     pos--;
     }
    newP->prev=temp;
    newP->next=temp->next;
    temp->next->prev=newP;
    temp->next=newP;
    if(temp==tail)
       tail=tail->next;
       return tail;
     }
     
void affichage(struct Node* tail){
 if(tail==NULL){
  printf("No Node in the list");
 }
 else{
    struct Node* temp=tail->next;
 
 do{
  printf("%d",temp->data);
  temp=temp->next;
  }
  while(temp!=tail->next);
 }
  printf("\n");
  }
 
