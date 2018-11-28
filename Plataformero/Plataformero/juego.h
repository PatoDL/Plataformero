#ifndef JUEGO_H
#define JUEGO_H

#include "pantalla.h"

#include "SFML/Graphics.hpp"

using namespace sf;

namespace juego
{
	enum Estados
	{
		gameplay,
		menu,
		creditos,
		gameover
	};

	const int cantPantallas = 4;

	class Juego
	{
	private:
		static bool _inGame;
		Pantalla* pantalla[cantPantallas];
		static unsigned int _anchoPantalla;
		static unsigned int _altoPantalla;
		static RenderWindow* window;
		static Estados estadoActual;
		static Estados estadoAnterior;
		static Clock _dClock;
		static Time _dt;
	public:
		Juego();
		~Juego();
		static RenderWindow* getWindow();
		static void setInGame(bool inGame);
		static bool getInGame();
		void ejecutar(Juego* juego);
		static float getFrameTime();
		void resetClock();
		static int getAnchoPantalla();
		static int getAltoPantalla();
		static void setAnchoPantalla(unsigned int ancho);
		static void setAltoPantalla(unsigned int alto);
		static Estados getEstadoActual();
		static void setEstadoActual(Estados e);
	};
}

#endif

