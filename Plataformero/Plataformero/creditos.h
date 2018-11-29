#ifndef CREDITOS_H
#define CREDITOS_H

#include "pantalla.h"

namespace juego
{
	class Creditos :public Pantalla
	{
	public:
		Creditos();
		~Creditos();
		void inicializar();
		void chequearInput();
		void actualizar();
		void dibujar(Juego* juego);
		void desinicializar();
	};
}
#endif