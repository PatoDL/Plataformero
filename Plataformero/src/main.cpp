#include "../Plataformero/juego.h"
#include "TGUI/TGUI.hpp"

using namespace juego;

void main()
{
	Juego* game = new Juego();

	game->ejecutar(game);

	delete game;
}
