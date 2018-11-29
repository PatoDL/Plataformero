#include "enemigo.h"

#include <iostream>

#include "juego.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	static Texture tex;
	static float tiempoAnimacion;
	static IntRect src;

	Enemigo::Enemigo(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		//setColPos(getCol().getPosition());
		setColSize({40.0f, 40.0f});
		setColColor(Color::Red);
		if (!tex.loadFromFile("res/assets/bug.png"))
		{
		}
		sprite.setTexture(tex);
		tiempoAnimacion = 0;
		src.left = 0;
		src.top = 0;
		src.width = sprite.getLocalBounds().width / 2;
		src.height = sprite.getLocalBounds().height;
		sprite.setTextureRect(src);
		sprite.setPosition(pos);
	}


	Enemigo::~Enemigo()
	{
	}

	void Enemigo::inicializar()
	{
		
		sprite.setTextureRect(src);
		sprite.setPosition(pos);
		sprite.setOrigin(sprite.getGlobalBounds().height, (sprite.getGlobalBounds().width / 2));
		setColOrigin(sprite.getOrigin());
		estaVivo = true;
	}

	void Enemigo::mover()
	{
		setX(getPos().x + getVel().x*Juego::getFrameTime());
	}

	void Enemigo::actualizar()
	{
		tiempoAnimacion += Juego::getFrameTime();

		if (getVel().x > 0)
		{
			sprite.setScale(-1, 1);
		}
		else
		{
			sprite.setScale(1, 1);
		}

		if (tiempoAnimacion < 0.25f)
		{
			src.left = 0;
		}
		else
		{
			src.left = src.width;
		}

		sprite.setTextureRect(src);

		if (tiempoAnimacion > 0.5f)
		{
			tiempoAnimacion = 0;
		}

		sprite.setPosition(pos);
		setColPos(pos);
	}

	void Enemigo::dibujar()
	{
		Juego::getWindow()->draw(sprite);
	}

	void Enemigo::chequearEnPlataforma(Mapa* map, int i)
	{
		if (getPos().x - getCol().getGlobalBounds().width/2 <= map->getPlataforma(map->getPlatConEnemigo(i)).getGlobalBounds().left || 
			getPos().x + getCol().getGlobalBounds().width / 2 >= map->getPlataforma(map->getPlatConEnemigo(i)).getGlobalBounds().left+ map->getPlataforma(map->getPlatConEnemigo(i)).getGlobalBounds().width)
		{
			setVel({ getVel().x*-1, getVel().y });
		}
	}

	bool Enemigo::getEstaVivo()
	{
		return estaVivo;
	}

	void Enemigo::setEstaVivo(bool vivo)
	{
		estaVivo = vivo;
	}
}