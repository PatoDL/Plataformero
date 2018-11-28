#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"
#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	class Jugador : public Personaje
	{
	public:
		Jugador(float x, float y, Vector2f v);
		~Jugador();
		void mover();
		void update();
		void draw();
		Jugador getJug();
	};
}

#endif