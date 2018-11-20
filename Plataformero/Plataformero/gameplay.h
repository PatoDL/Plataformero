#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantalla.h"

namespace Juego
{
	class Gameplay : public Pantalla
	{
	public:
		Gameplay();
		~Gameplay();
		void checkInput();
		void update();
		void draw();
	};
}
#endif