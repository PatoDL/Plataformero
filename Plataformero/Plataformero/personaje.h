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
		Sprite sprite;
		Vector2f pos;
	private:
		int cantVidas;
		Vector2f vel;
		const float gravedad=2.0f;
		RectangleShape collider;
	public:
		Personaje(float x, float y/*, Sprite spr*/,Vector2f v);
		~Personaje();
		virtual void mover() = 0;
		void setVidas(int vid);
		int getVidas();
		void setVel(Vector2f v);
		Vector2f getVel();
		void setCol(Vector2f posi, Vector2f tam, Color color);
		RectangleShape getCol();
		Vector2f getPos();
		void setPos(float x, float y);
		void setX(float x);
		void setY(float y);
		virtual void update();
		virtual void draw();
	};
}
#endif
