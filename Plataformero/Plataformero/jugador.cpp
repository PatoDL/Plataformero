#include "jugador.h"

#include "SFML\Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "juego.h"
#include "colisiones.h"

using namespace sf;

namespace juego
{
	Texture tex;
	IntRect src;
	IntRect original;
	bool caminandoDer;
	bool caminandoIzq;
	float tiempoAnimacion;
	Jugador::Jugador(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		tex.loadFromFile("res/assets/char.png");

		pos = { x,y };

		sprite.setTexture(tex);
		sprite.setPosition(pos);

		original = sprite.getTextureRect();

		src.top = 0;
		src.left = 0;
		src.width = sprite.getLocalBounds().width / 5;
		src.height = sprite.getLocalBounds().height;

		sprite.setTextureRect(src);

		setColSize({ static_cast<float> (sprite.getTextureRect().width), static_cast<float>(sprite.getTextureRect().height) });
		sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
		setColOrigin(sprite.getOrigin());

		caminandoDer = false;
		caminandoIzq = false;
		tiempoAnimacion = 0;

		posColision = { false,false,false,false };
		enSalto = false;
		velSalto = getVel().y;
		haceDash = false;
		multiplicadorDash = 7.0f;
		miraIzq = false;
		miraDer = true;
		timerEntreDash = 0.0f;
		timerPosiciones = 0.0f;

		for (int i = 0; i < cantSprDash; i++)
		{
			sprActivo[i] = false;
		}
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
				enSalto = true;
			}
			posColision._abajo = false;

		}
		if (Keyboard::isKeyPressed(Keyboard::Left) && !haceDash)
		{
			if (!posColision._izq)
			{
				setX(getPos().x - getVel().x*Juego::getFrameTime());
				caminandoIzq = true;
				miraDer = false;
				miraIzq = true;
			}
			posColision._der = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) && !haceDash)
		{
			if (!posColision._der)
			{
				setX(getPos().x + getVel().x*Juego::getFrameTime());
				caminandoDer = true;
				miraDer = true;
				miraIzq = false;
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
		
			if (enSalto)
			{
				src.left = src.width*3;
			}
			else if (caminandoDer)
			{
				sprite.setScale(1, 1);
				if (tiempoAnimacion>0.15f)
				{
					src.left = src.width;
				}
				else
				{
					src.left = src.width*2;
				}
			}
			else if (caminandoIzq)
			{
				sprite.setScale(-1, 1);
				if (tiempoAnimacion>0.15f)
				{
					src.left = src.width;
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

			if (tiempoAnimacion > 0.1f)
			{
				tiempoAnimacion = 0;
			}
	}

	void Jugador::draw()
	{
		Juego::getWindow()->draw(sprite);

		if (haceDash)
		{
			for (int i = 0; i < cantSprDash; i++)
			{
				if (sprActivo[i])
				{
					Juego::getWindow()->draw(sprDash[i]);
				}
			}
		}
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

	void Jugador::atacar()
	{
		if (Keyboard::isKeyPressed(Keyboard::Space) && !haceDash && timerEntreDash<0.0f)
		{
			haceDash = true;
			timerDash = 0.0f;
			timerEntreDash = 2.0f;
		}
		if (haceDash)
		{
			static int i = 0;
			timerDash += Juego::getFrameTime();
			if (timerDash < 0.15f)
			{
				
				if (miraDer)
				{
					setX(getPos().x + getVel().x*Juego::getFrameTime()*multiplicadorDash);
				}
				else
				{
					setX(getPos().x - getVel().x*Juego::getFrameTime()*multiplicadorDash);
				}
				if (timerPosiciones >= 0.15f/cantSprDash*i && i<cantSprDash)
				{
					sprDash[i] = sprite;
					sprActivo[i] = true;
				}
				else 
				{
					timerPosiciones = timerDash;
				}

				i++;
			}
			else
			{
				for (int i = 0; i < cantSprDash; i++)
				{
					sprActivo[i] = false;
				}
				timerDash = 0.0f;
				haceDash = false;
				i = 0;
			}
		}
		else
		{
			timerEntreDash -= Juego::getFrameTime();
		}
	}
}