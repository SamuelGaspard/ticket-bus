#include <stdio.h>
#include <stdlib.h>

// Structure pour les informations de r�servation
struct RESERVATION {
    char NOM[20];
    char POST_NOM[20];
    char PRENOM[20];
    int destinationIndex; // Index pour la destination choisie
    int heureDepartIndex; // Index pour l'heure de d�part choisie
};

int main() {
    struct RESERVATION user;
    char *destinations[] = {
        "LUBUMBASHI-LIKASI",
        "LUBUMBASHI-KOLWEZI",
        "LUBUMBASHI-KASUMBALESA",
        "LUBUMBASHI-FUNGURUME",
        "KOLWEZI-LUBUMBASI",
        "KOLWEZI-FUNGURUME",
        "KOLWEZI-LIKASI"
    };
    char *tarifs[] = {
        "15000FC",
        "40000FC",
        "15000FC",
        "10000FC",
        "40000FC",
        "25000FC",
        "15000FC"
    };
    char *Heure_de_Depart[] = {
        "06h00",
        "08h00",
        "10h00",
        "12h00",
        "14h00",
        "16h00",
        "18h00"
    };

    system("color 75");
    printf("\n\n\n");
    printf("\t\t\t BIENVENUE SUR NOTRE APPLICATION DE RESEVATION DE BUS PAR MOBILEMONEY ��  \n\t\t");
    printf("\t=====================================================================\n\t");
    printf("\n\n");
    printf("\t\t\t\t\tVEILLEZ COMPLETER CES INFORMATIONS :\n\t\t");
    printf("\t\t\t=======================================\n\t");
    printf("\n");

    // Demander les informations personnelles
    printf("\x1b[30;47m");
    printf("\tNOM : ");
    scanf("%s", user.NOM);
    printf("\tPOSTNOM : ");
    scanf("%s", user.POST_NOM);
    printf("\tPRENOM : ");
    scanf("%s", user.PRENOM);

    // Afficher les destinations disponibles et demander � l'utilisateur de choisir
    printf("\tDESTINATIONS DISPONIBLES:\n");
    printf("\n");
    for(int i = 0; i < 7; i++) {
        printf("\t%d. %s - %s\n", i+1, destinations[i], tarifs[i]);
    }
    printf("\n");
    printf("\tCHOISISSEZ VOTRE DESTINATION (1-7): ");
    scanf("%d", &user.destinationIndex);
    printf("\n");
    // V�rifier si le choix est valide
    if(user.destinationIndex < 1 || user.destinationIndex > 7) {
        printf("CHOIX INVALIDE. VEILLEZ ENTRER UN NOMBRE ENTRE 1 ET 7.\n");
        return 1; // Terminer le programme si le choix est invalide
    }
    printf("\n");
    // Ajuster l'index pour l'utiliser avec les tableaux
    user.destinationIndex--;

     // Afficher les heures de d�part disponibles et demander � l'utilisateur de choisir
     printf("\tHEURES DE DEPART DISPONIBLES:\n");
     for(int i = 0; i < 7; i++) {
         printf("\n");
         printf("\t%d. %s\n", i+1, Heure_de_Depart[i]);
     }
     printf("\n");
     printf("\tCHOISISSEZ UNE HEURE DE DEPART (1-7): ");
     scanf("%d", &user.heureDepartIndex);

     // V�rifier si le choix est valide

     if(user.heureDepartIndex < 1 || user.heureDepartIndex > 7) {
         printf("CHOIX INVALIDE. VEILLEZ ENTRER UN NOMBRE ENTRE 1 ET 7.\n");
         return 1; // Terminer le programme si le choix est invalide
     }

     // Ajuster l'index pour l'utiliser avec les tableaux
     user.heureDepartIndex--;
      printf("\n");
     // Afficher la confirmation de la r�servation avec la destination, l'heure de d�part et le tarif choisis
     printf("VOUS AVEZ RESERVER UN BUS VERS %s A %s POUR UN MONTANT DE  %s.\n", destinations[user.destinationIndex], Heure_de_Depart[user.heureDepartIndex], tarifs[user.destinationIndex]);

     return 0;
}
int main() {
    FILE *file;
    file = fopen("base_de_donnees.txt", "r"); // Ouvre le fichier en mode lecture

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    char line[255];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); // Affiche chaque ligne du fichier
    }

    fclose(file); // Ferme le fichier
    return 0;
};
void enregistrerReservation(struct RESERVATION user) {
    FILE *file;
    file = fopen("base_de_donnees.txt", "a"); // Ouvre le fichier en mode ajout

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // �crit les informations de r�servation dans le fichier
    fprintf(file, "%s,%s,%s,%d,%d\n", user.NOM, user.POST_NOM, user.PRENOM, user.destinationIndex, user.heureDepartIndex);

    fclose(file); // Ferme le fichier
};
