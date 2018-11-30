#include "creditos.h"

#include "juego/juego.h"

namespace juego
{
	Creditos::Creditos()
	{
	}


	Creditos::~Creditos()
	{
	}

	void Creditos::inicializar()
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

	void Creditos::chequearInput()
	{

	}

	void Creditos::actualizar()
	{

	}

	void Creditos::dibujar()
	{
		Juego::dibujarVersion();
	}

	void Creditos::desinicializar()
	{
		
	}

	void Creditos::esconderGui()
	{
		atras->setVisible(false);
	}

	void Creditos::mostrarGui()
	{
		atras->setVisible(true);
	}
}