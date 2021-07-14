# Juego de Batalla:


## Integrantes del equipo:

Diego Fernandes Alves. ([DiegoFernandesAlves](https://github.com/DiegoFernandesAlves))

Diego Bastida Juanes. ([DiegoBastida](https://github.com/DiegoBastida))

## Objetivo:

El objetivo de este ejercicio es diseñar e implementar un juego de batalla simplificado donde el jugador liderará el ejército de Daenerys Targaryen y sus tres dragones contra las fuerzas combinadas de Westeros (los generales Tywin, Jaimie, Cersei, Tyrion, Stannis y el Rey Muerto)


# Modo de empleo:

```
gcc *.c
./a.out
```
ó

```
gcc *.c -Wall -Wextra -Werror
./a.out
```

```(./a.out ó a./exe)```

La Configuracion de ambos ejercitos es asignada de forma random, por lo que las probabilidades de ganar/perder varían en cada ronda. Los generales mantienen fuerzas fijas.

Para consultar al principio del juego las Configuraciones del ejercito ir a westeros.txt y jugador.txt.
En map.txt se puede consultar qué ejercito/general protege la localizacion, entre las 7 zonas de Westeros. 

(No es necesario realizar las consultas, se puede jugar sin mirar los datos pero consultarlo ayudará a decidir a qué zona atacar o como elaborar la estrategia)

El menu principal te lleva a empezar/seguir jugando o Salir. 
Una vez empezado compienzan las batallas. Los ejercitos se enfretan por rondas. El perdedor se queda sin fuerzas, y el contrincante reduce su fuerza a la mitad. 

En caso de que no quede ejercito en dicha zona, se avisará al jugador y se seguirá preguntando a que nueva zona atacar hasta que elija correctamente una nueva zona inexplorada ó con enemigos en pie todavía.

El juego termina cuando el mapa está vacío, es decir no queda ejercito en ninguna de las zonas (El Jugador Gana) o cuando no queda ejercito del jugador (El Jugador Pierde) y se notifica con un mensaje. 

Todas las batallas pueden ser consultadas en results.txt, donde aparece la zona atacada. 
[enemigo]vs[jugador]->[ganador]
