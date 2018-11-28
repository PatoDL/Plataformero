#ifndef MAPA_H
#define MAPA_H

#include "pugixml.hpp"
#include "STP/TMXLoader.hpp"
#include "SFML/Graphics.hpp"

using namespace pugi;
using namespace tmx;
using namespace sf;

const int maxPlataformas=105;

namespace juego {
	enum tiposPlataforma{piso,pinches};

	class Mapa
	{
	private:
		xml_document doc;
		xml_parse_result result; // Locates the file to be used.
		xml_node objeto;
		TileMap* tMap;
		RectangleShape plataformas[maxPlataformas];
		tiposPlataforma tipoPlat[maxPlataformas];
	public:
		Mapa();
		~Mapa();
		TileMap* getTileMap();
		void crearPlataformas();
		RectangleShape getPlataforma(int i);
		Mapa &getMapa();
		tiposPlataforma getTipoPlataforma(int i);
	};
}
#endif