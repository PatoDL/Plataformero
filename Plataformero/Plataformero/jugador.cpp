#include "jugador.h"

#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "juego.h"
#include "colisiones.h"

using namespace std;

using namespace sf;

namespace juego
{
	static Texture tex;
	static IntRect src;
	bool caminandoDer;
	bool caminandoIzq;
	static float tiempoAnimacion;
	static float timer;

	Jugador::Jugador(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		tex.loadFromFile("res/assets/char.png");

		pos = { x,y };

		sprite.setTexture(tex);
		sprite.setPosition(pos);

		src.top = 0;
		src.left = 0;
		src.width = sprite.getLocalBounds().width / 6;
		src.height = sprite.getLocalBounds().height;

		sprite.setTextureRect(src);

		init();
	}


	Jugador::~Jugador()
	{

	}

	void Jugador::init()
	{
		setColSize({ static_cast<float> (sprite.getTextureRect().width), static_cast<float>(sprite.getTextureRect().height) });
		sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
		setColOrigin(sprite.getOrigin());

		setPos(50, 1800);

		caminandoDer = false;
		caminandoIzq = false;
		tiempoAnimacion = 0;
		timer = 0.0f;
		posColision = { false,false,false,false };
		enSalto = true;
		velSalto = getVel().y;
	}

	void Jugador::mover()
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (!posColision._arriba && !enSalto && posColision._abajo)
			{
				enSalto = true;
			}
			posColision._abajo = false;

		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (!posColision._izq)
			{
				setX(getPos().x - getVel().x*Juego::getFrameTime());
				caminandoIzq = true;
			}
			posColision._der = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (!posColision._der)
			{
				setX(getPos().x + getVel().x*Juego::getFrameTime());
				caminandoDer = true;
			}
			posColision._izq = false;
		}

		if (enSalto)
		{
			velSalto -= getGravedad() * Juego::getFrameTime();
			setY(getPos().y - velSalto * Juego::getFrameTime());
		}
		else
		{
			velSalto = getVel().y;
		}
	}

	void Jugador::update()
	{
		if (!posColision._abajo && !enSalto)
			aplicarGravedad();
		sprite.setPosition(pos);
		Personaje::update();

		tiempoAnimacion += Juego::getFrameTime();
		timer += Juego::getFrameTime();
		
			if (enSalto)
			{
				src.left = src.width*4;
			}
			else if (caminandoDer)
			{
				sprite.setScale(1, 1);
				if (tiempoAnimacion<0.10f)
				{
					src.left = src.width;
				}
				else if (tiempoAnimacion<0.20f)
				{
					src.left = src.width * 2;
				}
				else if (tiempoAnimacion<0.30f)
				{
					src.left = src.width * 3;
				}
				else
				{
					src.left = src.width * 2;
				}
			}
			else if (caminandoIzq)
			{
				sprite.setScale(-1, 1);
				if (tiempoAnimacion<0.10f)
				{
					src.left = src.width;
				}
				else if (tiempoAnimacion<0.20f)
				{
					src.left = src.width * 2;
				}
				else if (tiempoAnimacion<0.30f)
				{
					src.left = src.width * 3;
				}
				else
				{
					src.left = src.width * 2;
				}
				
			}
			else
			{
				src.left = 0;
			}

			if (caminandoDer)
			{
				caminandoDer = false;
			}
			if (caminandoIzq)
			{
				caminandoIzq = false;
			}

			sprite.setTextureRect(src);

			if (tiempoAnimacion > 0.4f)
			{
				tiempoAnimacion = 0;
			}
			if (timer > 2&&timer<2.5f)
			{
				enSalto = false;
			}
	}

	void Jugador::draw()
	{
		Juego::getWindow()->draw(sprite);
	}

	Jugador Jugador::getJug()
	{
		return *this;
	}

	vecColisiones Jugador::getColision()
	{
		return posColision;
	}

	void Jugador::setPosColision(vecColisiones vec)
	{
		posColision = vec;
	}

	void Jugador::setPosColisionPiso(bool col)
	{
		posColision._abajo = col;
	}

	void Jugador::setPosColisionTecho(bool col)
	{
		posColision._arriba = col;
	}

	void Jugador::setPosColisionIzq(bool col)
	{
		posColision._izq = col;
	}

	void Jugador::setPosColisionDer(bool col)
	{
		posColision._der = col;
	}

	bool Jugador::getEnSalto()
	{
		return enSalto;
	}

	void Jugador::setEnSalto(bool piso)
	{
		enSalto = piso;
	}

	void Jugador::setVelSalto(float vel)
	{
		velSalto = vel;
	}
}