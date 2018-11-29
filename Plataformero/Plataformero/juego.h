#ifndef JUEGO_H
#define JUEGO_H

#include "pantalla.h"

#include "SFML/Graphics.hpp"

#include "TGUI/Gui.hpp"

using namespace sf;

namespace juego
{
	enum Estados
	{
		gameplay,
		menu,
		creditos,
		gameover,
		opciones,
		pausa
	};

	const int cantPantallas = 6;

	class Juego
	{
	private:
		static bool _inGame;
		static Pantalla* pantalla[cantPantallas];
		static unsigned int _anchoPantalla;
		static unsigned int _altoPantalla;
		static RenderWindow* window;
		static Estados estadoActual;
		static Estados estadoAnterior;
		static Clock _dClock;
		static Time _dt;
		static tgui::Gui* gui;
		static tgui::Theme theme;
		static sf::Font _fuente;
		static sf::Text version;
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
		static void setEstadoActual(Estados e, bool reinicio);
		static tgui::Gui* getGui();
		static tgui::Theme getTheme();
		static sf::Font getFuente();
		static void dibujarVersion();
	};
}

#endif

