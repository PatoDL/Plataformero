#include "mapa.h"

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
}