#include "colisiones.h"

#include <iostream>
#include "juego.h"

namespace juego {

	Colisiones::Colisiones()
	{
		
	}


	Colisiones::~Colisiones()
	{

	}

	void Colisiones::procesarJugadorPlataformas(Jugador* jug, Mapa* mapa, float difColisionX, float difColisionY)
	{
		for (int i = 0; i < maxPlataformas; i++)
		{
			RectangleShape plataforma = mapa->getPlataforma(i);

			if (plataforma.getGlobalBounds().intersects(jug->getCol().getGlobalBounds()))
			{
				if (mapa->getTipoPlataforma(i) == piso) 
				{
					//ABAJO
					if (colisionaAbajo(jug, plataforma) && !jugadorEnPlataformaY(jug, plataforma) && jugadorEnPlataformaX(jug, plataforma))
					{
						jug->setY(plataforma.getGlobalBounds().top - jug->getCol().getSize().y / 2 + difColisionY);
						jug->setPosColisionPiso(true);
						jug->setEnSalto(false);
						jug->setVelCaida(0.0f);
					}
					//ARRIBA
					else if (colisionaArriba(jug, plataforma) && !jugadorEnPlataformaY(jug, plataforma) && jugadorEnPlataformaX(jug, plataforma))
					{
						jug->setY(plataforma.getGlobalBounds().top + plataforma.getGlobalBounds().height + jug->getCol().getSize().y / 2 - difColisionY);
						jug->setPosColisionTecho(true);
						jug->setVelSalto(-50.0f);
					}
					else
					{
						//IZQUIERDA
						if (colisionaIzq(jug, plataforma) && !jugadorEnPlataformaX(jug, plataforma))
						{
							jug->setX(plataforma.getGlobalBounds().left + plataforma.getGlobalBounds().width + jug->getCol().getSize().x / 2 - difColisionX);
							jug->setPosColisionIzq(true);
						}
						//DERECHA
						else if (colisionaDer(jug, plataforma) && !jugadorEnPlataformaX(jug, plataforma))
						{
							jug->setX(plataforma.getGlobalBounds().left - jug->getCol().getSize().x / 2 + difColisionX);
							jug->setPosColisionDer(true);
						}
					}
				}
				else
				{
					Juego::setEstadoActual(gameover, false);
				}
				
			}
		}
	}

	bool Colisiones::colisionaAbajo(Jugador* jug, RectangleShape plataforma)
	{
		return (jug->getPos().y + jug->getCol().getSize().y / 2 >= plataforma.getGlobalBounds().top &&
			jug->getPos().y < plataforma.getPosition().y);
	}

	bool Colisiones::colisionaArriba(Jugador* jug, RectangleShape plataforma)
	{
		return (jug->getPos().y - jug->getCol().getSize().y / 2 <= plataforma.getPosition().y + plataforma.getSize().y / 2 &&
			jug->getPos().y > plataforma.getPosition().y);
	}

	bool Colisiones::colisionaDer(Jugador* jug, RectangleShape plataforma)
	{
		return (jug->getPos().x + jug->getCol().getSize().x / 2 >= plataforma.getPosition().x - plataforma.getSize().x / 2 &&
			jug->getPos().x < plataforma.getPosition().x);
	}

	bool Colisiones::colisionaIzq(Jugador* jug, RectangleShape plataforma)
	{
		return (jug->getPos().x - jug->getCol().getSize().x / 2 <= plataforma.getPosition().x + plataforma.getSize().x / 2 &&
			jug->getPos().x > plataforma.getPosition().x);
	}

	bool Colisiones::jugadorEnPlataformaX(Jugador* jug, RectangleShape plataforma)		//chequeo que la pos x del personaje no se puperponga con el alto de la plataforma
	{
		return (jug->getPos().x - jug->getCol().getSize().x/8< plataforma.getPosition().x + plataforma.getSize().x / 2 &&
			jug->getPos().x + jug->getCol().getSize().x / 8 > plataforma.getPosition().x - plataforma.getSize().x / 2);
	}

	bool Colisiones::jugadorEnPlataformaY(Jugador* jug, RectangleShape plataforma)		//chequeo que la pos x del personaje no se puperponga con el ancho de la plataforma
	{
		return (jug->getPos().y - jug->getCol().getSize().y / 6 < plataforma.getPosition().y + plataforma.getSize().y / 2 &&
			jug->getPos().y + jug->getCol().getSize().y / 6 > plataforma.getPosition().y - plataforma.getSize().y / 2);
	}

	void Colisiones::procesarJugadorLimites(Jugador* jug, Mapa* mapa, float difColisionX, float difColisionY)
	{
		if (jug->getPos().x - jug->getCol().getSize().x / 2 <= 0)
		{
			jug->setX(0.0f + jug->getCol().getSize().x / 2 - difColisionX);
			jug->setPosColisionIzq(true);
		}
		
		if (jug->getPos().x+jug->getCol().getSize().x/2>=mapa->getTileMap()->GetWidth()*mapa->getTileMap()->GetTileWidth())
		{
			jug->setX(mapa->getTileMap()->GetWidth() * mapa->getTileMap()->GetTileWidth() - jug->getCol().getSize().x / 2 + difColisionX);
			jug->setPosColisionDer(true);
		}

		if (jug->getPos().y > mapa->getTileMap()->GetHeight()*mapa->getTileMap()->GetTileHeight() * 0.95f)
		{
			Juego::setEstadoActual(gameover, false);
		}
	}

	void Colisiones::procesarColisiones(Jugador* jug, Mapa* mapa)
	{
		static float difColisionX = jug->getCol().getGlobalBounds().width*0.009f;
		static float difColisionY = jug->getCol().getGlobalBounds().height*0.009f;

		jug->setPosColision({ false,false,false,false });

		procesarJugadorPlataformas(jug, mapa, difColisionX, difColisionY);
		procesarJugadorLimites(jug, mapa, difColisionX, difColisionY);

	}
}
