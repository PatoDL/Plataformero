#include "gameplay.h"

#include "jugador.h"
#include "juego.h"
#include "enemigo.h"
#include "mapa.h"

namespace juego
{
	Gameplay::Gameplay()
	{
		main = new Jugador(10, 10, { 10000.f,10000.f });
		enemy = new Enemigo(500, 500, { 500.f,500.f });
		map = new Mapa;
		view.setSize(static_cast<float>(Juego::getAnchoPantalla()), static_cast<float>(Juego::getAnchoPantalla()));
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
		map->getTileMap()->ShowObjects(true);
		view.setCenter(main->getPos());
		juego->getWindow()->setView(view);
		juego->getWindow()->draw(main->getCol());
		juego->getWindow()->draw(enemy->getCol());
		juego->getWindow()->draw(*map->getTileMap());
	}
}