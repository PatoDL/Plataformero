#include "jugador.h"

#include "SFML\Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "juego.h"
#include "colisiones.h"

using namespace std;

using namespace sf;

namespace juego
{
	Texture tex;
	static bool cambio;
	static bool enAire;
	IntRect src;
	IntRect original;
	Jugador::Jugador(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		tex.loadFromFile("res/assets/char.png");

		pos = { x,y };

		sprite.setTexture(tex);
		sprite.setPosition(pos);

		original = sprite.getTextureRect();

		src.top = 0;
		src.left = 0;
		src.width = sprite.getLocalBounds().width / 3;
		src.height = sprite.getLocalBounds().height;

		sprite.setTextureRect(src);

		setColSize({ static_cast<float> (sprite.getTextureRect().width), static_cast<float>(sprite.getTextureRect().height) });
		sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
		setColOrigin(sprite.getOrigin());

		enAire = false;
		cambio = false;

		posColision = { false,false,false,false };
		enSalto = false;
		velSalto = getVel().y;
	}


	Jugador::~Jugador()
	{

	}

	void Jugador::mover()
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (!posColision._arriba && !enSalto && posColision._abajo)
			{
				cambio = true;
				enAire = true;
				enSalto = true;
			}
			posColision._abajo = false;

		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (!posColision._izq)
			{
				setX(getPos().x - getVel().x*Juego::getFrameTime());
			}
			posColision._der = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (!posColision._der)
			{
				setX(getPos().x + getVel().x*Juego::getFrameTime());
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

		if (cambio)
		{
			if (enAire)
			{
				src.left = src.width;
			}
			else
			{
				src.left = 0;
			}

			sprite.setTextureRect(src);

			cambio = false;
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