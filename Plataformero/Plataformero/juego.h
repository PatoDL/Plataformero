#ifndef JUEGO_H
#define JUEGO_H

#include "pantalla.h"

#include "SFML/Graphics.hpp"

using namespace sf;

namespace juego
{
	const int cantPantallas = 4;

	class Juego
	{
	private:
		bool _inGame;
		Pantalla* pantalla[cantPantallas];
		RenderWindow* window;
		enum Estados
		{
			menu,
			gameplay,
			creditos,
			gameover
		};
		static Clock _dClock;
		static float _dt;
	public:
		Juego();
		~Juego();
		RenderWindow* getWindow();
		void setInGame(bool inGame);
		bool getInGame();
		void ejecutar(Juego* juego);
		static float getFrameTime();
		void resetClock();
	};
}

#endif

