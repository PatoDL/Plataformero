#include "personaje.h"

#include "SFML\Graphics\Sprite.hpp"

namespace juego
{
	Personaje::Personaje(float x, float y/*, Sprite spr*/,Vector2f v)
	{
		pos.x = x;
		pos.y = y;
		cantVidas = 1;
		//sprite = spr;
		collider.setPosition(pos);
		collider.setSize({40, 40});
		collider.setFillColor(Color::Blue);
	}

	Personaje::~Personaje()
	{
		//delete collider;
	}

	void Personaje::setVidas(int vid)
	{
		cantVidas = vid;
	}
	int Personaje::getVidas()
	{
		return cantVidas;
	}
	void Personaje::setVel(Vector2f v)
	{
		vel = v;
	}
	Vector2f Personaje::getVel()
	{
		return vel;
	}

	void Personaje::setCol(Vector2f posi, Vector2f tam, Color color)
	{
		collider.setPosition(posi);
		collider.setSize(tam);
		collider.setFillColor(color);
	}

	RectangleShape Personaje::getCol()
	{
		return collider;
	}

	Vector2f Personaje::getPos()
	{
		return pos;
	}

	void Personaje::setPos(float x, float y)
	{
		pos.x = x;
		pos.y = y;
	}

	void Personaje::setX(float x)
	{
		pos.x = x;
	}

	void Personaje::setY(float y)
	{
		pos.y = y;
	}

	void Personaje::update()
	{
		collider.setPosition(pos);
	}
}