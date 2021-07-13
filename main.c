#include <stdio.h>
#include "game.h"

int main(void)
{
    printf("\033[1;32m#######################################################\n");
    printf("##########        Battle  for  Westeros      ##########\n");
    printf("#######################################################\033[0;m\n");

    // WesterosConfiguration(); // Aqui se inicia la configuracion del Enemigo (Westeros)

    int option = 0, finishGame = 0, turno = 0;

    char *menu = "\033[1;35m\nMenu:\n1 - Choose my configuration\n" \
                "2 - Continue Automatically (The game will run until there is a winner)\n" \
                "3 - Exit game\n\033[0;m";

    // Ejercito compuesto por la Reina Daenerys Targaryen, sus dos dragones y sus soldados
    t_jugador   jugador = {{700,500,600,400,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {'R','D','D','D',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        0, 0, NULL};



    t_westeros westeros = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,2,3,4,5,6,7,0,0,0,0,0,0,0,0,0,0,0,0,0}, // se inicializa de esta manera para asegurar que hay almenos un enemigo ocupando cada localizacion
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,0,0,0,0},
                            500, 0,
                            300, 0, 250, 0, 200, 0, 150, 0, 300, 0,

                            NULL}; // Inicializando a 0 para despues sustituit por valores random



    t_mapa mapa[7] = { {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0},

                    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    0}
                    };

    // Aqui se inicia la configuracion del Enemigo (Westeros)
    WesterosConfiguration(&westeros, mapa); // El ejercito del enemigo no necesita confuguracion, se crea al inicio del programa de forma random
    // El ejercito del enemigo es colocado de forma random sobre el mapa de manera que siempre halla alguien contra quien enfrentarse
    EjercitoJugador(&jugador);

    if (westeros.error != NULL)
    {
        printf("ERROR: %s", westeros.error);
        return (0);
    }

    while (finishGame == 0)
    {
        if (option == 0) // Inicio de juego o nuevo turno
        {
           // Menu principal

           while (option != 1 && option != 2 && option != 3)
           {
              printf(menu);
              scanf("%i", &option);
              fflush(stdin); // para evitar bucles si el usuario introduce valor no int, se le vuelve a mostart el menu para que elija bien 1, 2 o 3
           }
           switch(option)
              {
                case 1:
                case 2:
                    // Juego empieza o continua
                    printf("Start Game");

                    turno += 1;
                    option = AskConfiguration(option, mapa, &jugador); // Para empezar turno nuevo en el siguiente loop y que el jugador eliga nueva opcion

                    jugador->final = Ataque(&westeros, &jugador); // el juego sigue hasta que esta var es 1 o el jugador elige Salir option = 3

                    if (jugador->final == 1)
                        finishGame = 1;

                    break;
                case 3:
                    finishGame = 3;
                    break ;
              }
        }
        // aqui option va a ser 0 si el jugador est� jugando manualmente o 2 si es random
        if (option == 2)
        {
            // continue random
            finishGame = 1;
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
        printf("\n\033[1;31m############################################################\n");
        printf("######  Westeros is invencible! Good luck next time.  ######\n");
        printf("############################################################\033[0;m\n");
    }


    if (finishGame == 3)
        printf("\nBye!\n");

    return 0;


}

