#ifndef COLISIONES_H
#define COLISIONES_H

#include "SFML\Graphics.hpp"
#include "jugador.h"
#include "mapa.h"

namespace juego {
	struct vecColisiones
	{
		bool _izq;
		bool _der;
		bool _abajo;
		bool _arriba;
	};

	class Colisiones
	{
	private:
		vecColisiones posColision;
	public:
		Colisiones();
		~Colisiones();
		vecColisiones getColision();
		void procesarJugadorPlataformas(Jugador* jug, Mapa* mapa);
		bool colisionaAbajo(Jugador* jug, Mapa* mapa, int i);
		bool colisionaArriba(Jugador* jug, Mapa* mapa, int i);		//CON RESPECTO AL PERSONAJE
		bool colisionaIzq(Jugador* jug, Mapa* mapa, int i);
		bool colisionaDer(Jugador* jug, Mapa* mapa, int i);
		bool jugadorEnPlataformaX(Jugador* jug, Mapa* mapa, int i);
		bool jugadorEnPlataformaY(Jugador* jug, Mapa* mapa, int i);
	};
}

#endif