#include "mariposa.h"

#include "juego/juego.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	static Texture tex;
	static float tiempoAnimacion;
	static IntRect src;

	Mariposa::Mariposa(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		setColColor(Color::Red);
		if (!tex.loadFromFile("res/assets/butterfly.png"))
		{
		}
		sprite.setTexture(tex);
		tiempoAnimacion = 0;
		src.left = 0;
		src.top = 0;
		src.width = static_cast<int>(sprite.getLocalBounds().width / 2);
		src.height = static_cast<int>(sprite.getLocalBounds().height);
		setColSize({ static_cast<float>(src.width),static_cast<float>(src.height) });
		sprite.setTextureRect(src);
		sprite.setPosition(pos);
	}


	Mariposa::~Mariposa()
	{
	}

	void Mariposa::inicializar()
	{
		sprite.setTextureRect(src);
		sprite.setPosition(pos);
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height);
		setColOrigin({ static_cast<float>(src.width) / 2.f ,static_cast<float>(src.height) });
		estaVivo = true;
	}

	void Mariposa::mover()
	{
		setY(getPos().y + getVel().y*Juego::getFrameTime());
	}

	void Mariposa::actualizar()
	{
		tiempoAnimacion += Juego::getFrameTime();

		if (tiempoAnimacion < 0.25f)
		{
			src.left = 0;
		}
		else
		{
			src.left = src.width;
		}

		sprite.setTextureRect(src);

		if (tiempoAnimacion > 0.5f)
		{
			tiempoAnimacion = 0;
		}

		sprite.setPosition(pos);
		setColPos(pos);
	}

	void Mariposa::dibujar()
	{
		Juego::getWindow()->draw(sprite);
	}

	bool Mariposa::getEstaVivo()
	{
		return estaVivo;
	}

	void Mariposa::chequearEnLimitesMapa(Mapa* map, int i)
	{
		if (getPos().y>=map->getTileMap()->GetHeight()*map->getTileMap()->GetTileHeight() || getPos().y <= 0)
		{
			setVel({ getVel().x, getVel().y*-1 });
		}
		
	}

	void Mariposa::setEstaVivo(bool vivo)
	{
		estaVivo = vivo;
	}
}