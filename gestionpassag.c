#include <stdio.h>
#include <stdlib.h>

typedef struct passager
{
    char NOM[50];
    char PRE_NOM[50];
    char addresse[100];
    char telephone[20];
    char email[50];
    int nombre_reservation ;
}passager;

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
        ajouter_passager(passagers[i]);
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
            ajouter_passager(passagers , &nb_passagers);
            break;
        case 2:
        int id_passager ;
            printf("entrer l'Id du passager : ");
            scanf("%d", &id_passager);

            if (id_passager >= 0 && id_passager < nb_passagers)
            {
                afficher_passager(passagers[id_passager]);
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