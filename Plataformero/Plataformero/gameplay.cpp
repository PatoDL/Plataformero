#include "gameplay.h"

#include "jugador.h"
#include "juego.h"
#include "enemigo.h"
#include "mapa.h"

using namespace tgui;

namespace juego
{
	const int tam_tiles = 32;

	Gameplay::Gameplay()
	{
		main = new Jugador(10, 10, { 1000.f,1000.f });
		enemy = new Enemigo(500, 500, { 500.f,500.f });
		map = new Mapa;
		view.setSize(static_cast<float>(Juego::getAnchoPantalla()/2.5f), static_cast<float>(Juego::getAnchoPantalla()/2.5f));
		view.setCenter(main->getPos());
		
	}

	Gameplay::~Gameplay()
	{
		delete main;
		delete map;
		delete enemy;
	}

	void Gameplay::init()
	{
		main = new Jugador(10, 10, { 1000.f,1000.f });
		enemy = new Enemigo(500, 500, { 500.f,500.f });
		map = new Mapa;
		view.setSize(static_cast<float>(Juego::getAnchoPantalla() / 2.5f), static_cast<float>(Juego::getAnchoPantalla() / 2.5f));
		view.setCenter(main->getPos());
		pause = tgui::Button::create();

		pause->setSize(40, 40);
		pause->setText("xd");
		pause->setPosition(Juego::getAnchoPantalla() - pause->getSize().x*1.5f, pause->getSize().y / 2);
		pause->setRenderer(Juego::getTheme().getRenderer("Button"));
		pause->connect("pressed", [&]() {Juego::setEstadoActual(pausa); });
		Juego::getGui()->add(pause);
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

		if (main->getPos().x <= view.getSize().x/2) 
		{
			if (main->getPos().y <= view.getSize().y / 2)
			{
				view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
			}
			else if(main->getPos().y >=map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2)
			{
				view.setCenter(view.getSize().x / 2, map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2);
			}
			else
			{
				view.setCenter(view.getSize().x / 2, main->getPos().y);
			}
			
		}
		else if (main->getPos().x >= map->getTileMap()->GetWidth()*tam_tiles - view.getSize().x / 2)
		{
			if (main->getPos().y <= view.getSize().y / 2)
			{
				view.setCenter(map->getTileMap()->GetHeight()*tam_tiles - view.getSize().x / 2, view.getSize().y / 2);
			}
			else if (main->getPos().y >= map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2)
			{
				view.setCenter(map->getTileMap()->GetWidth()*tam_tiles - view.getSize().x / 2, map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2);
			}
			else
			{
				view.setCenter(map->getTileMap()->GetWidth()*tam_tiles - view.getSize().x / 2, main->getPos().y);
			}
		}
		else if (main->getPos().y <= view.getSize().y / 2)
		{
			view.setCenter(main->getPos().x, view.getSize().y / 2);
		}
		else if (main->getPos().y >= map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2)
		{
			view.setCenter(main->getPos().x, map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2);
		}
		else 
		{
			view.setCenter(main->getPos());
		}

		pause->setPosition(Juego::getAnchoPantalla() - pause->getSize().x*1.5f, pause->getSize().y / 2);
	}

	void Gameplay::draw(Juego* juego)
	{
		juego->getWindow()->setView(view);
		map->getTileMap()->ShowObjects(true);
		juego->getWindow()->draw(*map->getTileMap());
		juego->getWindow()->draw(main->getCol());
		juego->getWindow()->draw(enemy->getCol());
		main->draw();
	}

	void Gameplay::deInit()
	{
		pause->setVisible(false);
	}
}