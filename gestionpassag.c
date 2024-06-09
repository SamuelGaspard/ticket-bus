#include <stdio.h>
#include <stdlib.h>

typedef struct passager
{
    char NOM[50];
    char PRE_NOM[50];
    //char addresse[100];
    char telephone[20];
    char email[50];
    int nombre_reservation;
    struct reservation* reservations[100];
    
}passager;

typedef struct Reservation

{
    char datevoyage[50];
    char numerobus[20];
    char place[20];
}Reservation;

void ajouter_passager(passager *passagers , int *nbpassagers)
{
    //allocation d'une memoire pour nouveau passager
    passager * nouveaupassager = malloc(sizeof(passager));

    //saisie des information du passagers 
    printf("Entrer le nom du passager  : ");
    scanf("%s", nouveaupassager ->NOM);
    printf("Entrer le pre-nom du passager  : ");
    scanf("%s", nouveaupassager ->PRE_NOM);
    printf("Entrer le numero du passager  : ");
    scanf("%s", nouveaupassager ->telephone);
    printf("Entrer email du passager  : ");
    scanf("%s", nouveaupassager ->email);
    printf("Entrer le nombre de(s) passager  : ");
    scanf("%d", nouveaupassager ->nombre_reservation);

    nouveaupassager ->nbpassagers = 0;
    passagers[*nbpassagers] = *nouveaupassager;
    *nbpassagers += 1;
}

//la fonction pour afficher les informatio du passagers 

void afficherpassager(passager *passager)
{
    printf("NOM : %s %s \n", passager ->NOM , passager ->PRE_NOM);
    printf("Email : %s \n " , passager ->email);
    printf("telephone : %s \n " , passager ->telephone);
    printf("nombre reserve(s) : %d\n " , passager ->nombre_reservation);

    //afficher l'historique du reservation
    if (passager ->nombre_reservation > 0)
    {
        printf("Historique de reservation : \n");
        for (int i = 0; i < passager ->nombre_reservation; i++)
        {
            struct Reservation* reservation = passager ->reservations[i];
            printf(" - Date de voyage : %s \n ", reservation ->datevoyage);
            printf(" - numero bus : %s \n ", reservation ->numerobus);
            printf(" - place : %s \n ", reservation->place);
            
        }
        else{
            printf("ce passager n'a aucune reservation . \n");
        }
        
    }
     
}

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
    passager ->reservations[passager ->nombre_reservation] = nouvelleReservation;
    passager ->nombre_reservation += 1;

    printf("reservation ajouter avec succes ! \n");

    
}

int main()
{
    //table pour stocker les passagers
    void ajouter_passager();
    void afficherpassager();
    void ajouterreservation();
    

    passager passagers[100];
    return 0;

}




/*
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