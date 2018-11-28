#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "SFML\Graphics.hpp"
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
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
		const float gravedad=2.0f;
		RectangleShape collider;
	public:
		Personaje(float x, float y/*, Sprite spr*/,sf::Vector2f v);
		~Personaje();
		virtual void mover() = 0;
		void setVidas(int vid);
		int getVidas();
		void setVel(sf::Vector2f v);
		sf::Vector2f getVel();
		void setCol(sf::Vector2f posi, sf::Vector2f tam, sf::Color color);
		RectangleShape getCol();
		sf::Vector2f getPos();
		void setPos(float x, float y);
		void setX(float x);
		void setY(float y);
		virtual void update();
		virtual void draw();
	};
}
#endif
