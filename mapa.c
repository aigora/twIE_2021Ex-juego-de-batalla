#include "game.h"

/*
    Funcion auxiliar para escribir en el fichero map.txt
    el contenido de la estructura map
*/
void    ContenidoMapaXLocalizacion(t_mapa *mapa, int localizacion, FILE *map)
{
    if (localizacion == 0)
        fprintf(map, "King's Landing\n");
    if (localizacion == 1)
        fprintf(map, "\n\nWinterfell\n");
    if (localizacion == 2)
        fprintf(map, "\n\nThe Wall\n");
    if (localizacion == 3)
        fprintf(map, "\n\nStorm's End\n");
    if (localizacion == 4)
        fprintf(map, "\n\nRiverrun\n");
    if (localizacion == 5)
        fprintf(map, "\n\nCasterlyRock\n");
    if (localizacion == 6)
        fprintf(map, "\n\nSunspear\n");

    for(int i = 0; i < 30; i++)
    {
        if (mapa[localizacion].enemigos_fuerza[i] != 0)
        {
            if (mapa[localizacion].enemigos_tipo[i] == 's')
                fprintf(map, "[∆-%i]", mapa[localizacion].enemigos_fuerza[i]);
            if (mapa[localizacion].enemigos_tipo[i] == 'a')
                fprintf(map, "[⩥-%i]", mapa[localizacion].enemigos_fuerza[i]);
            if (mapa[localizacion].enemigos_tipo[i] == 'z')
                fprintf(map, "[§-%i]", mapa[localizacion].enemigos_fuerza[i]);

            if (mapa[localizacion].enemigos_tipo[i] == 'M')
                fprintf(map, "[ReyMuerto-%i]", mapa[localizacion].enemigos_fuerza[i]);
            if (mapa[localizacion].enemigos_tipo[i] == 'T')
                fprintf(map, "[Tywin-%i]", mapa[localizacion].enemigos_fuerza[i]);
            if (mapa[localizacion].enemigos_tipo[i] == 'J')
                fprintf(map, "[Jaimie-%i]", mapa[localizacion].enemigos_fuerza[i]);
            if (mapa[localizacion].enemigos_tipo[i] == 'C')
                fprintf(map, "[Cersei-%i]", mapa[localizacion].enemigos_fuerza[i]);
            if (mapa[localizacion].enemigos_tipo[i] == 't')
                fprintf(map, "[Tyrion-%i]", mapa[localizacion].enemigos_fuerza[i]);
            if (mapa[localizacion].enemigos_tipo[i] == 'S')
                fprintf(map, "[Stannis-%i]", mapa[localizacion].enemigos_fuerza[i]);
        }
    }
}

void    AddGeneralesMapa(t_westeros *westeros, t_mapa *mapa, int *contador, int localizacion)
{

    if (westeros->localizacion_reyMuerto == localizacion+1)
    {
        mapa[localizacion].enemigos_fuerza[*contador] = westeros->reyMuerto;
        mapa[localizacion].enemigos_tipo[*contador] = 'M';
        (*contador)++;
    }
    if (westeros->localizacion_tywin == localizacion+1)
    {
        mapa[localizacion].enemigos_fuerza[*contador] = westeros->Tywin;
        mapa[localizacion].enemigos_tipo[*contador] = 'T';
        (*contador)++;
    }
    if (westeros->localizacion_jaimie == localizacion+1)
    {
        mapa[localizacion].enemigos_fuerza[*contador] = westeros->Jaimie;
        mapa[localizacion].enemigos_tipo[*contador] = 'J';
        (*contador)++;
    }
    if (westeros->localizacion_cersei == localizacion+1)
    {
        mapa[localizacion].enemigos_fuerza[*contador] = westeros->Cersei;
        mapa[localizacion].enemigos_tipo[*contador] = 'C';
        (*contador)++;
    }
    if (westeros->localizacion_tyrion == localizacion+1)
    {
        mapa[localizacion].enemigos_fuerza[*contador] = westeros->Tyrion;
        mapa[localizacion].enemigos_tipo[*contador] = 't';
        (*contador)++;
    }
    if (westeros->localizacion_stannis == localizacion+1)
    {
        mapa[localizacion].enemigos_fuerza[*contador] = westeros->Stannis;
        mapa[localizacion].enemigos_tipo[*contador] = 'S';
        (*contador)++;
    }
}

