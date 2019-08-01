#include "gameplay.h"

#include "objetos/jugador.h"
#include "juego/juego.h"
#include "objetos/enemigo.h"
#include "objetos/mapa.h"

namespace juego
{
	const int tam_tiles = 32;

	bool Gameplay::ganador = false;
	int Gameplay::nivel = 1;

	Gameplay::Gameplay()
	{		
		jugador = new Jugador(0, 0, { 150.f,250.f });

		view.setSize(static_cast<float>(Juego::getAnchoPantalla() / 2.5f), static_cast<float>(Juego::getAnchoPantalla() / 2.5f));
		view.setCenter(jugador->getPos());

		botonPausa = tgui::Button::create();
		botonPausa->setSize(40, 40);
		botonPausa->setText("| |");
		botonPausa->setPosition(Juego::getAnchoPantalla() - botonPausa->getSize().x*1.5f, botonPausa->getSize().y / 2);
		botonPausa->setRenderer(Juego::getTheme().getRenderer("Button"));
		botonPausa->connect("pressed", [&]() {Juego::setEstadoActual(pausa, false); });
		Juego::getGui()->add(botonPausa);
		setGanador(false);
	}

	Gameplay::~Gameplay()
	{
		delete jugador;
		delete map;
		for (int i = 0; i < cantEnemigos; i++)
		{
			delete enemigo[i];
		}
	}

	void Gameplay::inicializar()
	{
		reiniciar();
	}

	void Gameplay::reiniciar()
	{
		if(jugador==NULL)
			jugador = new Jugador(0, 0, { 150.f,250.f });

		map = new Mapa(nivel);
		map->crearPlataformas();
		crearEnemigos(map);
		ganador = false;
		
		static_cast<Jugador*>(jugador)->setPosInicial(map->getPosInicial());
		jugador->inicializar();
		for (int i = 0; i < cantEnemigos; i++)
		{
			enemigo[i]->inicializar();
		}
	}

	void Gameplay::chequearInput()
	{
		jugador->mover();
		((Jugador*)jugador)->atacar();
	}

	void Gameplay::actualizar()
	{
		if (!ganador)
		{
			colisiones.procesarColisiones(static_cast<Jugador*>(jugador), map);
			for (int i = 0; i < cantEnemigos; i++)
			{
				if (static_cast<Enemigo*>(enemigo[i])->getEstaVivo())
				{
					colisiones.procesarColisionesPersonajes(static_cast<Jugador*>(jugador), static_cast<Enemigo*>(enemigo[i]));
				}
			}
			for (int i = 0; i < cantEnemigos; i++)
			{
				if (static_cast<Enemigo*>(enemigo[i])->getEstaVivo())
				{
					static_cast<Enemigo*>(enemigo[i])->chequearEnPlataforma(map, i);
					enemigo[i]->mover();
					enemigo[i]->actualizar();
				}

			}
			jugador->actualizar();
			posicionarCamara();
		}
		else
		{
			procesarLlegada();
		}
	}

	void Gameplay::dibujar()
	{
		Juego::getWindow()->setView(view);
		map->getTileMap()->ShowObjects(false);
		Juego::getWindow()->draw(*map->getTileMap());
		jugador->dibujar();
		for (int i = 0; i < cantEnemigos; i++)
		{
			if (static_cast<Enemigo*>(enemigo[i])->getEstaVivo())
			{
				enemigo[i]->dibujar();
			}
		}
	}

	void Gameplay::desinicializar()
	{
		delete map;
		for (int i = 0; i < cantEnemigos; i++)
		{
			delete enemigo[i];
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
				view.setCenter(map->getTileMap()->GetWidth()*tam_tiles - view.getSize().x / 2, view.getSize().y / 2);
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

	

	void Gameplay::crearEnemigos(Mapa* map)
	{
		for (int i = 0; i < cantEnemigos; i++)
		{
			float posX = map->getPlataforma(map->getPlatConEnemigo(i)).getPosition().x;
			float posY = map->getPlataforma(map->getPlatConEnemigo(i)).getPosition().y - map->getPlataforma(map->getPlatConEnemigo(i)).getSize().y / 2;

			enemigo[i] = new Enemigo(posX, posY, { -200.0f,200.0f });
		}
	}

	void Gameplay::esconderGui()
	{
		botonPausa->setVisible(false);
		view.setCenter({ static_cast<float>(Juego::getAnchoPantalla() / 2),static_cast<float>(Juego::getAltoPantalla() / 2) });
	}

	void Gameplay::mostrarGui()
	{
		botonPausa->setVisible(true);
	}

	bool Gameplay::getGanador()
	{
		return ganador;
	}

	void Gameplay::setGanador(bool g)
	{
		ganador = g;
	}

	void Gameplay::setNivel(int n)
	{
		nivel = n;
	}

	void Gameplay::procesarLlegada()
	{
		switch (nivel)
		{
		case 1:
			nivel++;
			desinicializar();
			inicializar();
			setGanador(false);
			break;
		case 2:
			desinicializar();
			nivel = 1;
			Juego::setEstadoActual(gameover, false);
			break;
		}
	}
}