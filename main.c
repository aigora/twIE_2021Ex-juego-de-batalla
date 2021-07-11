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

    while (finishGame == 0)
    {
        while (option != 1 && option != 2 && option != 3)
    }







}

