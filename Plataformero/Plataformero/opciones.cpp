#include "opciones.h"

#include "juego.h"

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

		setResolucion800x600 = Button::create();
		setResolucion800x600->setSize(100,50);
		setResolucion800x600->setPosition(Juego::getAnchoPantalla() / 2 - setResolucion800x600->getSize().x / 2,
			Juego::getAltoPantalla() / 2 - setResolucion800x600->getSize().y / 2);
		setResolucion800x600->setRenderer(Juego::getTheme().getRenderer("Button"));
		setResolucion800x600->connect("Pressed", [&]() {Juego::setAltoPantalla(600); Juego::setAnchoPantalla(800); });
		setResolucion800x600->setText("holi");
		Juego::getGui()->add(setResolucion800x600);
		Juego::getGui()->add(atras);
	}

	void Opciones::chequearInput() 
	{

	}

	void Opciones::actualizar()
	{
		setResolucion800x600->setSize(Juego::getAnchoPantalla() *100/1200, Juego::getAltoPantalla() *50/800);
		setResolucion800x600->setPosition(Juego::getAnchoPantalla() / 2 - setResolucion800x600->getSize().x / 2,
			Juego::getAltoPantalla() / 2 - setResolucion800x600->getSize().y / 2);
	}

	void Opciones::dibujar(Juego* juego)
	{

	}

	void Opciones::desinicializar()
	{
		atras->setVisible(false);
		setResolucion800x600->setVisible(false);
	}
}