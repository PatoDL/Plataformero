#ifndef MAPA_H
#define MAPA_H

#include "pugixml.hpp"
#include "STP/TMXLoader.hpp"
#include "SFML/Graphics.hpp"

using namespace pugi;
using namespace tmx;
using namespace sf;

const int maxPlataformas = 300;

namespace juego {
	enum tiposPlataforma{piso,pinches, llegada};

	class Mapa
	{
	private:
		xml_document doc;
		xml_parse_result result; // Locates the file to be used.
		xml_node objeto;
		TileMap* tMap;
		RectangleShape plataformas[maxPlataformas];
		tiposPlataforma tipoPlat[maxPlataformas];
		bool tieneEnemigo[maxPlataformas];
		int platConEnemigo[5];
		Vector2f posInicial;
	public:
		Mapa(int nivel);
		~Mapa();
		TileMap* getTileMap();
		void crearPlataformas();
		RectangleShape getPlataforma(int i);
		Mapa &getMapa();
		tiposPlataforma getTipoPlataforma(int i);
		int getPlatConEnemigo(int i);
		Vector2f getPosInicial();
	};
}
#endif