#include "colisiones.h"

#include "juego.h"

namespace juego {
	Colisiones::Colisiones()
	{
		
	}


	Colisiones::~Colisiones()
	{

	}

	void Colisiones::procesarJugadorPlataformas(Jugador* jug, Mapa* mapa)
	{
		jug->setPosColision({ false,false,false,false });

		static float difColisionX = jug->getCol().getGlobalBounds().width*0.01f;
		static float difColisionY = jug->getCol().getGlobalBounds().height*0.01f;

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
						jug->setY(plataforma.getGlobalBounds().top - jug->getCol().getSize().y / 2 + difColisionY);//(plataforma.getPosition().y - plataforma.getSize().y / 2 - jug->getCol().getSize().y / 2);
						jug->setPosColisionPiso(true);
						jug->setEnSalto(true);
					}
					//ARRIBA
					else if (colisionaArriba(jug, plataforma) && !jugadorEnPlataformaY(jug, plataforma) && jugadorEnPlataformaX(jug, plataforma))
					{
						jug->setY(plataforma.getPosition().y + plataforma.getSize().y / 2 + jug->getCol().getSize().y / 2 - difColisionY);
						jug->setPosColisionTecho(true);
					}
					else
					{
						//IZQUIERDA
						if (colisionaIzq(jug, plataforma) && !jugadorEnPlataformaX(jug, plataforma))
						{
							jug->setX(plataforma.getPosition().x + plataforma.getSize().x / 2 + jug->getCol().getSize().x / 2 - difColisionX);
							jug->setPosColisionIzq(true);
						}
						//DERECHA
						else if (colisionaDer(jug, plataforma) && !jugadorEnPlataformaX(jug, plataforma))
						{
							jug->setX(plataforma.getPosition().x - plataforma.getSize().x / 2 - jug->getCol().getSize().x / 2 + difColisionX);
							jug->setPosColisionDer(true);
						}
					}
				}
				else
				{
					Juego::setInGame(false);
				}
				
			}
			//else
			//{
			//	if (jug->getColision()._abajo)
			//	{
			//		jug->setPosColisionPiso(false);
			//	}
			//	if (jug->getColision()._arriba)
			//	{
			//		jug->setPosColisionTecho(false);
			//	}
			//	if (jug->getColision()._izq)
			//	{
			//		jug->setPosColisionIzq(false);
			//	}
			//	if (jug->getColision()._der)
			//	{
			//		jug->setPosColisionDer(false);
			//	}
			//}
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
}
