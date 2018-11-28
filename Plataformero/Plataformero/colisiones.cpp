#include "colisiones.h"

#include "juego.h"

namespace juego {
	Colisiones::Colisiones()
	{
		posColision = { false,false,false,false };
	}


	Colisiones::~Colisiones()
	{

	}

	vecColisiones Colisiones::getColision()
	{
		return posColision;
	}

	void Colisiones::procesarJugadorPlataformas(Jugador* jug, Mapa* mapa)
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
						jug->setY(plataforma.getPosition().y - plataforma.getSize().y / 2 - jug->getCol().getSize().y / 2);
						posColision._abajo = true;
					}
					//ARRIBA
					else if (colisionaArriba(jug, plataforma) && !jugadorEnPlataformaY(jug, plataforma) && jugadorEnPlataformaX(jug, plataforma))
					{
						jug->setY(plataforma.getPosition().y + plataforma.getSize().y / 2 + jug->getCol().getSize().y / 2);
						posColision._arriba = true;
					}
					else
					{
						//IZQUIERDA
						if (colisionaIzq(jug, plataforma))
						{
							jug->setX(plataforma.getPosition().x + plataforma.getSize().x / 2 + jug->getCol().getSize().x / 2);
							posColision._izq = true;
						}
						//DERECHA
						else if (colisionaDer(jug, plataforma))
						{
							jug->setX(plataforma.getPosition().x - plataforma.getSize().x / 2 - jug->getCol().getSize().x / 2);
							posColision._der = true;
						}
					}
				}
				else
				{
					Juego::setInGame(false);
				}
				
			}
		}
	}

	bool Colisiones::colisionaAbajo(Jugador* jug, RectangleShape plataforma)
	{
		return (jug->getPos().y + jug->getCol().getSize().y / 2 >= plataforma.getPosition().y - plataforma.getSize().y / 2 &&
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
		return (jug->getPos().x - jug->getCol().getSize().x/4< plataforma.getPosition().x + plataforma.getSize().x / 2 &&
			jug->getPos().x + jug->getCol().getSize().x / 4 > plataforma.getPosition().x - plataforma.getSize().x / 2);
	}

	bool Colisiones::jugadorEnPlataformaY(Jugador* jug, RectangleShape plataforma)		//chequeo que la pos x del personaje no se puperponga con el ancho de la plataforma
	{
		return (jug->getPos().y - jug->getCol().getSize().y / 6 < plataforma.getPosition().y + plataforma.getSize().y / 2 &&
			jug->getPos().y + jug->getCol().getSize().y / 6 > plataforma.getPosition().y - plataforma.getSize().y / 2);
	}
}
