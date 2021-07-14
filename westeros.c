
#include "game.h"


/*
    Funcion para crear el fichero westeros.txt
*/
void        CreateWesterosFile(t_westeros *westeros)
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
        fprintf(w, "\nGenerales:\n");

        fprintf(w, "[ReyMuerto-%i]", westeros->reyMuerto);
        fprintf(w, "[Tywin-%i]", westeros->Tywin);
        fprintf(w, "[Jaimie-%i]", westeros->Jaimie);
        fprintf(w, "[Cersei-%i]", westeros->Cersei);
        fprintf(w, "[Tyrion-%i]", westeros->Tyrion);
        fprintf(w, "[Stannis-%i]", westeros->Stannis);

        fprintf(w, "\n\n\n");
        fclose(w); // Cerramos fichero
    }
}


/*
    Funcion para configurar al enemigo (Westeros)
    Westeros está formado por:
        - [lista] 20 batallones de soldados con fuerzas entre 10-50 (int values)
        - [lista] 10 batallones de arqueros con fuerzas entre 10-30 (int values)
        - [lista] 5 batallones de soldados con fuerzas entre 30-60 (int values)
        - [int] representa al Rey Muerto con 500 de fuerza
        - [int] Tywin 300
        - [int] Jaimie 250
        - [int] Cersei 200
        - [int] Tyrion 150
        - [int] Stannis 300
*/
t_westeros  *WesterosConfiguration(t_westeros *westeros, t_mapa *mapa)
{
    srand(time(NULL)); // para evitar obtener la misma secuencia de numeros random

    // Loop para asignar de manera random distintas fuerzas a cada batallon de soldados/arqueros/zombies
    for (int i=0; i < 20; i++)
    {
        westeros->bsoldados[i] = (rand() % 50) + 10; // random numbers 10 - 50
        if (i < 5)
        {
            westeros->barqueros[i] = (rand() % 30) + 10;
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

    CreateMap(westeros, mapa);

    return (westeros);
}
