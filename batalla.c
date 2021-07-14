
#include "game.h"

int     Ataque(t_mapa *mapa, t_jugador *jugador, int localizacion)
{
    int perdedorJugador = 0, batalla = 0, i = 0, j = 0;
    FILE *a;
    a = fopen("resultados.txt", "a");

    if (localizacion == 0)
        fprintf(a, "King's Landing\n");
    if (localizacion == 1)
        fprintf(a, "\n\nWinterfell\n");
    if (localizacion == 2)
        fprintf(a, "\n\nThe Wall\n");
    if (localizacion == 3)
        fprintf(a, "\n\nStorm's End\n");
    if (localizacion == 4)
        fprintf(a, "\n\nRiverrun\n");
    if (localizacion == 5)
        fprintf(a, "\n\nCasterlyRock\n");
    if (localizacion == 6)
        fprintf(a, "\n\nSunspear\n");

    // 30 es el maximo de ejercitos por zona de mapa

    while (i < 30)
    {
        if (mapa[localizacion].enemigos_fuerza[i] != 0)
        {
            // westeros vs ejercito. Quien tenga mayor fuerza gana. El perdedor muere y se queda a 0. El ganador pierde la mitad de su eenrgia
            while (j < 20 && batalla == 0) // batalla si ambos son != 0
            {
                if (jugador->ejercito[j] != 0)
                {
                    batalla = 1;
                    printf("\n[%i-%c]vs\x1b[32m[%i-%c]\x1b[0m", mapa[localizacion].enemigos_fuerza[i], mapa[localizacion].enemigos_tipo[i], jugador->ejercito[j], jugador->tipo[j] );
                    fprintf(a,"\n[%i-%c]vs[%i-%c]", mapa[localizacion].enemigos_fuerza[i], mapa[localizacion].enemigos_tipo[i], jugador->ejercito[j], jugador->tipo[j] );
                    if (mapa[localizacion].enemigos_fuerza[i] >= jugador->ejercito[j])
                    {
                        jugador->ejercito[j] = 0;
                        mapa[localizacion].enemigos_fuerza[i] -= (int)(mapa[localizacion].enemigos_fuerza[i]/2);
                        if (jugador->ejercito[j] < 0)
                            jugador->ejercito[j] = 0;
                        printf("->[%i-%c]", mapa[localizacion].enemigos_fuerza[i], mapa[localizacion].enemigos_tipo[i]);
                        fprintf(a,"->[%i-%c]", mapa[localizacion].enemigos_fuerza[i], mapa[localizacion].enemigos_tipo[i]);
                    }
                    else
                    {
                        mapa[localizacion].enemigos_fuerza[i] = 0;
                        jugador->ejercito[j] -= (int)(jugador->ejercito[j]/2);
                        if (mapa[localizacion].enemigos_fuerza[i]<0)
                            mapa[localizacion].enemigos_fuerza[i] = 0;
                        printf("->\x1b[32m[%i-%c]\x1b[0m",jugador->ejercito[j], jugador->tipo[j]);
                        fprintf(a,"->[%i-%c]",jugador->ejercito[j], jugador->tipo[j]);
                    }
                    j++;
                }
                else
                    j++;
            }
            batalla = 0;
            if (j == 20)
                j = 0;
            // una vez que han luchado todos del ejercito pero no han ganado, otra ronda
        }
        i++;

    }

    if (ZonaConquistada(mapa, 1) && ZonaConquistada(mapa, 2) && ZonaConquistada(mapa, 3) && ZonaConquistada(mapa, 4) && ZonaConquistada(mapa, 5) && ZonaConquistada(mapa, 6) && ZonaConquistada(mapa, 7))
        return (1);

    for (int i=0; i<20;i++)
    {
        if (jugador->ejercito[i] == 0)
            perdedorJugador++;
    }
    if (perdedorJugador == 20)
        return (2);

    printf("\n\x1b[34mBatalla terminada. Consulta <map.txt> para ver donde te conviene atacar. \x1b[0m");
    fprintf(a,"\n\n\n");
    return (0);
}
