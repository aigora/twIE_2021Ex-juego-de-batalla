
#include "game.h"

int     Ataque(t_mapa *mapa, t_jugador *jugador,int localizacion)
{
    for(int i=0; i<31; i++)
    {
        if (mapa[localizacion].enemigos_fuerza[i] != 0)
        {
            // westeros vs ejercito. Quien tenga mayor fuerza gana. El perdedor reduce sus fuerzas 1/3 del enemigo
            if ((mapa[localizacion].enemigos_fuerza[i] > jugador->ejercito[i])
                jugador->ejercito[i] = 0;
            else
                mapa[localizacion].enemigos_fuerza[i] = 0;

        }
    }

}
