#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "pantalla.h"

#include "TGUI/TGUI.hpp"

namespace juego
{
	const int cantBotonesMenu = 2;

	enum EstadosGO
	{
		ganaste,
		perdiste
	};

	enum BotonesGO
	{
		jugarGO,
		menuGO
	};

	class Gameover:public Pantalla
	{
		tgui::Button::Ptr botonGO[cantBotonesMenu];
	public:
		Gameover();
		~Gameover();
		void inicializar();
		void chequearInput();
		void actualizar();
		void dibujar(Juego* juego);
		void desinicializar();
	};
}
#endif