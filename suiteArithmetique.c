#include <stdio.h>
#include <string.h>

int main()
{

    // on choisi la formule explicite : un = u0 + nr
    // un+1 = un + (n-1)r

    int u0 = 0;
    int n = 0;
    int r = 0;
    int uprev = 0;
    int result = 0;
    char typeOfFomula[11] = "";
    int i = 0;

    // demande à l'utilisateur les valeur uo , pour n combien et r , la raison

    printf("\n[MATH] Calculateur de série arithmétique !\n\n");
    printf("Quel formule souhaitez vous utiliser ? \n");
    printf(" -> explicite : u(n) = u(0) + nr \n");
    printf("-> récurrence : u(n+1) = un + r\n\n ");
    printf("[Ecrivez \"explicite\" ou \"recurrence\"] : ");

    fgets(typeOfFomula, sizeof(typeOfFomula), stdin); // pour obtenir le user input
    printf("[OKAY] Vous avez entré : '%s'\n", typeOfFomula);

    typeOfFomula[strcspn(typeOfFomula, "\n")] = '\0'; // pour enlever la nouvelle ligbe après le print de la chaîne de charactères

    // l'utilisateur ne peux choisir que explcite ou recurrence, sinon le programme s'arrête
    if (strcmp(typeOfFomula, "explicite") == 0) // pour comparer l'entrée utilisateur aux type de formule
    {

        printf("\nDonner la valeur du premier terme u(0) : ");
        scanf("%d", &u0);

        printf("\nDonner la valeur du terme n souhaiter : ");
        scanf("%d", &n);

        printf("\nDonner la valeur de la raison r: ");
        scanf("%d", &r);

        result = u0 + n * r;

        printf("\nLe terme u(%d) = %d", n, result);
    }
    else if (strcmp(typeOfFomula, "recurrence") == 0)
    {
        printf("\nDonner la valeur terme u(n) précédent : ");
        scanf("%d", &uprev);

        printf("\nDonner la valeur du terme n souhaiter : ");
        scanf("%d", &n);

        printf("\nDonner la valeur de la raison r : ");
        scanf("%d", &r);
      
        result = uprev; // le résultat fait d'abord la valeur précédente;

        for (i = 1; i <= n; i++) // boucle pour faire en sorte d'avoir un + 1
        {
            result += r; // on ajoute la raison pour n donné
        }
        printf("\nLe terme u(%d) = %d", n, result);
    }
    else
    {
        printf("type incorrect, veuillez recommencez");
    }

    return 0;
}