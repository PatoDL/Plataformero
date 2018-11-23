#include "jugador.h"

#include "SFML\Graphics.hpp"

using namespace std;

namespace juego
{
	Jugador::Jugador(float x, float y):Personaje(x,y)
	{
		
	}


	Jugador::~Jugador()
	{
	}

	void Jugador::mover()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			setY(getPos().y+1);
		}
	}
}