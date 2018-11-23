#include "enemigo.h"

namespace juego
{
	Enemigo::Enemigo(float x, float y):Personaje(x,y)
	{
		setCol(getCol().getPosition(), getCol().getSize(), Color::Red);
	}


	Enemigo::~Enemigo()
	{
	}

	void Enemigo::mover()
	{
		setX(getPos().x - 0.03f);
	}
}