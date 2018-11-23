#include "../Plataformero/juego.h"

void main()
{
	Juego::Juego* juego = new Juego::Juego();

	juego->ejecutar();

	delete juego;
}