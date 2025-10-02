#ifndef LISTE_DOUBLE_H
#define LISTE_DOUBLE_H

// Structure d'un nœud de la liste chaînée
typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
} Noeud;

// Structure de la liste chaînée
typedef struct {
    Noeud* tete;
} ListeChainee;

//Définition de la structure d'un noeud d'une liste doublement chainé
typedef struct Node{
     int data;
     struct Node* prev;
     struct Node* next;
}Node;

//Définition de la structure Liste
typedef struct{
   Node* head;
   Node* tail;
}Liste;


// LISTE SIMPLEMENT CHAINE CIRCULAIRE
typedef enum { false, true } Bool;

typedef struct ListElement {
    int value;
    struct ListElement *next;
} ListElement, *List; // Pour masquer le pointeur sur ListElement



// Structure pour une liste doublement chaînée circulaire
typedef struct Node {
  struct Node *prec;
  int data;
  struct Node *suiv;
}Node;
   
typedef struct ListeCirculaire {
    Noeud* tete;
} ListeCirculaire;

//Prototypes
ListeChainee* initialiserListe();
void insererEnTete(ListeChainee* liste, int valeur);
void insererALaQueue(ListeChainee* liste, int valeur);
void insererAPosition(ListeChainee* liste, int valeur, int position);
void trierListe(ListeChainee* liste);
void afficherListe(ListeChainee* liste);
void libererListe(ListeChainee* liste);

//Liste doublement chainé
void initialiserListe(Liste* liste);
Node* creerNode(int valeur);
void insertionEnTete(Liste* liste, int valeur);
void insertionEnQueue(Liste* liste, int valeur);
void trierListe(Liste* liste);

// SUPPRESSION
Noeud* supprimerEnTete(Noeud* tete);
Noeud* supprimerEnPosition(Noeud* tete, int position);
Noeud* supprimerEnQueue(Noeud* tete);

// AFFICHAGE
void afficherTous(Noeud* tete);
void afficherElement(Noeud* tete, int position);

// RECHERCHE
Noeud* rechercher(Noeud* tete, int valeur);


// PROTOTYOES D'UNE LISTE SIMPLEMENT CHAINE
ist new_circular_list(void);

Bool is_empty_circular_list(List li);

List push_back_circular_list(List li, int x);

List push_front_circular_list(List li, int x);

List pop_back_circular_list(List li);

List pop_front_circular_list(List li);

ListElement* search_in_circular_list(List li, int x);

List sort_circular_list(List li);

void print_circular_list(List li);

List clear_circular_list(List li);


// LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE
// ==============================

// INITIALISATION
ListeCirculaire* initialiserListeCirculaire();

// INSERTION
void insererEnTeteCirculaire(ListeCirculaire* liste, int valeur);
void insererEnQueueCirculaire(ListeCirculaire* liste, int valeur);
void afficherListeCirculaire(ListeCirculaire* liste);

truct Node* ajouterEnTete(struct Node* tail,int data);
struct Node* ajouterEnqueue(struct Node* tail,int data);
struct Node* trierListe(struct Node* tail);
struct Node* supprimerTete(struct Node* tail);
struct Node* supprimerQueue(struct Node* tail);
struct Node* supprimerPosition(struct Node* tail, int pos);
struct Node* rechercher(struct Node* tail, int valeur);



#endif



