#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "SFML\Graphics.hpp"
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
using namespace sf;

namespace Juego
{
	class Personaje
	{
		int cantVidas;
		Vector2f pos;
		Vector2f vel;
		const float gravedad=2.0f;
		Sprite sprite;
		RectangleShape collider;
	public:
		Personaje();
		~Personaje();
	};
}
#endif
