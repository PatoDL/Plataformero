#include "item.h"

#include "juego/juego.h"

namespace juego
{
	Item::Item()
	{
		activo = true;
	}

	void Item::inicializar(sf::Vector2f pos)
	{
		collider.setSize({ 40.f, 40.f });
		collider.setOrigin(sprite.getOrigin());
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

	bool Item::estaActivo()
	{
		return activo;
	}

	RectangleShape Item::getCol()
	{
		return collider;
	}
}