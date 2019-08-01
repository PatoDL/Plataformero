#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantallas/pantalla.h"
#include "objetos/personaje.h"
#include "juego/juego.h"

#include "objetos/mapa.h"
#include "objetos/colisiones.h"

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
		static bool ganador;
		int nivel;
	public:
		Gameplay();
		~Gameplay();
		void inicializar();
		void reiniciar();
		void chequearInput();
		void actualizar();
		void dibujar();
		void desinicializar();
		void posicionarCamara();
		void crearEnemigos(Mapa* map);
		void esconderGui();
		void mostrarGui();
		static bool getGanador();
		static void setGanador(bool g);
		void procesarLlegada();
	};
}
#endif