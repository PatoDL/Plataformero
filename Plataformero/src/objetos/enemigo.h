#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"
#include "mapa.h"

#include "SFML/Graphics.hpp"

const int cantEscarabajos = 5;

namespace juego
{
	class Escarabajo : public Personaje
	{
	private:
		bool estaVivo;
		IntRect src;
	public:
		Escarabajo(float x, float y,sf::Vector2f v);
		~Escarabajo();
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