/*
    Funcion que añade cada batallon de soldados/arqueros/zombies
    a su correspondiente localizacion en el mapa
*/
void    AddEnemigosMapa(t_westeros *westeros, t_mapa *mapa)
{
    int mapa0 = 0, mapa1 = 0, mapa2 = 0, mapa3 = 0, mapa4 = 0, mapa5 = 0, mapa6 = 0;

    for (int i=0; i < 20; i++)
    {
        if (westeros->localizaciones_soldados[i] == 1)
        {
            mapa[0].enemigos_fuerza[mapa0] = westeros->bsoldados[i];
            mapa[0].enemigos_tipo[mapa0] = 's';
            mapa0++;
        }
        if (westeros->localizaciones_soldados[i] == 2)
        {
            mapa[1].enemigos_fuerza[mapa1] = westeros->bsoldados[i];
            mapa[1].enemigos_tipo[mapa1] = 's';
            mapa1++;
        }
        if (westeros->localizaciones_soldados[i] == 3)
        {
            mapa[2].enemigos_fuerza[mapa2] = westeros->bsoldados[i];
            mapa[2].enemigos_tipo[mapa2] = 's';
            mapa2++;
        }
        if (westeros->localizaciones_soldados[i] == 4)
        {
            mapa[3].enemigos_fuerza[mapa3] = westeros->bsoldados[i];
            mapa[3].enemigos_tipo[mapa3] = 's';
            mapa3++;
        }
        if (westeros->localizaciones_soldados[i] == 5)
        {
            mapa[4].enemigos_fuerza[mapa4] = westeros->bsoldados[i];
            mapa[4].enemigos_tipo[mapa4] = 's';
            mapa4++;
        }
        if (westeros->localizaciones_soldados[i] == 6)
        {
            mapa[5].enemigos_fuerza[mapa5] = westeros->bsoldados[i];
            mapa[5].enemigos_tipo[mapa5] = 's';
            mapa5++;
        }
        if (westeros->localizaciones_soldados[i] == 7)
        {
            mapa[6].enemigos_fuerza[mapa6] = westeros->bsoldados[i];
            mapa[6].enemigos_tipo[mapa6] = 's';
            mapa6++;
        }
    }

    for (int i=0; i<10; i++)
    {
        if (westeros->localizaciones_arqueros[i] == 1)
        {
            mapa[0].enemigos_fuerza[mapa0] = westeros->barqueros[i];
            mapa[0].enemigos_tipo[mapa0] = 'a';
            mapa0++;
        }
        if (westeros->localizaciones_arqueros[i] == 2)
        {
            mapa[1].enemigos_fuerza[mapa1] = westeros->barqueros[i];
            mapa[1].enemigos_tipo[mapa1] = 'a';
            mapa1++;
        }
        if (westeros->localizaciones_arqueros[i] == 3)
        {
            mapa[2].enemigos_fuerza[mapa2] = westeros->barqueros[i];
            mapa[2].enemigos_tipo[mapa2] = 'a';
            mapa2++;
        }
        if (westeros->localizaciones_arqueros[i] == 4)
        {
            mapa[3].enemigos_fuerza[mapa3] = westeros->barqueros[i];
            mapa[3].enemigos_tipo[mapa3] = 'a';
            mapa3++;
        }
        if (westeros->localizaciones_arqueros[i] == 5)
        {
            mapa[4].enemigos_fuerza[mapa4] = westeros->barqueros[i];
            mapa[4].enemigos_tipo[mapa4] = 'a';
            mapa4++;
        }
        if (westeros->localizaciones_arqueros[i] == 6)
        {
            mapa[5].enemigos_fuerza[mapa5] = westeros->barqueros[i];
            mapa[5].enemigos_tipo[mapa5] = 'a';
            mapa5++;
        }
        if (westeros->localizaciones_arqueros[i] == 7)
        {
            mapa[6].enemigos_fuerza[mapa6] = westeros->barqueros[i];
            mapa[6].enemigos_tipo[mapa6] = 'a';
            mapa6++;
        }
    }
    for (int i=0; i<5; i++)
    {
        if (westeros->localizaciones_zombies[i] == 1)
        {
            mapa[0].enemigos_fuerza[mapa0] = westeros->bzombies[i];
            mapa[0].enemigos_tipo[mapa0] = 'z';
            mapa0++;
        }
        if (westeros->localizaciones_zombies[i] == 2)
        {
            mapa[1].enemigos_fuerza[mapa1] = westeros->bzombies[i];
            mapa[1].enemigos_tipo[mapa1] = 'z';
            mapa1++;
        }
        if (westeros->localizaciones_zombies[i] == 3)
        {
            mapa[2].enemigos_fuerza[mapa2] = westeros->bzombies[i];
            mapa[2].enemigos_tipo[mapa2] = 'z';
            mapa2++;
        }
        if (westeros->localizaciones_zombies[i] == 4)
        {
            mapa[3].enemigos_fuerza[mapa3] = westeros->bzombies[i];
            mapa[3].enemigos_tipo[mapa3] = 'z';
            mapa3++;
        }
        if (westeros->localizaciones_zombies[i] == 5)
        {
            mapa[4].enemigos_fuerza[mapa4] = westeros->bzombies[i];
            mapa[4].enemigos_tipo[mapa4] = 'z';
            mapa4++;
        }
        if (westeros->localizaciones_zombies[i] == 6)
        {
            mapa[5].enemigos_fuerza[mapa5] = westeros->bzombies[i];
            mapa[5].enemigos_tipo[mapa5] = 'z';
            mapa5++;
        }
        if (westeros->localizaciones_zombies[i] == 7)
        {
            mapa[6].enemigos_fuerza[mapa6] = westeros->bzombies[i];
            mapa[6].enemigos_tipo[mapa6] = 'z';
            mapa6++;
        }
    }

    AddGeneralesMapa(westeros, mapa, &mapa0, 0);
    AddGeneralesMapa(westeros, mapa, &mapa1, 1);
    AddGeneralesMapa(westeros, mapa, &mapa2, 2);
    AddGeneralesMapa(westeros, mapa, &mapa3, 3);
    AddGeneralesMapa(westeros, mapa, &mapa4, 4);
    AddGeneralesMapa(westeros, mapa, &mapa5, 5);
    AddGeneralesMapa(westeros, mapa, &mapa6, 6);
}


