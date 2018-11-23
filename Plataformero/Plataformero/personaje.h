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
		int cantVidas;
		Vector2f pos;
		Vector2f vel;
		const float gravedad=2.0f;
		Sprite sprite;
		RectangleShape collider;
	public:
		Personaje(float x, float y/*, Sprite spr*/);
		~Personaje();
		virtual void mover() = 0;
		void setVidas(int vid);
		int getVidas();
		void setVel(Vector2f v);
		Vector2f getVel();
		RectangleShape getCol();
		Vector2f getPos();
		void setPos(float x, float y);
		void setX(float x);
		void setY(float y);
		void update();
	};
}
#endif
