#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // déclaration des variables
    int i;
    char ligne[30];
    char mon_fichier[] = "verification.txt";

    FILE *fptr;
    FILE *fichier;

    char compar[30];
    int choixP;
    int numero[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    char *place[30] = {
        "linge1 chaise1", "linge1 chaise2", "linge1 chaise3",
        "linge2 chaise1", "linge2 chaise2", "linge2 chaise3",
        "linge3 chaise1", "linge3 chaise2", "linge3 chaise3",
        "linge4 chaise1", "linge4 chaise2", "linge4 chaise3",
        "linge5 chaise1", "linge5 chaise2", "linge5 chaise3",
        "linge6 chaise1", "linge6 chaise2", "linge6 chaise3",
        "linge7 chaise1", "linge7 chaise2", "linge7 chaise3",
        "linge8 chaise1", "linge8 chaise2", "linge8 chaise3",
        "linge9 chaise1", "linge9 chaise2", "linge9 chaise3",
        "linge10 chaise1", "linge10 chaise2", "linge10 chaise3"
    };

    // affichage message
    printf("NUMERO  VOICI UNE LISTE DES SIEGES: \n\n");

    // affichage des éléments du tableau place
    for (i = 0; i < 30; i++) {
        printf("%d\t %s\n\n", numero[i], place[i]);
    }

    // affichage d'un message qui permet à l'utilisateur de choisir une place
    printf("VEUILLEZ CHOISIR UN SIEGE SELON LE NUMERO DES SIEGES: ");
    // Récupération de la valeur saisie par l'utilisateur
    scanf("%d", &choixP);

    // utilisation de la boucle while pour contrôler la saisie de l'utilisateur
    while (!(choixP >= 1 && choixP <= 30)) {
        printf("Entrer un nombre compris entre 1 et 30 : ");
        scanf("%d", &choixP);
    }

    fichier = fopen(mon_fichier, "r");
    if (fichier == NULL) {
        printf("ERREUR lors de l'ouverture du fichier.");
        return 1;
    }

    while (fgets(ligne, 30, fichier) != NULL) {
        sprintf(compar, "%d", choixP);
        if (strstr(ligne, compar) != NULL) {
            printf("Cette place est déjà prise veuillez en choisir une autre.\n");
            scanf("%d", &choixP);
            break;
        }
        printf("votere place a bien été réserver !");
    }

    fclose(fichier);

    fptr = fopen("verification.txt", "w");
    if (fptr == NULL) {
        printf("ERREUR lors de l'ouverture du fichier.");
        return 1;
    }

    fprintf(fptr, "%d", choixP);

    fclose(fptr);

    return 0;
}
