#include "enemigo.h"
#include "juego.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	Enemigo::Enemigo(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		setColPos(getCol().getPosition());
		setColSize({40.0f, 40.0f});
		setColColor(Color::Red);
	}


	Enemigo::~Enemigo()
	{
	}

	void Enemigo::mover()
	{
		setX(getPos().x - getVel().x*Juego::getFrameTime());
	}

	void Enemigo::draw()
	{

	}
}