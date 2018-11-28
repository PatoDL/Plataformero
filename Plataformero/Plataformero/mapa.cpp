#include "mapa.h"

#include <iostream>

namespace juego {
	Mapa::Mapa()
	{
		result = doc.load_file("res/assets/mapa.tmx"); // Locates the file to be used.
		objeto = doc.child("map").child("objectgroup");
		tMap = new TileMap("res/assets/mapa.tmx");
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
		for (xml_node_iterator i = objeto.begin(); i != objeto.end(),j<maxPlataformas; i++) {
			std::string tipo = i->attribute("type").as_string();
			plataformas[j].setSize(Vector2f(i->attribute("width").as_int(), i->attribute("height").as_int()));
			plataformas[j].setPosition(Vector2f(i->attribute("x").as_int()+plataformas[j].getSize().x/2, i->attribute("y").as_int() + plataformas[j].getSize().y / 2));
			plataformas[j].setOrigin(Vector2f(i->attribute("width").as_int() / 2.f, i->attribute("height").as_int() / 2.f));
			if (tipo == "piso")
				tipoPlat[j] = piso;
			else
				tipoPlat[j] = pinches;
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
}