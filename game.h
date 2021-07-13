#include <stdio.h>
#include <stdlib.h> // random rand()
#include <time.h> // time(NULL)

#define ERROR_MAP "Error al abrir el fichero map.txt.\n"
#define ERROR_WESTEROS "Error al abrir el fichero westeros.txt.\n"
#define ERROR_EJERCITO "Error al abrir el fichero jugador.txt.\n"


typedef struct s_jugador{
    int     ejercito[30];
    char    tipo[30];
    int     localizacion_ataque;
    int     final;
    char   *error;
}   t_jugador;



typedef struct s_mapa{
    int     enemigos_fuerza[31];
    char    enemigos_tipo[31];
    int     zona_conquistada;
}   t_mapa;


//Estructura que contiene informacion del ejercito enemigo


typedef struct s_westeros{
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
}t_westeros;


// westeros.c
void CreateWesterosFile(t_westeros *westeros, t_mapa *mapa);
t_westeros  *WesterosConfiguration(t_westeros *westeros);

// jugador.c
int         AskConfiguration(int option, t_mapa *mapa, t_jugador *jugador);
void        EjercitoJugador(t_jugador *jugador);

// mapa.c
void ContenidoMapaXLocalizacion(t_westeros *westeros, t_mapa *mapa, int localizacion, FILE *map);
void AddGeneralesMapa(t_westeros *westeros, t_mapa *mapa, int *contador, int localizacion);
void AddEnemigosMapa(t_westeros *westeros, t_mapa *mapa);
void CreateMap(t_westeros *westeros, t_mapa *mapa);

// batalla.c
int     Ataque(t_mapa *mapa, t_jugador *jugador, int localizacion);
