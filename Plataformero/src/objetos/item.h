#ifndef	ITEM_H
#define ITEM_H

#include "SFML\Graphics.hpp"

namespace juego
{
	class Item
	{
	protected:
		sf::Sprite sprite;
	private:
		sf::RectangleShape collider;
		bool activo;
	public:
		Item();
		void setPosition(sf::Vector2f pos);
		void activar();
		void desactivar();
		void dibujar();
	};
}

#endif