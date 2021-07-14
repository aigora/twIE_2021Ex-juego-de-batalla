
#include <stdio.h>
#include <stdlib.h> // random rand()
#include <time.h> // time(NULL)

#define ERROR_MAP "Error al abrir el fichero map.txt.\n"
#define ERROR_WESTEROS "Error al abrir el fichero westeros.txt.\n"
#define ERROR_EJERCITO "Error al abrir el fichero jugador.txt.\n"


typedef struct {
    int     ejercito[20];
    char    tipo[20];
    int     localizacion_ataque;
    char   *error;
}   t_jugador;


typedef struct {
    int     enemigos_fuerza[30];
    char    enemigos_tipo[30];
    int     zona_conquistada;
}   t_mapa;

/*
    Estructura que contiene informacion del ejercito enemigo
*/
typedef struct {
   int      bsoldados[20];
   int      localizaciones_soldados[20];
   int      barqueros[10];
   int      localizaciones_arqueros[10];
   int      bzombies[5];
   int      localizaciones_zombies[5];
   int      reyMuerto;
   int      localizacion_reyMuerto;
   int      Tywin;
   int      localizacion_tywin;
   int      Jaimie;
   int      localizacion_jaimie;
   int      Cersei;
   int      localizacion_cersei;
   int      Tyrion;
   int      localizacion_tyrion;
   int      Stannis;
   int      localizacion_stannis;
   char     *error;
}   t_westeros;


// westeros.c
void        CreateWesterosFile(t_westeros *westeros);
t_westeros  *WesterosConfiguration(t_westeros *westeros, t_mapa *mapa);

// jugador.c
int         AskConfiguration(t_mapa *mapa);
void        EjercitoJugador(t_jugador *jugador);

// mapa.c
void        ContenidoMapaXLocalizacion(t_mapa *mapa, int localizacion, FILE *map);
void        AddGeneralesMapa(t_westeros *westeros, t_mapa *mapa, int *contador, int localizacion);
void        AddEnemigosMapa(t_westeros *westeros, t_mapa *mapa);
void        CreateMap(t_westeros *westeros, t_mapa *mapa);
int         ZonaConquistada(t_mapa *mapa, int localizacion);

// batalla.c
int     Ataque(t_mapa *mapa, t_jugador *jugador, int localizacion);
