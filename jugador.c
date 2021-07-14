#include "game.h"



// Funcion qu determina la configuracion con la que juega el jugador
// En cada turno se le pregunta al jugador la configuracion de su Ejercito
// a no ser que en el menu principal haya elegido la opcion 2
// opcion 2 ejecuta el juego de manera random hasta que haya un ganador
// retun 0 para opcion 1 (se vuelve al menu principal)
// return 2 para opcion 2 (no se vuelve a interactuar con el jugador)


int AskConfiguration(t_mapa *mapa)
{
    // menu juego automatico
    int ataque_localizacion = 0, conquista = 0;

    while ((ataque_localizacion != 1 && ataque_localizacion != 2 && ataque_localizacion != 3 && ataque_localizacion != 4 && ataque_localizacion != 5 && ataque_localizacion != 6 && ataque_localizacion != 7) || conquista == 1)
    {
        conquista = 0;
        printf("\033[1;35m\nElige zona para atacar:\n1 - King's Landing\n2 - Winterfell\n3 - The Wall\n4-Storm's End" \
                "5 - Riverrun\n6 - CasterlyRock\n7 - Sunspear\n\033[0;m");
        scanf("%i", &ataque_localizacion);
        fflush(stdin); // para evitar bucles si el usuario introduce valor no int, se le vuelve a mostart el menu para que elija bien 1, 2 o 3

        conquista = ZonaConquistada(mapa, ataque_localizacion);
        if (conquista == 1)
            printf("Zona ya conquistada. Prueba otra.\n");
    }


    jugador->localizacion_ataque = ataque_localizacion;
    if (option == 2)
        return 2;
    return 0;
        return(ataque_localizacion);

}


/*
    Configuracion del ejercito con el que ataca el jugador
*/

void    EjercitoJugador(t_jugador *jugador)
{
    for(int i = 0; i < 16; i++)
    jugador->ejercito[i] = (rand() % 120) + 50;     // MODIFICAR PARA AÑADIR/QUITAR DIFICULTAD
    // dependiendo de la fuerza de los soldados del jugador, es más facil o más dificil ganar
    // con los valores actuales de la más o menos la mitad de las partidas son ganadas y la otra mitad perdidas

    FILE *j;
    j = fopen("jugador.txt", "w");
    if (j == NULL)
    {   // Si el resultado es NULL mensaje de error
        jugador->error = ERROR_EJERCITO;
    }
    else
    {

        fprintf(j, "Ejercito de Daenerys Targaryen antes de empezar la Batalla\n\n");

        fprintf(j, "\nEjercito:\n");
        for (int i = 0; i < 16; i++)
        fprintf(j, "[s-%i]", jugador->ejercito[i]);
        fprintf(j, "\n\nDaenerys Targaryen:\n");
        fprintf(j, "[Daenerys-%i]", jugador->ejercito[16]);

        fprintf(j, "\n\nDragones:\n");
        for (int i = 17; i < 20; i++)
            fprintf(j, "[D-%i]", jugador->ejercito[i]);



        fclose(j); // Cerramos fichero
    }
}
