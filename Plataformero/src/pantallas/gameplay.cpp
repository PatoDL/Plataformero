#include "gameplay.h"

#include "objetos/jugador.h"
#include "juego/juego.h"
#include "objetos/enemigo.h"
#include "objetos/mapa.h"
#include "objetos/vidaExtra.h"
#include "objetos/dobleSalto.h"

namespace juego
{
	const int tam_tiles = 32;

	bool Gameplay::ganador = false;
	int Gameplay::nivel = 1;

	Texture vidasUITex;

	Sprite vidasUI;
	Text vidas;

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
		for (int i = 0; i < cantEscarabajos; i++)
		{
			if(escarabajos[i] != NULL)
				delete escarabajos[i];
		}
		for (int i = 0; i < cantMariposas; i++)
		{
			if (escarabajos[i] != NULL)
				delete mariposas[i];
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

		vidasUITex.loadFromFile("res/assets/1up.png");

		vidasUI.setTexture(vidasUITex);

		vidasUI.setOrigin(vidasUI.getTextureRect().width/2, vidasUI.getTextureRect().height / 2);

		vidas.setFont(*Juego::getGui()->getFont());
		vidas.setFillColor(Color::Red);
		vidas.setOrigin(vidas.getLocalBounds().width / 2, vidas.getLocalBounds().height / 2);

		map = new Mapa(nivel);
		map->crearPlataformas();
		crearEnemigos(map);
		crearItems(map);
		ganador = false;
		
		static_cast<Jugador*>(jugador)->setPosInicial(map->getPosInicial());
		jugador->inicializar();
		for (int i = 0; i < cantEscarabajos; i++)
		{
			escarabajos[i]->inicializar();
		}
		for (int i = 0; i < cantMariposas; i++)
		{
			mariposas[i]->inicializar();
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
			for (int i = 0; i < cantEscarabajos; i++)
			{
				if (static_cast<Escarabajo*>(escarabajos[i])->getEstaVivo())
				{
					colisiones.procesarColisionesPersonajes(static_cast<Jugador*>(jugador), static_cast<Escarabajo*>(escarabajos[i]));
				}
			}
			for (int i = 0; i < cantEscarabajos; i++)
			{
				if (static_cast<Escarabajo*>(escarabajos[i])->getEstaVivo())
				{
					static_cast<Escarabajo*>(escarabajos[i])->chequearEnPlataforma(map, i);
					escarabajos[i]->mover();
					escarabajos[i]->actualizar();
				}

			}
			for (int i = 0; i < cantMariposas; i++)
			{
				if (static_cast<Mariposa*>(mariposas[i])->getEstaVivo())
				{
					colisiones.procesarColisionesPersonajes(static_cast<Jugador*>(jugador), static_cast<Mariposa*>(mariposas[i]));
				}
			}
			for (int i = 0; i < cantMariposas; i++)
			{
				if (static_cast<Mariposa*>(mariposas[i])->getEstaVivo())
				{
					static_cast<Mariposa*>(mariposas[i])->chequearEnLimitesMapa(map, i);
					mariposas[i]->mover();
					mariposas[i]->actualizar();
				}
			}

			colisiones.procesarColisionesConItems(static_cast<Jugador*>(jugador), vidaExtra, dobleSalto);

			jugador->actualizar();
			posicionarCamara();
			vidasUI.setPosition(view.getCenter().x-200.0f,view.getCenter().y - 200.0f);
			
			vidas.setString("x" + std::to_string(jugador->getVidas()));
			vidas.setCharacterSize(20);
			vidas.setPosition(vidasUI.getPosition().x + 10.0f, vidasUI.getPosition().y);
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
		for (int i = 0; i < cantEscarabajos; i++)
		{
			if (static_cast<Escarabajo*>(escarabajos[i])->getEstaVivo())
			{
				escarabajos[i]->dibujar();
			}
		}
		for (int i = 0; i < cantMariposas; i++)
		{
			if (static_cast<Mariposa*>(mariposas[i])->getEstaVivo())
			{
				mariposas[i]->dibujar();
			}
		}
		vidaExtra->dibujar();
		dobleSalto->dibujar();
		Juego::getWindow()->draw(vidasUI);
		Juego::getWindow()->draw(vidas);
	}

	void Gameplay::desinicializar()
	{
		delete map;
		for (int i = 0; i < cantEscarabajos; i++)
		{
			if (escarabajos[i] != NULL)
				delete escarabajos[i];
		}
		for (int i = 0; i < cantMariposas; i++)
		{
			if (escarabajos[i] != NULL)
				delete mariposas[i];
		}
		delete dobleSalto;
		delete vidaExtra;
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
		for (int i = 0; i < cantEscarabajos; i++)
		{
			float posX = map->getPlataforma(map->getPlatConEnemigo(i)).getPosition().x;
			float posY = map->getPlataforma(map->getPlatConEnemigo(i)).getPosition().y - map->getPlataforma(map->getPlatConEnemigo(i)).getSize().y / 2;

			escarabajos[i] = new Escarabajo(posX, posY, { -200.0f,200.0f });
		}
		for (int i = 0; i < cantMariposas; i++)
		{
			float posX = map->getTileMap()->GetWidth() * map->getTileMap()->GetTileWidth() / 4 * i + 1;
			float posY = map->getTileMap()->GetHeight() * map->getTileMap()->GetTileHeight() / 2;
			mariposas[i] = new Mariposa(posX, posY, { -200.0f,200.0f });
		}
	}

	void Gameplay::crearItems(Mapa* map)
	{
		float posX = map->getPlataforma(map->getPlatConVidaExtra()).getPosition().x;
		float posY = map->getPlataforma(map->getPlatConVidaExtra()).getPosition().y - map->getPlataforma(map->getPlatConVidaExtra()).getSize().y / 2;

		vidaExtra = new VidaExtra();
		vidaExtra->inicializar({ posX, posY });

		posX = map->getPlataforma(map->getPlatConDobleSalto()).getPosition().x;
		posY = map->getPlataforma(map->getPlatConDobleSalto()).getPosition().y - map->getPlataforma(map->getPlatConDobleSalto()).getSize().y / 2;

		dobleSalto = new DobleSalto();
		dobleSalto->inicializar({ posX, posY });
	}

	void Gameplay::esconderGui()
	{
		botonPausa->setVisible(false);
		view.setCenter({ static_cast<float>(Juego::getAnchoPantalla() / 2), static_cast<float>(Juego::getAltoPantalla() / 2) });
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