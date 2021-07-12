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


    t_westeros westeros = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,2,3,4,5,6,7,0,0,0,0,0,0,0,0,0,0,0,0,0}, // se inicializa de esta manera para asegurar que hay almenos un enemigo ocupando cada localizacion
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,0,0,0,0},
                            500, 0,
                            300, 0, 250, 0, 200, 0, 150, 0, 300, 0,
                            NULL}; // Inicializando a 0 para despues sustituit por valores random

    WesterosConfiguration(&westeros); // El ejercito del enemigo no necesita confuguracion, se crea al inicio del programa

    if (westeros.error != NULL)
    {
        printf("ERROR: %s", westeros.error);
        return (0);
    }

    while (finishGame == 0)
    {
        if (option == 0 || option == 1) // Inicio de juego o nuevo turno
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
                    option = AskConfiguration(option); // Para empezar turno nuevo en el siguiente loop y que el jugador eliga nueva opcion

                    finishGame = 1; // el juego sigue hasta que esta var es 1 o el jugador elige Salir option = 3
                    // por ahora ponemos la variable a 1 para que no etre en bucle, pero se pondrá a 1 cuando haya ganador del juego más adelante
                    break;
                case 3:
                    finishGame = 3;
                    break ;
              }
        }
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

