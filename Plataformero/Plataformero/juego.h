#ifndef JUEGO_H
#define JUEGO_H

namespace Juego
{
	class Juego
	{
	private:
		bool _inGame;
	public:
		Juego();
		~Juego();
		void setInGame(bool inGame);
		bool getInGame();
	};
}

#endif

