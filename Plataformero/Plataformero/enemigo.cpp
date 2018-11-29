#include "enemigo.h"
#include "juego.h"

#include <iostream>
#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	static Texture tex;
	static float tiempoAnimacion;
	static IntRect src;
	Enemigo::Enemigo(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		setColPos(getCol().getPosition());
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

	void Enemigo::mover()
	{
		setX(getPos().x - getVel().x*Juego::getFrameTime());
	}

	void Enemigo::update()
	{
		tiempoAnimacion += Juego::getFrameTime();

		if (tiempoAnimacion < 0.5f)
		{
			src.left = 0;
		}
		else
		{
			src.left = src.width;
		}

		

		if (tiempoAnimacion > 1)
		{
			tiempoAnimacion = 0;
		}
	}

	void Enemigo::draw()
	{
		Juego::getWindow()->draw(sprite);
	}
}