#include "gameplay.h"

#include "jugador.h"
#include "juego.h"
#include "enemigo.h"
namespace juego
{
	Gameplay::Gameplay()
	{
		main = new Jugador(10, 10, { 1000.f,1000.f });
		enemy = new Enemigo(500, 500, { 500.f,500.f });
		view.setSize(static_cast<float>(Juego::getAnchoPantalla()/2), static_cast<float>(Juego::getAnchoPantalla()/2));
		view.setCenter(main->getPos());
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
		enemy->mover();
		main->update();
		enemy->update();
	}

	void Gameplay::draw(Juego* juego)
	{
		view.setCenter(main->getPos());
		juego->getWindow()->setView(view);
		juego->getWindow()->draw(main->getCol());
		juego->getWindow()->draw(enemy->getCol());
	}
}