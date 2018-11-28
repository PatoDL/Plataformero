#include "mapa.h"

//const int maxPlataformas = 104;

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
			plataformas[j].setSize(Vector2f(i->attribute("width").as_int(), i->attribute("height").as_int()));
			plataformas[j].setPosition(Vector2f(i->attribute("x").as_int()+plataformas[j].getSize().x/2, i->attribute("y").as_int() + plataformas[j].getSize().y / 2));
			plataformas[j].setOrigin(Vector2f(i->attribute("width").as_int() / 2.f, i->attribute("height").as_int() / 2.f));
			//cout << i->attribute("id").as_int() << endl;
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
}