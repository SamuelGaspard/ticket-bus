#include <stdio.h>
#include <stdlib.h>

#define MAX_RESERVATIONS 10
#define MAX_PASSAGERS 100

typedef struct {
    char datevoyage[20];
    char numerobus[20];
    char place[10];
} Reservation;

typedef struct {

    char nom[50];
    char contact[50];
    char PRE_NOM[50];
    char telephone[20];
    char email[50];
   // int nombre_reservation;
    Reservation reservations[MAX_RESERVATIONS];
    int nombre_reservation;
} Passager;

void ajouter_passager(Passager passagers[], int *nbpassagers) {
    if (*nbpassagers >= MAX_PASSAGERS) {
        printf("Limite de passagers atteinte.\n");
        return;
    }
    printf("\n\n\n\n");
    printf("\t\t Entrer le nom du passager: ");
    scanf("%s", passagers[*nbpassagers].nom);
    printf("\n");
    printf("\t\t Entrer le pre-nom du passager: ");
    scanf("%s", passagers[*nbpassagers].PRE_NOM);
    printf("\n");
    printf("\t\t Entrer le telephone du passager: ");
    scanf("%s", passagers[*nbpassagers].telephone);
    printf("\n");
    printf("\t\t Entrer l'email du passager: ");
    scanf("%s", passagers[*nbpassagers].email);
    printf("\n");
    printf("\t\t Entrer le contact du passager: ");
    scanf("%s", passagers[*nbpassagers].contact);
    printf("\n");

    passagers[*nbpassagers].nombre_reservation = 0;
    (*nbpassagers)++;
}

void ajouter_reservation(Passager passagers[], int nbpassagers) {
    int id;
    printf("Entrer l'ID du passager: ");
    scanf("%d", &id);
    if (id < 1 || id > nbpassagers) {
        printf("numero de Passager invalide.\n");

       return;
    }
    Passager *passager = &passagers[id - 1];
    if (passager->nombre_reservation >= MAX_RESERVATIONS) {
        printf("Limite de réservations atteinte pour ce passager.\n");
        return;
    }
    printf("Entrer la date du voyage: ");
    scanf("%s", passager->reservations[passager->nombre_reservation].datevoyage);
    printf("Entrer le numéro du bus: ");
    scanf("%s", passager->reservations[passager->nombre_reservation].numerobus);
    printf("Entrer la place: ");
    scanf("%s", passager->reservations[passager->nombre_reservation].place);
    passager->nombre_reservation++;
}

void afficher_passager(Passager passagers[], int nbpassagers) {
    int id;
    printf("Entrer l'ID du passager à afficher: ");
    scanf("%d", &id);
    if (id < 1 || id > nbpassagers) {
        printf("Passager invalide.\n");
        return;
    }
    Passager passager = passagers[id - 1];
    printf("Nom: %s, Contact: %s\n", passager.nom, passager.contact);
    for (int i = 0; i < passager.nombre_reservation; i++) {
        printf("Réservation %d: %s, Bus %s, Place %s\n", i + 1, passager.reservations[i].datevoyage, passager.reservations[i].numerobus, passager.reservations[i].place);
    }
}

