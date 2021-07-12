
#define ERROR_MAP "Error al abrir el fichero map.txt.\n"
#define ERROR_WESTEROS "Error al abrir el fichero westeros.txt.\n"




typedef struct s_mapa{
    int enemigos_fuerza[31];
    char enemigos_tipo[31];
    int vivos_muertos[31]; //mirar mas tarde si hace falta
}   t_mapa;

typedef struct s_westeros{
   int  bsoldados[20];
   int  localizaciones_soldados[20];
   int  barqueros[10];
   int  localizaciones_arqueros[10];
   int  bzombies[5];
   int  localizaciones_zombies[5];
   int  reyMuerto;
   int  localizacion_reyMuerto;
   int  Tywin;
   int  localizacion_tywin;
   int  Jaimie;
   int  localizacion_jaimie;
   int  Cersei;
   int  localizacion_cersei;
   int  Tyrion;
   int  localizacion_tyrion;
   int  Stannis;
   int  localizacion_stannis;
   char *error;
}t_westeros;


// westeros.c
void    CreateWesterosMap(t_westeros *westeros);
void    CreateWesterosFile(t_westeros *westeros);
t_westeros *WesterosConfiguration(t_westeros *westeros);

// player.c
int AskConfiguration(int option);
