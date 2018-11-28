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
}