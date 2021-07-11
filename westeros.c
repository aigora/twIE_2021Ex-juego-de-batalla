#include <stdio.h>
#include <stdlib.h> // random rand()
#include <time.h> // time(NULL)
#include "game.h"

void WesterosConfiguration(void)
{
    int batallon_soldados[20];
    int batallon_arqueros[10];
    int batallon_zombies[5];

    srand(time(NULL)); // para evitar obtener la misma secuencia de numeros random
    for (int i=0; i < 20; i++)
    {
        batallon_soldados[i] = (rand() % 50) + 10; // random numbers 1 - 50
        if (i < 5)
        {
            batallon_arqueros[i] =  (rand() % 20) + 10;
            batallon_zombies[i] = (rand() % 60) + 30;
        }
        if (i < 10 && i >= 5)
            batallon_arqueros[i] =  (rand() % 20) + 10;
    }

    printf("Soldados:\n");
    for (int i=0; i < 20; i++)
    {
        printf("[%i]", batallon_soldados[i]);
    }

    printf("\nArqueros:\n");
    for (int i=0; i < 10; i++)
    {
        printf("[%i]", batallon_soldados[i]);
    }

    printf("\nZombies:\n");
    for (int i=0; i < 5; i++)
    {
        printf("[%i]", batallon_soldados[i]);
    }

    //printf(bsoldados.numero_soldados);
    //printf(bsoldados.battallon);
    // westeros.bsoldados.lider  pensar en implementar lider o no



}




// Funcion que determina la configuracion con la que juega el jugador
// En cada turno se le pregunta al jugador la configuracion de su Ejercito
// a no ser que en el menu principal haya elegido la opcion 2
// opcion 2 ejecuta el juego de manera random hasta que haya un ganador
// retun 0 para opcion 1 (se vuelve al menu principal)
// return 2 para opcion 2 (no se vuelve a interactuar con el jugador)


int AskConfiguration(int option)
{




    if (option == 2)
        return (2);
    return 0;
}
