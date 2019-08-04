#include "enemigo.h"

#include "juego/juego.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	static Texture tex;
	static float tiempoAnimacion;
	static IntRect src;

	Escarabajo::Escarabajo(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		setColColor(Color::Red);
		if (!tex.loadFromFile("res/assets/bug.png"))
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


	Escarabajo::~Escarabajo()
	{
	}

	void Escarabajo::inicializar()
	{
		sprite.setTextureRect(src);
		sprite.setPosition(pos);
		sprite.setOrigin(sprite.getGlobalBounds().height, (sprite.getGlobalBounds().width / 2));
		setColOrigin({ static_cast<float>(src.width) / 2.f ,static_cast<float>(src.height) });
		estaVivo = true;
	}

	void Escarabajo::mover()
	{
		setX(getPos().x + getVel().x*Juego::getFrameTime());
	}

	void Escarabajo::actualizar()
	{
		tiempoAnimacion += Juego::getFrameTime();

		if (getVel().x > 0)
		{
			sprite.setScale(-1, 1);
		}
		else
		{
			sprite.setScale(1, 1);
		}

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

	void Escarabajo::dibujar()
	{
		Juego::getWindow()->draw(sprite);
	}

	void Escarabajo::chequearEnPlataforma(Mapa* map, int i)
	{
		if (getPos().x - getCol().getGlobalBounds().width/2 <= map->getPlataforma(map->getPlatConEnemigo(i)).getGlobalBounds().left || 
			getPos().x + getCol().getGlobalBounds().width / 2 >= map->getPlataforma(map->getPlatConEnemigo(i)).getGlobalBounds().left+ map->getPlataforma(map->getPlatConEnemigo(i)).getGlobalBounds().width)
		{
			setVel({ getVel().x*-1, getVel().y });
		}
	}

	bool Escarabajo::getEstaVivo()
	{
		return estaVivo;
	}

	void Escarabajo::setEstaVivo(bool vivo)
	{
		estaVivo = vivo;
	}
}