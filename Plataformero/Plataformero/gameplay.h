#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantalla.h"
#include "personaje.h"
#include "juego.h"
#include "mapa.h"
#include "colisiones.h"
#include "TGUI/TGUI.hpp"

using namespace tgui;


namespace juego
{
	class Gameplay : public Pantalla
	{
		Personaje* jugador;
		Personaje* enemigo;
		View view;
		Mapa* map;
		Button::Ptr botonPausa;
		Colisiones colisiones;
	public:
		Gameplay();
		~Gameplay();
		void inicializar();
		void chequearInput();
		void actualizar();
		void dibujar(Juego* juego);
		void desinicializar();
		void posicionarCamara();
	};
}
#endif