#ifndef PANTALLA_H
#define PANTALLA_H

namespace Juego
{
	class Pantalla
	{
	public:
		Pantalla();
		~Pantalla();
		virtual void checkInput() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
	};
}
#endif