#ifndef COLISIONES_H
#define COLISIONES_H

#include "SFML\Graphics.hpp"
#include "jugador.h"
#include "mapa.h"

namespace juego {
	class Colisiones
	{
	public:
		Colisiones();
		~Colisiones();
		void procesarJugadorPlataformas(Jugador* jug, Mapa* mapa, float difColisionX, float difColisionY);
		bool colisionaAbajo(Jugador* jug,RectangleShape plataforma);
		bool colisionaArriba(Jugador* jug, RectangleShape plataforma);		//CON RESPECTO AL PERSONAJE
		bool colisionaIzq(Jugador* jug, RectangleShape plataforma);
		bool colisionaDer(Jugador* jug, RectangleShape plataforma);
		bool jugadorEnPlataformaX(Jugador* jug, RectangleShape plataforma);
		bool jugadorEnPlataformaY(Jugador* jug, RectangleShape plataforma);
		void procesarJugadorLimites(Jugador* jug, Mapa* mapa, float difColisionX,float difColisionY);
		void procesarColisiones(Jugador* jug, Mapa* mapa);
	};
}

#endif