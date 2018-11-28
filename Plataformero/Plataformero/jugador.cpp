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
	Jugador::Jugador(float x, float y, Vector2f v):Personaje(x,y,v)
	{
		

		tex.loadFromFile("res/assets/char.png");

		sprite.setTexture(tex);
		sprite.setPosition(pos);

		sprite.setTextureRect(sf::IntRect(0, 0, sprite.getLocalBounds().width / 3, sprite.getLocalBounds().height));
	}


	Jugador::~Jugador()
	{

	}

	void Jugador::mover()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			setY(getPos().y + getVel().y*Juego::getFrameTime());
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			setY(getPos().y - getVel().y*Juego::getFrameTime());
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
	}

	void Jugador::draw()
	{
		Juego::getWindow()->draw(sprite);
	}
}