/*
    Funcion para crear el fichero map.txt
    map.txt almacena las posiciones de cada batallon y cada general
    con sus correspondientes fuerzas y simbolo representativo
    El jugador podrá consultarlo y ver donde le conviene atacar
*/
void    CreateMap(t_westeros *westeros, t_mapa *mapa)
{
    FILE *map;
    map = fopen("map.txt", "w");
    if (map == NULL)
    {   // Si el resultado es NULL mensaje de error
        westeros->error = ERROR_MAP;
    }
    else
    {
        fprintf(map, "\t\tWESTEROS MAP\n\n");

        westeros->localizacion_reyMuerto = (rand() % 7) + 1;
        westeros->localizacion_tywin = (rand() % 7) + 1;
        westeros->localizacion_jaimie = (rand() % 7) + 1;
        westeros->localizacion_cersei = (rand() % 7) + 1;
        westeros->localizacion_tyrion = (rand() % 7) + 1;
        westeros->localizacion_stannis = (rand() % 7) + 1;

        // Asignando valores para las 7 localizaciones

        AddEnemigosMapa(westeros, mapa);

        ContenidoMapaXLocalizacion(mapa, 0, map);
        ContenidoMapaXLocalizacion(mapa, 1, map);
        ContenidoMapaXLocalizacion(mapa, 2, map);
        ContenidoMapaXLocalizacion(mapa, 3, map);
        ContenidoMapaXLocalizacion(mapa, 4, map);
        ContenidoMapaXLocalizacion(mapa, 5, map);
        ContenidoMapaXLocalizacion(mapa, 6, map);

        fclose(map);
    }
}

int     ZonaConquistada(t_mapa *mapa, int localizacion)
{
    int conquista =0;
    int i = 0;


    if (localizacion == 1)
    {
        for (int j=0; j<30; j++)
        {
            if(mapa[0].enemigos_fuerza[j] == 0)
                i++;
            if (i == 30)
                conquista = 1;
        }
    }
    if (localizacion == 2)
    {
        for (int j=0; j<30; j++)
        {
            if(mapa[1].enemigos_fuerza[j] == 0)
                i++;
            if (i == 30)
                conquista = 1;
        }
    }
    if (localizacion == 3)
    {
        for (int j=0; j<30; j++)
        {
            if(mapa[2].enemigos_fuerza[j] == 0)
                i++;
            if (i == 30)
                conquista = 1;
        }
    }
    if (localizacion == 4)
    {
        for (int j=0; j<30; j++)
        {
            if(mapa[3].enemigos_fuerza[j] == 0)
                i++;
            if (i == 30)
                conquista = 1;
        }
    }
    if (localizacion == 5)
    {
        for (int j=0; j<30; j++)
        {
            if(mapa[4].enemigos_fuerza[j] == 0)
                i++;
            if (i == 30)
                conquista = 1;
        }
    }
    if (localizacion == 6)
    {
        for (int j=0; j<30; j++)
        {
            if(mapa[5].enemigos_fuerza[j] == 0)
                i++;
            if (i == 30)
                conquista = 1;
        }
    }
    if (localizacion == 7)
    {
        for (int j=0; j<30; j++)
        {
            if(mapa[6].enemigos_fuerza[j] == 0)
                i++;
            if (i == 30)
                conquista = 1;
        }
    }
    return (conquista);
}
