#include "opciones.h"

#include "juego/juego.h"

namespace juego
{
	Opciones::Opciones()
	{
		
	}


	Opciones::~Opciones()
	{
	}

	void Opciones::inicializar()
	{
		atras = Button::create();
		atras->setText("Atras");
		atras->setRenderer(Juego::getTheme().getRenderer("Button"));
		atras->setTextSize(40);
		atras->setSize(120, 60);
		atras->setPosition(atras->getSize().x / 2, atras->getSize().y / 2);
		atras->connect("pressed", [&]() {Juego::setEstadoActual(menu, false); });
		Juego::getGui()->add(atras);
	}

	void Opciones::chequearInput() 
	{

	}

	void Opciones::actualizar()
	{
	}

	void Opciones::dibujar(Juego* juego)
	{

	}

	void Opciones::desinicializar()
	{
		atras->setVisible(false);
	}
}