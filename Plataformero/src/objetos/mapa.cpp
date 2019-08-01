#include "mapa.h"

namespace juego {
	Mapa::Mapa()
	{
		result = doc.load_file("res/assets/mapa2.tmx"); // Locates the file to be used.
		objeto = doc.child("map").child("objectgroup");
		tMap = new TileMap("res/assets/mapa2.tmx");
	}


	Mapa::~Mapa()
	{

	}

	TileMap* Mapa::getTileMap()
	{
		return tMap;
	}

	void Mapa::crearPlataformas() 
	{
		int j = 0;
		for (xml_node_iterator i = objeto.begin(); i != objeto.end()/*, j < maxPlataformas*/; i++) {
			static int h = 0;
			std::string tipo = i->attribute("type").as_string();
			plataformas[j].setSize(sf::Vector2f(static_cast<float>(i->attribute("width").as_int()), static_cast<float>( i->attribute("height").as_int())));
			plataformas[j].setPosition(sf::Vector2f(i->attribute("x").as_int() + plataformas[j].getSize().x / 2, i->attribute("y").as_int() + plataformas[j].getSize().y / 2));
			plataformas[j].setOrigin(sf::Vector2f(i->attribute("width").as_int() / 2.f, i->attribute("height").as_int() / 2.f));
			if (tipo == "piso")
				tipoPlat[j] = piso;
			else if (tipo == "pinches")
				tipoPlat[j] = pinches;
			else if (tipo == "inicio")
				posInicial = plataformas[j].getPosition();
			else
				tipoPlat[j] = llegada;
			if (i->child("properties").child("property").attribute("value").as_bool())
			{
				tieneEnemigo[j] = true;
				platConEnemigo[h] = j;
				h++;
			}
			else
			{
				tieneEnemigo[j] = false;
			}
				
			j++;
		}
		j = 0;
	}

	RectangleShape Mapa::getPlataforma(int i)
	{
		return plataformas[i];
	}

	Mapa &Mapa::getMapa()
	{
		return *this;
	}

	tiposPlataforma Mapa::getTipoPlataforma(int i)
	{
		return tipoPlat[i];
	}

	int Mapa::getPlatConEnemigo(int i)
	{
		return platConEnemigo[i];
	}

	Vector2f Mapa::getPosInicial()
	{
		return posInicial;
	}
}