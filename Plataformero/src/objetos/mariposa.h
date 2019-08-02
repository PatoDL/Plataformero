#ifndef MARIPOSA_H
#define MARIPOSA_H

#include "personaje.h"
#include "mapa.h"

#include "SFML/Graphics.hpp"

const int cantMariposas = 3;

namespace juego
{
	class Mariposa : public Personaje
	{
	private:
		bool estaVivo;
	public:
		Mariposa(float x, float y,sf::Vector2f v);
		~Mariposa();
		void inicializar();
		void mover();
		void actualizar();
		void dibujar();
		void chequearEnLimitesMapa(Mapa* map, int i);
		bool getEstaVivo();
		void setEstaVivo(bool vivo);
	};
}
#endif