#include "colisiones.h"



Colisiones::Colisiones()
{
	posColision = { false,false,false,false };
}


Colisiones::~Colisiones()
{
	
}

vecColisiones Colisiones::getColision()
{
	return posColision;
}
