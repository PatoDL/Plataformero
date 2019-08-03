#ifndef	ITEM_H
#define ITEM_H

#include "SFML\Graphics.hpp"

namespace juego
{
	class Item
	{
	protected:
		sf::Sprite sprite;
	public:
		Item();
		virtual ~Item();
		void setPosition(sf::Vector2f pos);
	};
}

#endif