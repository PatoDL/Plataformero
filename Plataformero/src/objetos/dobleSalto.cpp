#include "dobleSalto.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	static Texture tex;

	DobleSalto::DobleSalto()
	{
		Texture tex;

		if (!tex.loadFromFile("res/assets/dobleSalto.png"))
		{
		}
		sprite.setTexture(tex);
		sprite.setOrigin(sprite.getGlobalBounds().height / 2, (sprite.getGlobalBounds().width / 2));
	}
}