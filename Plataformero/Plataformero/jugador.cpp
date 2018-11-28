#include "jugador.h"

#include "SFML\Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "juego.h"

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

		pos = { 100,100 };

		sprite.setTexture(tex);
		sprite.setPosition(pos);

		original = sprite.getTextureRect();

		src.top = 0;
		src.left = 0;
		src.width = sprite.getLocalBounds().width/3;
		src.height = sprite.getLocalBounds().height;

		sprite.setTextureRect(src);
		enAire = false;
		cambio = false;
	}


	Jugador::~Jugador()
	{

	}

	void Jugador::mover()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			setY(getPos().y + getVel().y*Juego::getFrameTime());
			cambio = true;
			enAire = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			setY(getPos().y - getVel().y*Juego::getFrameTime());
			cambio = true;
			enAire = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			setX(getPos().x - getVel().x*Juego::getFrameTime());
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			setX(getPos().x + getVel().x*Juego::getFrameTime());
		}
	}

	void Jugador::update()
	{
		sprite.setPosition(pos);

		if (cambio)
		{
			if (enAire)
			{
				src.left = original.width / 3;
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
}