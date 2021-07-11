
typedef struct s_mapa{
    int enemigos_fuerza[31];
    int enemigos_tipo[31];
    int vivos_muertos[31];
}   t_mapa;

typedef struct s_westeros{
   int  bsoldados[20];
   int  barqueros[10];
   int  bzombies[5];
   int  reyMuerto;
   int  Tywin;
   int  Jaimie;
   int  Cersei;
   int  Tyrion;
   int  Stannis;
}   t_westeros;


// westeros.c
void    CreateWesterosMap(t_westeros *westeros);
void    CreateWesterosFile(t_westeros *westeros);
t_westeros *WesterosConfiguration(t_westeros *westeros);

// player.c
int AskConfiguration(int option);
