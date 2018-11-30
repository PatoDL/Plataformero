#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	class Personaje
	{
	protected:
		sf::Sprite sprite;
		sf::Vector2f pos;
	private:
		int cantVidas;
		sf::Vector2f vel;
		const float gravedad=98.0f*4;
		float velCaida;
		RectangleShape collider;
	public:
		Personaje(float x, float y/*, Sprite spr*/,sf::Vector2f v);
		~Personaje();
		virtual void inicializar()=0;
		virtual void mover() = 0;
		void setVidas(int vid);
		int getVidas();
		void setVel(sf::Vector2f v);
		sf::Vector2f getVel();
		void setColPos(sf::Vector2f posi);
		void setColSize(sf::Vector2f tam);
		void setColColor(sf::Color color);
		void setColOrigin(sf::Vector2f ori);
		RectangleShape getCol();
		sf::Vector2f getPos();
		void setPos(float x, float y);
		void setX(float x);
		void setY(float y);
		virtual void actualizar();
		virtual void dibujar();
		void aplicarGravedad();
		float getGravedad();
		float getVelCaida();
		void setVelCaida(float vel);
	};
}
#endif
