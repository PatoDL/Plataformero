#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

namespace juego
{
	class Enemigo : public Personaje
	{
	public:
		Enemigo(float x, float y,Vector2f v);
		~Enemigo();
		void mover();
		void draw();
	};
}
#endif