#include "gameplay.h"

#include <iostream>
#include "jugador.h"
#include "juego.h"
#include <string>

namespace juego
{
	Gameplay::Gameplay()
	{
		main = new Jugador(10,10);
	}

	Gameplay::~Gameplay()
	{
		delete main;
	}

	void Gameplay::checkInput()
	{
		main->mover();
	}

	void Gameplay::update()
	{
		main->update();
	}

	void Gameplay::draw(Juego* juego)
	{
		juego->getWindow()->draw(main->getCol());
	}
}