#include "../Plataformero/juego.h"
#include "TGUI/TGUI.hpp"

using namespace juego;

int main()
{
	Juego* j = new Juego();

	j->ejecutar(j);

	delete j;

	return 0;
}