int main() {
    Passager passagers[MAX_PASSAGERS];
    int nbpassagers = 0;
    int choix;

    do {
        printf("\t\t\t 1. Ajouter un passager : \n");
        printf("\t\t\t 2. Ajouter une reservation : \n");
        printf("\t\t\t 3. Afficher un passager : \n");
        printf("\t\t\t 0. Quitter\n\t\t");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_passager(passagers, &nbpassagers);
                break;
            case 2:
                ajouter_reservation(passagers, nbpassagers);
                break;
            case 3:
                afficher_passager(passagers, nbpassagers);
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("\t\t\t Choix invalide.\n\t\t\t");
        }
    } while (choix != 0);

    return 0;
}
/*
typedef struct passager
{
    //declaration des variables pour les information du passagers

    char NOM[50];
    char PRE_NOM[50];
    char telephone[20];
    char email[50];
    int nombre_reservation;
    int nbpassagers;
    struct reservation reservations[100];
    
}passager;

typedef struct Reservation

{
    char datevoyage[50];
    char numerobus[20];
    char place[20];
}Reservation;
/*
// Définition de la structure 'reservation'
struct reservation {
    // Ajoutez ici les champs de la structure
    int id;
    char details[100];
    char datevoyage[50];
    char numerobus[20];
    char place[20];
    // Autres champs...
};

// Définition de la structure 'passager'
struct passager {
    char NOM[50];
    char PRE_NOM[50];
    char telephone[15];
    char email[50];
    int nombre_reservation;
    struct reservation reservations[100]; // Maintenant, cette ligne ne devrait plus causer d'erreur
    // Autres champs...
};

// Votre code existant ici...
//ajouter un passager
void ajouter_passager(passager *passagers, int *nbpassagers)
{
    //allocation d'une memoire pour nouveau passager
    passager *nouveaupassager = malloc(sizeof(passager));

    //saisie des information du passagers ,la fonction pour afficher les information du passagers 
    printf("Entrer le nom du passager  : ");
    scanf("%s", nouveaupassager->NOM);
    printf("Entrer le pre-nom du passager  : ");
    scanf("%s", nouveaupassager->PRE_NOM);
    printf("Entrer le numero du passager  : ");
    scanf("%s", nouveaupassager->telephone);
    printf("Entrer email du passager  : ");
    scanf("%s", nouveaupassager->email);
    printf("Entrer le nombre de(s) passager  : ");
    scanf("%d", &nouveaupassager->nombre_reservation);

    nouveaupassager->nbpassagers = 0;
    passagers[*nbpassagers] = *nouveaupassager;
    *nbpassagers += 1;
}




 //une procedure pour afficher les passagers 
    //une procedure pour afficher les passagers 
    
void afficher_tous_les_passagers(passager *passagers, int nbpassagers)
{
    for (int i = 0; i < nbpassagers; i++)
    {
        printf("Passager %d:\n", i + 1);
        printf("Nom: %s\n", passagers[i].NOM);
        printf("Prénom: %s\n", passagers[i].PRE_NOM);
        printf("Téléphone: %s\n", passagers[i].telephone);
        printf("Email: %s\n", passagers[i].email);
        printf("Nombre de réservations: %d\n", passagers[i].nombre_reservation);
        printf("\n");
    }
}
  /*
  
void afficherpassager(passager *passager)
{
    printf("NOM : %s %s \n", passager->NOM, passager->PRE_NOM);
    printf("Email : %s \n ", passager->email);
    printf("telephone : %s \n ", passager->telephone);
    printf("nombre reserve(s) : %d\n ", passager->nombre_reservation);

    //afficher l'historique du reservation
    if (passager->nombre_reservation > 0)
    {
        printf("Historique de reservation : \n");
        for (int i = 0; i < passager->nombre_reservation; i++)
        {
            struct Reservation reservation = passager->reservations[i];
            printf(" - Date de voyage : %s \n ", reservation->datevoyage);
            printf(" - numero bus : %s \n ", reservation->numerobus);
            printf(" - place : %s \n ", reservation->place);
        }
    }
    else
    {
        printf("ce passager n'a aucune reservation . \n");
    }
}

/*

//ajouter une reservation a un passager 

void ajouterreservation(passager*passagers , int nbpassagers)
{
    int choixpassager;
    printf("entrer le numero du passager : ");
    scanf("%d", &choixpassager);
    if (choixpassager < 1 || choixpassager > nbpassagers)
    {
        printf("numero de passager invalide \n ");
        return;
    }
    passager* passager = &passagers[choixpassager -1];
    //allocation d'une memoire pour ajouter une reservation 
    struct Reservation* nouvelleReservation = malloc(sizeof(Reservation));

    //la saisie de informations de reservation 
    printf("entrer la date du voyage : ");
    scanf("%s", nouvelleReservation ->datevoyage);
    printf("entrer le numero du bus : ");
    scanf("%s", nouvelleReservation ->numerobus);
    printf("entrer la place : ");
    scanf("%s", nouvelleReservation ->place);

    //ajouter la nouvelle reservation dans l'historique du passager 
    passager->reservations[passager->nombre_reservation] = (struct Reservation*)nouvelleReservation;
    struct Reservation* nouvelleReservation; 
    passager ->nombre_reservation += 1;

    printf("reservation ajouter avec succes ! \n");

    
}

    int main()
{
    passager passagers[100];
    int nbpassagers = 0;
    int choix;

    do
    {
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                printf("\t\t\tAjouter un passager : \t\t\t\n");
                printf("\n\n\n\n");
                ajouter_passager(passagers, &nbpassagers); 
                break;
            case 2:
                printf("Afficher un passager : \n ");   
                break;
            case 3:
                printf("Ajouter reservation du passager : \n");      
                break;
            case 4:
                printf("Afficher tous les passagers  : \n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
        } 

    } while (choix != 4);
    

//afficher tous les passagers enregistrés
/*void afficher_tous_les_passagers(passager *passagers, int nbpassagers)
{
    for (int i = 0; i < nbpassagers; i++)
    {
        printf("Passager %d:\n", i + 1);
        printf("Nom: %s\n", passagers[i].NOM);
        printf("Prénom: %s\n", passagers[i].PRE_NOM);
        printf("Téléphone: %s\n", passagers[i].telephone);
        printf("Email: %s\n", passagers[i].email);
        printf("Nombre de réservations: %d\n", passagers[i].nombre_reservation);
        printf("\n");
    }
}

    return 0;
}

    
/*
{
        int choix;

        do
        {
            switch (choix)
            {
                case 0:
                    printf("1. Ajouter un passager : ");
                    ajouter_passager(passagers, &nbpassagers); // Call the function to add a passenger
                    break;
                case 1:
                    printf("2. afficher un passager : ");
                    // Call the function to display a passenger
                    break;
                case 2:
                    printf("3. ajouter resrevation du passager: ");
                    // Call the function to add a reservation for a passenger
                    break;
                case 3:
                    printf("4. Ajouter un passager: ");
                    // Call the function to display all passengers
                    break;
                default:
                    printf("");
            } 

        } while (choix != 4);
        
        return 0;
    }
void ajouter_passager(passager *passagers , int **nbr_passagers)
{
        printf("veuiller entrer votre NOM : ");
        scanf("%s" , passagers[ ** nbr_passagers].NOM);

        printf("veuiller entrer votre PRE_NOM : ");
        scanf("%s" , passagers[ ** nbr_passagers].PRE_NOM);

        printf("veuiller entrer votre addresse : ");
        scanf("%s" , passagers[ ** nbr_passagers].addresse);

        printf("veuiller entrer votre numero de telephone : ");
        scanf("%s" , passagers[ ** nbr_passagers].telephone);

        printf("veuiller entrer votre email : ");
        scanf("%s" , passagers[ ** nbr_passagers].email);

        passagers [ **nbr_passagers].nombre_reservation = 0;
        (*nbr_passagers) ++;

}

void afficher_tous_les_passagers(passager *passagers , int nb_passagers)
{
    for (int i = 0; i < nb_passagers; i++)
    {
        ajouter_passager(passager[i]);
    }
    
}

// la fonction principale prend en parametre tout les procedures 


int main ()
{
     passager passagers[100];
     int nb_passagers = 0;

     int choix;
     do
     {
        printf("\t************MENU\t***********\n");
        printf("1. Ajouter un passagers \n");
        printf("2. Afficher un passager\n");
        printf("3. Afficher tous les passagers \n");
        printf("4. Quitter  \n");

        printf("enter votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouter_passager(passagers , int **nb_passagers);
            break;
        case 2:
        int id_passager ;
            printf("entrer l'Id du passager : ");
            scanf("%d", &id_passager);

            if (id_passager >= 0 && id_passager < nb_passagers)
            {
                ajouter_passager(passagers[id_passager]);
            }else{
                printf("ID du passager invalide .\n ");
            }  
            break;

        case 3:
            afficher_tous_les_passagers(passagers, nb_passagers);
            break;
        case 4:
            break; 
        default:
        printf("choix invalide .\n");
            break;
        }
     } while (choix !=4);
       
    return 0;
    

}
*/