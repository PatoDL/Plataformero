#ifndef COLISIONES_H
#define COLISIONES_H

#include "SFML\Graphics.hpp"

struct vecColisiones
{
	bool _izq;
	bool _der;
	bool _abajo;
	bool _arriba;
};

class Colisiones
{
private:
	vecColisiones posColision;
public:
	Colisiones();
	~Colisiones();
	vecColisiones getColision();
};

#endif