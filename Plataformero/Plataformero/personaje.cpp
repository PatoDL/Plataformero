#include "personaje.h"

#include "SFML\Graphics\Sprite.hpp"
#include "juego.h"

namespace juego
{
	Personaje::Personaje(float x, float y,Vector2f v)
	{
		pos.x = x;
		pos.y = y;
		cantVidas = 1;
		collider.setPosition(pos);
		//collider.setSize({40, 40});
		collider.setFillColor(Color::Blue);
		vel.x = v.x;
		vel.y = v.y;
		//collider.setOrigin({ collider.getSize().x / 2, collider.getSize().y / 2 });
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

	void Personaje::setColPos(Vector2f posi)
	{
		collider.setPosition(posi);
	}

	void Personaje::setColSize(Vector2f tam)
	{
		collider.setSize(tam);
	}

	void Personaje::setColColor(Color color)
	{
		collider.setFillColor(color);
	}

	void Personaje::setColOrigin(Vector2f ori)
	{
		collider.setOrigin(ori);
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

	void Personaje::draw()
	{
		
	}

	void Personaje::aplicarGravedad()
	{
		setY(pos.y + gravedad * Juego::getFrameTime());
	}
}