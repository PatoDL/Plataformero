#include "../Plataformero/juego.h"

using namespace juego;

void main()
{
	Juego* game = new Juego();

	game->ejecutar(game);

	delete game;
}