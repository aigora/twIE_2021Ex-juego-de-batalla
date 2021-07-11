#include <stdio.h>

int main(void)
{
    printf("##########        Battle  for  Westeros      ##########\n");

    // WesterosConfiguration(); // Aqui se inicia la configuracion del Enemigo (Westeros)

    int option = 0, finishGame = 0, turno = 0;

    char *menu = "\033[1;35m\nMenu:\n1 - Choose my configuration\n" \
                "2 - Continue Automatically (The game will run until there is a winner)\n" \
                "3 - Exit game\n\033[0;m";

    // Loop principal

    while (finishGame == 0 && option == 0)
    {
        if (option == 0) // Inicio de juego o nuevo turno
        {
           // Menu principal

           while (option != 1 && option != 2 && option != 3)
           {
              printf(menu);
              scanf("%i", &option);
              fflush(stdin); // para evitar bucles si el usuario introduce valor no int, se le vuelve a mostart el menu para que elija bien 1, 2 o 3
              printf("%i", option);
           }
           switch(option)
              {
                case 1:
                case 2:
                    // Juego empieza o continua
                    printf("Start Game");

                    turno += 1;
                    option = 0; // Para empezar turno nuevo en el siguiente loop y que el jugador eliga nueva opcion

                    finishGame = 1; // el juego sigue hasta que esta var es 1 o el jugador elige Salir option = 3
                    // por ahora ponemos la variable a 1 para que no etre en bucle, pero se pondrá a 1 cuando haya ganador del juego más adelante
                    break;
                case 3:
                    finishGame = 3;
                    break ;
              }
        }
    }


    if (finishGame == 3)
    {
        printf("\nBye!\n");
    }

    return 0;







}

