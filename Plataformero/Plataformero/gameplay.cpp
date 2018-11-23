#include "gameplay.h"

#include "jugador.h"
#include "juego.h"
#include "enemigo.h"
namespace juego
{
	Gameplay::Gameplay()
	{
		main = new Jugador(10,10);
		enemy = new Enemigo(500, 500);
	}

	Gameplay::~Gameplay()
	{
		delete main;
	}

	void Gameplay::checkInput()
	{
		main->mover();
		enemy->mover();
	}

	void Gameplay::update()
	{
		main->update();
		enemy->update();
	}

	void Gameplay::draw(Juego* juego)
	{
		juego->getWindow()->draw(main->getCol());
		juego->getWindow()->draw(enemy->getCol());
	}
}