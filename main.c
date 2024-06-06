#include <stdio.h>
#include <stdlib.h> 


int main()
{
    
    printf("\t**********BIENVENUS CHEZ BIENVENUS***********\t\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    int choix_du_bus = 0;
    printf("entrer votre choix : ");
    scanf("%d", &choix_du_bus);
    
    do
    {
        switch (choix_du_bus)
        {
        case 0:
        printf("");
            break;
        
        default:
            break;
        }
    } while (choix_du_bus !=4);
    
    return 0;

}