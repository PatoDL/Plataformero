#ifndef JUEGO_H
#define JUEGO_H

#include "pantalla.h"

namespace Juego
{
	const int cantPantallas = 4;

	class Juego
	{
	private:
		bool _inGame;
		Pantalla* pantalla[cantPantallas];
		enum Estados
		{
			menu,
			gameplay,
			creditos,
			gameover
		};
	public:
		Juego();
		~Juego();
		void setInGame(bool inGame);
		bool getInGame();
		void ejecutar();
	};
}

#endif

