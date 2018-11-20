#include "juego.h"

namespace Juego
{
	Juego::Juego()
	{
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
}