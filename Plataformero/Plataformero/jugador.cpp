#include "jugador.h"

#include "SFML\Graphics.hpp"
#include "juego.h"

using namespace std;

namespace juego
{
	Jugador::Jugador(float x, float y, Vector2f v):Personaje(x,y,v)
	{
		
	}


	Jugador::~Jugador()
	{
	}

	void Jugador::mover()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			setY(getPos().y + getVel().y*Juego::getFrameTime());
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			setY(getPos().y - getVel().y*Juego::getFrameTime());
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			setX(getPos().x - getVel().x*Juego::getFrameTime());
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			setX(getPos().x + getVel().x*Juego::getFrameTime());
		}
	}
}