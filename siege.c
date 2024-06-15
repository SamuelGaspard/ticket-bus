#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NB_SIEGES 50 // Nombre de si�ges dans le bus

// Structure pour repr�senter les pr�f�rences de l'utilisateur
typedef struct preferences {

  bool fenetre; // Pr�f�rence pour un si�ge c�t� fen�tre
  bool couloir; // Pr�f�rence pour un si�ge c�t� couloir
} preferences_t;

// Structure pour repr�senter un si�ge dans le bus
typedef struct siege {
  int numero;      // Num�ro du si�ge
  bool occupe;     // Indique si le si�ge est occup�
  bool coteFenetre; // Indique si le si�ge est c�t� fen�tre
} siege_t;

// Fonction pour initialiser les si�ges du bus
void initialiser_sieges(siege_t bus[NB_SIEGES]) {
  for (int i = 0; i < NB_SIEGES; i++) {
    bus[i].numero = i + 1;
    bus[i].occupe = false;
    bus[i].coteFenetre = (i % 2 == 0); // Les si�ges pairs sont c�t� fen�tre
  }
}

// Fonction pour afficher l'�tat d'occupation des si�ges
void afficher_sieges(siege_t bus[NB_SIEGES]) {
  printf("Etat des sieges:\n");
  for (int i = 0; i < NB_SIEGES; i++) {
    printf("Siege %d: ", bus[i].numero);
    if (bus[i].occupe) {
      printf("Occupe");
    } else {
      printf("Libre");
    }
    if (bus[i].coteFenetre) {
      printf(" (cote fenetre)");
    } else {
      printf(" (cote couloir)");
    }
    printf("\n");
  }
}

// Fonction pour attribuer un si�ge en fonction des pr�f�rences
int attribuer_siege(siege_t bus[NB_SIEGES], preferences_t pref) {
  for (int i = 0; i < NB_SIEGES; i++) {
    if (!bus[i].occupe &&
        ((pref.fenetre && !bus[i].coteFenetre) ||
         (pref.couloir && bus[i].coteFenetre))) {
      bus[i].occupe = true;
      return bus[i].numero;
    }
  }
  return -1; // Aucun si�ge disponible selon les pr�f�rences
}

// Fonction pour attribuer un si�ge al�atoire
int attribuer_siege_aleatoire(siege_t bus[NB_SIEGES]) {
  int i;
  do {
    i = rand() % NB_SIEGES;
  } while (bus[i].occupe);

  bus[i].occupe = true;
  return bus[i].numero;
}

int main() {
  siege_t bus[NB_SIEGES];
  initialiser_sieges(bus);

  // Demander les pr�f�rences de l'utilisateur (optionnel)
  preferences_t prefUtilisateur;
  printf("Voulez-vous choisir vos preferences de siege ? (oui/non) : ");
  char choixPreference[10];
  scanf("%s", choixPreference);

  if (strcmp(choixPreference, "oui") == 0) {
    printf("Preferences de l'utilisateur:\n");
    printf("Siege cote fenetre (oui/non) ?: ");
    scanf("%d", &prefUtilisateur.fenetre);
    printf("Siege cote couloir (oui/non) ?: ");
    scanf("%d", &prefUtilisateur.couloir);
  }

  // Attribuer un si�ge
  int numeroSiege;
  if (strcmp(choixPreference, "oui") == 0) {
    numeroSiege = attribuer_siege(bus, prefUtilisateur);
  } else {
    numeroSiege = attribuer_siege_aleatoire(bus);
  }

  if (numeroSiege != -1) {
    printf("Siege attribue : %d\n", numeroSiege);
    afficher_sieges(bus);
  } else {
    printf("Aucun siege disponible.\n");
  }

  return 0;
}
