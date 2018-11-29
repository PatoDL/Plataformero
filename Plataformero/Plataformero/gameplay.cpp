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
		jugador = new Jugador(90, 2000, { 150.f,250.f });
		enemigo = new Enemigo(90, 1800, { 100.f,10.f });
		map = new Mapa;
		view.setSize(static_cast<float>(Juego::getAnchoPantalla()/2.5f), static_cast<float>(Juego::getAnchoPantalla()/2.5f));
		view.setCenter(jugador->getPos());
		map->crearPlataformas();
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
		enemigo->inicializar();
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
		enemigo->mover();
		jugador->actualizar();
		posicionarCamara();
		enemigo->actualizar();
	}

	void Gameplay::dibujar(Juego* juego)
	{
		juego->getWindow()->setView(view);
		map->getTileMap()->ShowObjects(false);
		juego->getWindow()->draw(*map->getTileMap());
		//juego->getWindow()->dibujar(jugador->getCol());
		//juego->getWindow()->dibujar(enemigo->getCol());
		jugador->dibujar();
		enemigo->dibujar();
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
}