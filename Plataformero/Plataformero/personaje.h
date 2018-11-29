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
		virtual void init()=0;
		virtual void mover() = 0;
		void setVidas(int vid);
		int getVidas();
		void setCol(sf::Vector2f posi, sf::Vector2f tam, sf::Color color);
		void setVel(Vector2f v);
		Vector2f getVel();
		void setColPos(Vector2f posi);
		void setColSize(Vector2f tam);
		void setColColor(Color color);
		void setColOrigin(Vector2f ori);
		RectangleShape getCol();
		sf::Vector2f getPos();
		void setPos(float x, float y);
		void setX(float x);
		void setY(float y);
		virtual void update();
		virtual void draw();
		void aplicarGravedad();
		float getGravedad();
		float getVelCaida();
		void setVelCaida(float vel);
	};
}
#endif
