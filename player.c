#include "game.h"



// Funcion qu determina la configuracion con la que juega el jugador
// En cada turno se le pregunta al jugador la configuracion de su Ejercito
// anoser que en el menu principal haya elegido la opcion 2
// opcion 2 ejecuta el juego de manera random hasta que haya un ganador
// retun 0 para opcion 1 (se vuelve al menu principal)
// return 2 para opcion 2 (no se vuelve a interactuar con el jugador)


int AskConfiguration(int option)
{




    if (option == 2)
        return 2;
    return 0;
}
