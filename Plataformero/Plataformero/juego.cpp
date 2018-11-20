#include "juego.h"

#include <iostream>
#include "gameplay.h"

namespace Juego
{
	Juego::Juego()
	{
		_inGame = true;

		for (int i = 0; i < cantPantallas; i++)
		{
			pantalla[i] = NULL;
		}

		pantalla[0] = new Gameplay();
	}

	Juego::~Juego()
	{
	}

	void Juego::setInGame(bool inGame)
	{
		_inGame = inGame;
	}

	bool Juego::getInGame()
	{
		return _inGame;
	}

	void Juego::ejecutar()
	{

	}
}