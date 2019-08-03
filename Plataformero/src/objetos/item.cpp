#include "item.h"

#include "juego/juego.h"

namespace juego
{
	Item::Item()
	{
		activo = true;
	}

	void Item::setPosition(sf::Vector2f pos)
	{
		sprite.setPosition(pos);
		collider.setPosition(pos);
	}

	void Item::activar()
	{
		activo = true;
	}

	void Item::desactivar()
	{
		activo = false;
	}

	void Item::dibujar()
	{
		if(activo)
			Juego::getWindow()->draw(sprite);
	}
}