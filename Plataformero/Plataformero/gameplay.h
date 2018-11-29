#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantalla.h"
#include "personaje.h"
#include "juego.h"

#include "mapa.h"
#include "colisiones.h"

#include "TGUI/TGUI.hpp"


namespace juego
{
	class Gameplay : public Pantalla
	{
		Personaje* jugador;
		Personaje* enemigo[cantEnemigos];
		View view;
		Mapa* map;
		tgui::Button::Ptr botonPausa;
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
		void crearEnemigos(Mapa* map);
	};
}
#endif