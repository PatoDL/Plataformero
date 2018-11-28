#include "colisiones.h"

#include <iostream>

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
			if (mapa->getPlataforma(i).getGlobalBounds().intersects(jug->getCol().getGlobalBounds()))
			{
				
				//ABAJO
				if (colisionaAbajo(jug, mapa, i) && !jugadorEnPlataformaY(jug, mapa, i)  && jugadorEnPlataformaX(jug,mapa,i))
				{
					jug->setY(mapa->getPlataforma(i).getPosition().y - mapa->getPlataforma(i).getSize().y / 2 - jug->getCol().getSize().y / 2);
					posColision._abajo = true;
					std::cout << "abajo" << std::endl;
				}
				//ARRIBA
				else if (colisionaArriba(jug, mapa, i) && !jugadorEnPlataformaY(jug, mapa, i) && jugadorEnPlataformaX(jug, mapa, i))
				{
					jug->setY(mapa->getPlataforma(i).getPosition().y + mapa->getPlataforma(i).getSize().y / 2 + jug->getCol().getSize().y / 2);
					posColision._arriba = true;
					std::cout << "ariba" << std::endl;
				}
				else
				{
					//IZQUIERDA
					if (colisionaIzq(jug, mapa, i))
					{
						jug->setX(mapa->getPlataforma(i).getPosition().x + mapa->getPlataforma(i).getSize().x / 2 + jug->getCol().getSize().x / 2);
						posColision._izq = true;
						std::cout << "izq" << std::endl;
					}
					//DERECHA
					else if (colisionaDer(jug, mapa, i))
					{
						jug->setX(mapa->getPlataforma(i).getPosition().x - mapa->getPlataforma(i).getSize().x / 2 - jug->getCol().getSize().x / 2);
						posColision._der = true;
						std::cout << "der" << std::endl;
					}


					
				}
				
			}
		}
	}

	bool Colisiones::colisionaAbajo(Jugador* jug, Mapa* mapa, int i)
	{
		return (jug->getPos().y + jug->getCol().getSize().y / 2 >= mapa->getPlataforma(i).getPosition().y - mapa->getPlataforma(i).getSize().y / 2 &&
			jug->getPos().y < mapa->getPlataforma(i).getPosition().y);
	}

	bool Colisiones::colisionaArriba(Jugador* jug, Mapa* mapa, int i)
	{
		return (jug->getPos().y - jug->getCol().getSize().y / 2 <= mapa->getPlataforma(i).getPosition().y + mapa->getPlataforma(i).getSize().y / 2 && 
			jug->getPos().y > mapa->getPlataforma(i).getPosition().y);
	}

	bool Colisiones::colisionaDer(Jugador* jug, Mapa* mapa, int i)
	{
		return (jug->getPos().x + jug->getCol().getSize().x / 2 >= mapa->getPlataforma(i).getPosition().x - mapa->getPlataforma(i).getSize().x / 2 &&
			jug->getPos().x < mapa->getPlataforma(i).getPosition().x);
	}

	bool Colisiones::colisionaIzq(Jugador* jug, Mapa* mapa, int i)
	{
		return (jug->getPos().x - jug->getCol().getSize().x / 2 <= mapa->getPlataforma(i).getPosition().x + mapa->getPlataforma(i).getSize().x / 2 &&
			jug->getPos().x > mapa->getPlataforma(i).getPosition().x);
	}

	bool Colisiones::jugadorEnPlataformaX(Jugador* jug, Mapa* mapa, int i)		//chequeo que la pos x del personaje no se puperponga con el alto de la plataforma
	{
		return (jug->getPos().x - jug->getCol().getSize().x/4< mapa->getPlataforma(i).getPosition().x + mapa->getPlataforma(i).getSize().x / 2 &&
			jug->getPos().x + jug->getCol().getSize().x / 4 > mapa->getPlataforma(i).getPosition().x - mapa->getPlataforma(i).getSize().x / 2);
	}

	bool Colisiones::jugadorEnPlataformaY(Jugador* jug, Mapa* mapa, int i)		//chequeo que la pos x del personaje no se puperponga con el ancho de la plataforma
	{
		return (jug->getPos().y - jug->getCol().getSize().y / 6 < mapa->getPlataforma(i).getPosition().y + mapa->getPlataforma(i).getSize().y / 2 &&
			jug->getPos().y + jug->getCol().getSize().y / 6 > mapa->getPlataforma(i).getPosition().y - mapa->getPlataforma(i).getSize().y / 2);
	}
}
