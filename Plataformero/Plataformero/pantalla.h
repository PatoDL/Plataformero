#ifndef PANTALLA_H
#define PANTALLA_H

namespace juego
{
	class Juego;

	class Pantalla
	{
	public:
		Pantalla();
		~Pantalla();
		virtual void checkInput() = 0;
		virtual void update() = 0;
		virtual void draw(Juego* juego) = 0;
	};
}
#endif