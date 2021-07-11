#include <stdio.h>
#include <stdlib.h> // random rand()
#include <time.h> // time(NULL)
#include "game.h"


void CreateWesterosFile(t_westeros *westeros)

{

    FILE *w;

    w = fopen("westeros.txt", "w");
    if (w == NULL)
    {   // Si el resultado es NULL mensaje de error
        printf("Error al abrir el fichero westeros.txt.\n");
    }
    else
    {
        fprintf(w, "Ejercito de Westeros antes de empezar la Batalla\n");
        fprintf(w, "Soldados:\n");
        for (int i=0; i < 20; i++)
            fprintf(w, "[∆-%i]", westeros->bsoldados[i]);
        fprintf(w, "\nArqueros:\n");
        for (int i=0; i < 10; i++)
            fprintf(w, "[⩥-%i]", westeros->barqueros[i]);
        fprintf(w, "\nZombies:\n");
        for (int i=0; i < 5; i++)
            fprintf(w, "[§-%i]", westeros->bzombies[i]);

        fprintf(w, "\n\n\n");
        fclose(w); // Cerramos fichero
    }
}

void    CreateWesterosMap(t_westeros *westeros)
{
    FILE *map;
    map = fopen("map.txt", "w");
    if (map == NULL)
    {   // Si el resultado es NULL mensaje de error
        printf("Error al abrir el fichero map.txt.\n");
    }
    else
    {
        fprintf(map, "\t\tWESTEROS MAP\n\n");


        int localizacion_reyMuerto = (rand() % 7) + 1;
        int localizacion_tywin = (rand() % 7) + 1;
        int localizacion_jaimie = (rand() % 7) + 1;
        int localizacion_cersei = (rand() % 7) + 1;
        int localizacion_tyrion = (rand() % 7) + 1;
        int localizacion_stannis = (rand() % 7) + 1;

        int localizaciones_soldados[20] = {1,2,3,4,5,6,7,0,0,0,0,0,0,0,0,0,0,0,0,0};
        // se inicializa de esta manera para asegurar que hay almenos un enemigo ocupando cada localizacion
        for (int i=7; i < 20; i++)
            localizaciones_soldados[i] = (rand() % 7) + 1;
        int localizaciones_arqueros[10] = {0,0,0,0,0,0,0,0,0,0};
        for (int i=0; i < 10; i++)
            localizaciones_arqueros[i] = (rand() % 7) + 1;
        int localizaciones_zombies[5] = {0,0,0,0,0};
        for (int i=0; i < 5; i++)
            localizaciones_zombies[i] = (rand() % 7) + 1;

        t_mapa mapa[7] = {{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}, { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} }, { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} }, { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} },{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} },{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} },{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} }};
        //mapa[0] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };


        for (int i=0; i < 9; i++)
        {
            printf("aaaa");
            printf("{%i]",mapa[0].enemigos_fuerza[i]);
        }


        fprintf(map, "King's Landing\n");

        if (localizacion_reyMuerto == 1)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "Winterfell\n");

        if (localizacion_reyMuerto == 2)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "The Wall\n");

        if (localizacion_reyMuerto == 3)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "Storm's End\n");

        if (localizacion_reyMuerto == 4)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "Riverrun\n");

        if (localizacion_reyMuerto == 5)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "CasterlyRock\n");

        if (localizacion_reyMuerto == 6)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "Sunspear\n");

        if (localizacion_reyMuerto == 7)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fclose(map);

    }
}

    t_westeros *WesterosConfiguration(t_westeros *westeros)
{
    int batallon_soldados[20];
    int batallon_arqueros[10];
    int batallon_zombies[5];

    srand(time(NULL)); // para evitar obtener la misma secuencia de numeros random
    for (int i=0; i < 20; i++)
    {
        batallon_soldados[i] = (rand() % 50) + 10; // random numbers 1 - 50
        westeros->bsoldados[i] = batallon_soldados[i];
        if (i < 5)
        {
            batallon_arqueros[i] =  (rand() % 20) + 10;
            westeros->barqueros[i] = batallon_arqueros[i];
            batallon_zombies[i] = (rand() % 60) + 30;
            westeros->bzombies[i] = batallon_zombies[i];
        }
        if (i >= 5 && i < 10)
        {
            batallon_arqueros[i] = (rand() % 20) + 10;
            westeros->barqueros[i] = batallon_arqueros[i];
        }
    }

    CreateWesterosFile(westeros);
    CreateWesterosMap(westeros);


    printf("Soldados:\n");
    for (int i=0; i < 20; i++)
    {
        printf("[%i]", batallon_soldados[i]);
    }

    printf("\nArqueros:\n");
    for (int i=0; i < 10; i++)
    {
        printf("[%i]", batallon_arqueros[i]);
    }

    printf("\nZombies:\n");
    for (int i=0; i < 5; i++)
    {
        printf("[%i]", batallon_zombies[i]);
    }



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
