#include "gameplay.h"

#include "jugador.h"
#include "juego.h"
#include "enemigo.h"
#include "mapa.h"

//using namespace tgui;

namespace juego
{
	const int tam_tiles = 32;

	Gameplay::Gameplay()
	{
		jugador = new Jugador(90, 2000, { 150.f,250.f });
		//enemigo = new Enemigo(90, 1800, { 100.f,10.f });
		map = new Mapa;
		map->crearPlataformas();
		crearEnemigos(map);
		view.setSize(static_cast<float>(Juego::getAnchoPantalla()/2.5f), static_cast<float>(Juego::getAnchoPantalla()/2.5f));
		view.setCenter(jugador->getPos());
		
		
	}

	Gameplay::~Gameplay()
	{
		delete jugador;
		delete map;
		delete enemigo;
	}

	void Gameplay::inicializar()
	{
		/*jugador = new Jugador(10, 10, { 100.f,100.f });
		enemigo = new Enemigo(500, 500, { 500.f,500.f });
		map = new Mapa;*/
		view.setSize(static_cast<float>(Juego::getAnchoPantalla() / 2.5f), static_cast<float>(Juego::getAnchoPantalla() / 2.5f));
		view.setCenter(jugador->getPos());
		jugador->inicializar();
		for (int i = 0; i < cantEnemigos; i++)
		{
			enemigo[i]->inicializar();
		}
		botonPausa = tgui::Button::create();
		botonPausa->setSize(40, 40);
		botonPausa->setText("P");
		botonPausa->setPosition(Juego::getAnchoPantalla() - botonPausa->getSize().x*1.5f, botonPausa->getSize().y / 2);
		botonPausa->setRenderer(Juego::getTheme().getRenderer("Button"));
		botonPausa->connect("pressed", [&]() {Juego::setEstadoActual(pausa, false); });
		Juego::getGui()->add(botonPausa);
	}

	void Gameplay::chequearInput()
	{
		jugador->mover();
		((Jugador*)jugador)->atacar();
	}

	void Gameplay::actualizar()
	{
		colisiones.procesarColisiones(static_cast<Jugador*>(jugador), map);
		for (int i = 0; i < cantEnemigos; i++)
		{
			static_cast<Enemigo*>(enemigo[i])->chequearEnPlataforma(map,i);
			enemigo[i]->mover();
			enemigo[i]->actualizar();
		}
		jugador->actualizar();
		posicionarCamara();
		
	}

	void Gameplay::dibujar(Juego* juego)
	{
		juego->getWindow()->setView(view);
		map->getTileMap()->ShowObjects(false);
		juego->getWindow()->draw(*map->getTileMap());
		//juego->getWindow()->dibujar(jugador->getCol());
		//juego->getWindow()->dibujar(enemigo->getCol());
		jugador->dibujar();
		for (int i = 0; i < cantEnemigos; i++)
		{
			enemigo[i]->dibujar();
		}
	}

	void Gameplay::posicionarCamara()
	{
		if (jugador->getPos().x <= view.getSize().x / 2)
		{
			if (jugador->getPos().y <= view.getSize().y / 2)
			{
				view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
			}
			else if (jugador->getPos().y >= map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2)
			{
				view.setCenter(view.getSize().x / 2, map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2);
			}
			else
			{
				view.setCenter(view.getSize().x / 2, jugador->getPos().y);
			}

		}
		else if (jugador->getPos().x >= map->getTileMap()->GetWidth()*tam_tiles - view.getSize().x / 2)
		{
			if (jugador->getPos().y <= view.getSize().y / 2)
			{
				view.setCenter(map->getTileMap()->GetHeight()*tam_tiles - view.getSize().x / 2, view.getSize().y / 2);
			}
			else if (jugador->getPos().y >= map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2)
			{
				view.setCenter(map->getTileMap()->GetWidth()*tam_tiles - view.getSize().x / 2, map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2);
			}
			else
			{
				view.setCenter(map->getTileMap()->GetWidth()*tam_tiles - view.getSize().x / 2, jugador->getPos().y);
			}
		}
		else if (jugador->getPos().y <= view.getSize().y / 2)
		{
			view.setCenter(jugador->getPos().x, view.getSize().y / 2);
		}
		else if (jugador->getPos().y >= map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2)
		{
			view.setCenter(jugador->getPos().x, map->getTileMap()->GetHeight()*tam_tiles - view.getSize().y / 2);
		}
		else
		{
			view.setCenter(jugador->getPos());
		}

		botonPausa->setPosition(Juego::getAnchoPantalla() - botonPausa->getSize().x*1.5f, botonPausa->getSize().y / 2);
	}

	void Gameplay::desinicializar()
	{
		botonPausa->setVisible(false);
	}

	void Gameplay::crearEnemigos(Mapa* map)
	{
		for (int i = 0; i < cantEnemigos; i++)
		{
			float posX= map->getPlataforma(map->getPlatConEnemigo(i)).getPosition().x;
			float posY = map->getPlataforma(map->getPlatConEnemigo(i)).getPosition().y - map->getPlataforma(map->getPlatConEnemigo(i)).getSize().y / 2;

			enemigo[i] = new Enemigo(posX, posY, { -200.0f,200.0f });
		}
	}
}