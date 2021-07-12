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
         westeros->error = ERROR_WESTEROS;
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

void AddEnemigosMapa(t_westeros *westeros, t_mapa *mapa)
{
    int mapa0 = 0, mapa1 = 0, mapa2 = 0, mapa3 = 0, mapa4 = 0, mapa5 = 0, mapa6 = 0;

    for (int i=0; i < 20; i++)
    {
        if (westeros->localizaciones_soldados[i] == 1)
        {
            mapa[0].enemigos_fuerza[mapa0] = westeros->bsoldados[i];
            mapa[0].enemigos_tipo[mapa0] = 's';
            mapa0++;
        }
        /*
        if (westeros->localizaciones_soldados[i] == 2)
        {
            mapa[1]->enemigos_fuerza[mapa1] = westeros->bsoldados[i];
            mapa[1]->enemigos_tipo[mapa1] = 's';
            mapa1++;
        }
        if (westeros->localizaciones_soldados[i] == 3)
        {
            mapa[2]->enemigos_fuerza[mapa2] = westeros->bsoldados[i];
            mapa[2]->enemigos_tipo[mapa2] = 's';
            mapa2++;
        }
        if (westeros->localizaciones_soldados[i] == 4)
        {
            mapa[3]->enemigos_fuerza[mapa3] = westeros->bsoldados[i];
            mapa[3]->enemigos_tipo[mapa3] = 's';
            mapa3++;
        }
        if (westeros->localizaciones_soldados[i] == 5)
        {
            mapa[4]->enemigos_fuerza[mapa4] = westeros->bsoldados[i];
            mapa[4]->enemigos_tipo[mapa4] = 's';
            mapa4++;
        }
        if (westeros->localizaciones_soldados[i] == 6)
        {
            mapa[5]->enemigos_fuerza[mapa5] = westeros->bsoldados[i];
            mapa[5]->enemigos_tipo[mapa5] = 's';
            mapa5++;
        }
        if (westeros->localizaciones_soldados[i] == 7)
        {
            mapa[6]->enemigos_fuerza[mapa6] = westeros->bsoldados[i];
            mapa[6]->enemigos_tipo[mapa6] = 's';
            mapa6++;
        }*/
    }

    for (int i = 0; i < 31; i++)
    {
        printf("<%i-%c>", mapa[0].enemigos_fuerza[i], mapa[0].enemigos_tipo[i]);
    }
    printf("\n");
}


void    CreateWesterosMap(t_westeros *westeros)
{
    FILE *map;
    map = fopen("map.txt", "w");
    if (map == NULL)
    {   // Si el resultado es NULL mensaje de error
         westeros->error = ERROR_MAP;
    }
    else
    {
        fprintf(map, "\t\tWESTEROS MAP\n\n");


        westeros->localizacion_reyMuerto = (rand() % 7) + 1;
        westeros->localizacion_tywin = (rand() % 7) + 1;
        westeros->localizacion_jaimie = (rand() % 7) + 1;
        westeros->localizacion_cersei = (rand() % 7) + 1;
        westeros->localizacion_tyrion = (rand() % 7) + 1;
        westeros->localizacion_stannis = (rand() % 7) + 1;


        // Asignando valores para las 7 localizaciones

        t_mapa mapa[7] = { {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}
                    };



        AddEnemigosMapa(westeros, mapa);
        fprintf(map, "King's Landing\n");

        int i = 0;
        while (mapa[0].enemigos_fuerza[i] != 0)
        {
            fprintf(map, "[∆-%i]", mapa[0].enemigos_fuerza[i++]);
        }

        fprintf(map, "\nWinterfell\n");

        if (westeros->localizacion_reyMuerto == 2)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "\nThe Wall\n");

        if (westeros->localizacion_reyMuerto == 3)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "\nStorm's End\n");

        if (westeros->localizacion_reyMuerto == 4)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "\nRiverrun\n");

        if (westeros->localizacion_reyMuerto == 5)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "\nCasterlyRock\n");

        if (westeros->localizacion_reyMuerto == 6)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fprintf(map, "\nSunspear\n");

        if (westeros->localizacion_reyMuerto == 7)
        {
            fprintf(map, "[ReyMuerto]\n");
        }

        fclose(map);

    }
}

    t_westeros *WesterosConfiguration(t_westeros *westeros)
{
    srand(time(NULL)); // para evitar obtener la misma secuencia de numeros random
    for (int i=0; i < 20; i++)
    {
        westeros->bsoldados[i] = (rand() % 50) + 10; // numeros random 1 - 50

        if(i < 5)
        {
            westeros->barqueros[i] = (rand() % 20) + 10;
            westeros->localizaciones_arqueros[i] = (rand() % 7) + 1;
            westeros->bzombies[i] = (rand() % 60) + 30;
            westeros->localizaciones_zombies[i] = (rand() % 7) + 1;
        }

        if (i >= 5 && i < 10)
        {
            westeros->barqueros[i] = (rand() % 20) + 10;
            westeros->localizaciones_arqueros[i] = (rand() % 7) + 1;
        }

        // Set up localizaciones, habrá minimo un batallon de soldados por localizacion, para evitar obtener localizaciones despobladas
        if (i >= 7)
            westeros->localizaciones_soldados[i] = (rand() % 7) + 1;

    }

    CreateWesterosFile(westeros);
    CreateWesterosMap(westeros);

    // para debuggear BORRAR luego

    printf("Soldados:\n");
    for (int i=0; i < 20; i++)
    {
        printf("[%i]", westeros->bsoldados[i]);
        printf("{%i}", westeros->localizaciones_soldados[i]);
    }

    printf("\nArqueros:\n");
    for (int i=0; i < 10; i++)
    {
        printf("[%i]", westeros->barqueros[i]);
        printf("{%i}", westeros->localizaciones_arqueros[i]);
    }

    printf("\nZombies:\n");
    for (int i=0; i < 5; i++)
    {
        printf("[%i]", westeros->bzombies[i]);
        printf("{%i}", westeros->localizaciones_zombies[i]);
    }

    return (westeros);

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
