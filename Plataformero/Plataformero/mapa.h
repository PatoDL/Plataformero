#ifndef MAPA_H
#define MAPA_H

#include "pugixml.hpp"
#include "STP/TMXLoader.hpp"

using namespace pugi;
using namespace tmx;

namespace juego {
	class Mapa
	{
	private:
		xml_document doc;
		xml_parse_result result; // Locates the file to be used.
		xml_node objeto;
		TileMap* tMap;
	public:
		Mapa();
		~Mapa();
		TileMap* getTileMap();
	};
}
#endif