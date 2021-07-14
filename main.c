#include "game.h"


int main(void)
{
    printf("\033[1;32m#######################################################\n");
    printf("##########        Battle  for  Westeros      ##########\n");
    printf("#######################################################\033[0;m\n");

    int     option = 0, finishGame = 0;

    char    *menu = "\033[1;35m\nMenu:\n1 - Configurar el ataque\n2 - Salir del juego\n\033[0;m";

    // Ejercito compuesto por la Reina Daenerys Targaryen, sus dos dragones y sus soldados
    t_jugador   jugador = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,800,700,600,500},
                        {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','R','D','D','D',},
                        0, NULL};
    // Ejercito Enemigo
    t_westeros  westeros = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,2,3,4,5,6,7,0,0,0,0,0,0,0,0,0,0,0,0,0}, // se inicializa de esta manera para asegurar que hay almenos un enemigo ocupando cada localizacion
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,0,0,0,0},
                            500, 0,
                            300, 0, 250, 0, 200, 0, 150, 0, 300, 0,
                            NULL}; // Inicializando a 0 para despues sustituir por valores random

    // Mapa con las 7 distintas loalizaciones
    t_mapa  mapa[7] = { {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0}
                    };
    // Aqui se inicia la configuracion del Enemigo (Westeros)
    WesterosConfiguration(&westeros, mapa); // El ejercito del enemigo no necesita confuguracion, se crea al inicio del programa de forma random
    // El ejercito del enemigo es colocado de forma random sobre el mapa de manera que siempre halla alguien contra quien enfrentarse

    EjercitoJugador(&jugador);

    // Gestion errores ficheros
    if (westeros.error != NULL || jugador.error != NULL)
    {
        if (westeros.error != NULL)
            printf("ERROR: %s", westeros.error);
        else
            printf("ERROR: %s", jugador.error);
        return (0);
    }

    // Loop principal
    while (finishGame == 0)
    {
        while (option != 1 && option != 2)
        {
            printf(menu);
            scanf("%i", &option);
            fflush(stdin); // para evitar bucles si el usuario introduce valor no int, se le vuelve a mostart el menu para que elija bien 1, 2 o 3
        }
        switch(option)
        {
            case 1:
                // Juego empieza o continua
                printf("\n\x1b[34mComienza nuevo ataque.\x1b[0m\n");

                jugador.localizacion_ataque = AskConfiguration(mapa); // Para empezar turno nuevo en el siguiente loop y que el jugador eliga nueva opcion

                finishGame = Ataque(mapa, &jugador, jugador.localizacion_ataque - 1); // el juego sigue hasta que esta var es 1 o el jugador elige Salir option = 2

                break;
            case 2:
                finishGame = 3;
                break ;
        }
    }

    if (finishGame == 1)
    {
        printf("\n\033[1;32m#############################################################\n");
        printf("## You are the Winner! Westeros is yours! Congratulations! ##\n");
        printf("#############################################################\033[0;m\n");
    }
    if (finishGame == 2)
    {
        printf("\n\033[1;31m##################################################################\n");
        printf("######  Westeros es invencible! Buena suerte la siguiente vez.  ##\n");
        printf("##################################################################\033[0;m\n");
    }
    if (finishGame == 3)
        printf("\nBye!\n");

    return (0);
}

