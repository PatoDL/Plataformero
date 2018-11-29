#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

#include "SFML/Graphics.hpp"
#include "mapa.h"

const int cantEnemigos = 5;

namespace juego
{
	class Enemigo : public Personaje
	{
	private:
		bool estaVivo;
	public:
		Enemigo(float x, float y,sf::Vector2f v);
		~Enemigo();
		void inicializar();
		void mover();
		void actualizar();
		void dibujar();
		void chequearEnPlataforma(Mapa* map, int i);
		bool getEstaVivo();
		void setEstaVivo(bool vivo);
	};
}
#endif