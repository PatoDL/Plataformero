#include "vidaExtra.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	static Texture tex;

	VidaExtra::VidaExtra()
	{
		if (!tex.loadFromFile("res/assets/1up.png"))
		{
		}
		sprite.setTexture(tex);
		sprite.setOrigin(sprite.getGlobalBounds().height / 2, (sprite.getGlobalBounds().width / 2));
	}
}