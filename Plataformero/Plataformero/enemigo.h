#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

#include "SFML/Graphics.hpp"
#include "mapa.h"

namespace juego
{
	class Enemigo : public Personaje
	{
	public:
		Enemigo(float x, float y,sf::Vector2f v);
		~Enemigo();
		void inicializar();
		void mover();
		void actualizar();
		void dibujar();
		void chequearEnPlataforma(Mapa* map, int i);
	};
}
#endif