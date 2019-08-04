#include "dobleSalto.h"

#include "SFML\Graphics.hpp"
#include <iostream>

using namespace sf;

namespace juego
{
	static Texture tex;

	DobleSalto::DobleSalto()
	{
		//Texture tex;

		if (!tex.loadFromFile("res/assets/dobleSalto.png"))
		{
		}
		sprite.setTexture(tex);
		sprite.setTextureRect({ 0,0,(int)sprite.getLocalBounds().width,(int)sprite.getLocalBounds().height });
		sprite.setOrigin(sprite.getTextureRect().height / 2, (sprite.getTextureRect().width / 2));
	}
}