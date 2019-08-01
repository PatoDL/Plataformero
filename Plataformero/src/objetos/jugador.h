#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	struct vecColisiones
	{
		bool _izq;
		bool _der;
		bool _abajo;
		bool _arriba;
	};

	const int cantSprDash = 6;

	class Jugador : public Personaje
	{
	private:
		vecColisiones posColision;
		bool enSalto;
		float velSalto;
		bool haceDash;
		float timerDash;
		float multiplicadorDash;
		bool miraIzq;
		bool miraDer;
		float timerEntreDash;
		float timerPosiciones;
		sf::Sprite sprDash[cantSprDash];	//guarda el sprite y su poosicion para dibujar el dash
		bool sprActivo[cantSprDash];
		Vector2f posInicial;
	public:
		Jugador(float x, float y, sf::Vector2f v);
		~Jugador();
		void inicializar();
		void mover();
		void actualizar();
		void dibujar();
		Jugador getJug();
		vecColisiones getColision();
		void setPosColision(vecColisiones vec);
		void setPosColisionPiso(bool col);
		void setPosColisionTecho(bool col);
		void setPosColisionIzq(bool col);
		void setPosColisionDer(bool col);
		bool getEnSalto();
		void setEnSalto(bool salto);
		void setVelSalto(float vel);
		void atacar();
		void setDash(bool b);
		bool getDash();
		Sprite getSprDash(int i);
		bool getSprDashActivo(int i);
		bool getMiraIzq();
		void setPosInicial(Vector2f posIni);
	};
}

#endif