#include "game.h"



// Funcion qu determina la configuracion con la que juega el jugador
// En cada turno se le pregunta al jugador la configuracion de su Ejercito
// anoser que en el menu principal haya elegido la opcion 2
// opcion 2 ejecuta el juego de manera random hasta que haya un ganador
// retun 0 para opcion 1 (se vuelve al menu principal)
// return 2 para opcion 2 (no se vuelve a interactuar con el jugador)


int AskConfiguration(int option, t_mapa *mapa, t_jugador *jugador)
{
    // menu juego automatico
    int     ataque_localizacion = 0, conquista = 0, i=0;

    while (ataque_localizacion != 1 && ataque_localizacion != 2 && ataque_localizacion != 3 && ataque_localizacion != 4 && ataque_localizacion != 5 && ataque_localizacion != 6) || conquista == 1)
    {
        conquista = 0;
        printf("\033[1;35m\nElige zona para atacar:\n1 - King's Landing\n2 - Winterfell\n3 - The Wall\n4-Storm's End" \
                "5 - Riverrun\n6 - CasterlyRock\n7 - Sunspear\n\033[0;m");
        scanf("%i", &ataque_localizacion);
        fflush(stdin); // para evitar bucles si el usuario introduce valor no int, se le vuelve a mostart el menu para que elija bien 1, 2 o 3

        if (ataque_localizacion == 1)
        {
            while(mapa[0].enemigos_fuerza != 0)
                i++;
            if (i == 31)
                conquista = 1;
        }
        if (ataque_localizacion == 2)
        {
            i = 0;
            while(mapa[1].enemigos_fuerza != 0)
                i++;
            if (i == 31)
                conquista = 1;
        }
        if (ataque_localizacion == 3)
        {
            i = 0;
            while(mapa[2].enemigos_fuerza != 0)
                i++;
            if (i == 31)
                conquista = 1;
        }
        if (ataque_localizacion == 4)
        {
            i = 0;
            while(mapa[3].enemigos_fuerza != 0)
                i++;
            if (i == 31)
                conquista = 1;
        }
        if (ataque_localizacion == 5)
        {
            i = 0;
            while(mapa[4].enemigos_fuerza != 0)
                i++;
            if (i == 31)
                conquista = 1;
        }
        if (ataque_localizacion == 6)
        {
            i = 0;
            while(mapa[5].enemigos_fuerza != 0)
                i++;
            if (i == 31)
                conquista = 1;
        }
        if (ataque_localizacion == 7)
        {
            i = 0;
            while(mapa[6].enemigos_fuerza != 0)
                i++;
            if (i == 31)
                conquista = 1;
        }
        if (conquista == 1)
            printf("Zona ya conquistada. Prueba otra.\n");
    }


    jugador->localizacion_ataque = ataque_localizacion;
    if (option == 2)
        return (2);
    return (0);
}


/*
    Configuracion del ejercito con el que ataca el jugador
*/

void    EjercitoJugador(t_jugador *jugador)
{
    int i = 4;
    for(i; i < 30; i++)
        jugador->ejercito[i] = (rand() % 50) + 10;

        i = 0;
    printf("\n\n");
    for(i;i<30;i++)
    {
        printf("%i-", jugador->ejercito[i]);
    }

    FILE *j;
    j = fopen("jugador.txt", "w");
    if (j == NULL)
    {   // Si el resultado es NULL mensaje de error
        jugador->error = ERROR_EJERCITO;
    }
    else
    {
        i = 0;
        fprintf(j, "Ejercito de Daenerys Targaryen antes de empezar la Batalla\n\n");
        fprintf(j, "Daenerys Targaryen:\n");
        fprintf(j, "[Daenerys-%i]", jugador->ejercito[i++]);

        fprintf(j, "\nDragones:\n");
        for (i; i < 4; i++)
            fprintf(j, "[D-%i]", jugador->ejercito[i]);

        fprintf(j, "\nEjercito:\n");
        for (i; i < 30; i++)
            fprintf(j, "[s-%i]", jugador->ejercito[i]);



        fprintf(j, "\n\n\n");
        fclose(j); // Cerramos fichero
    }
}
