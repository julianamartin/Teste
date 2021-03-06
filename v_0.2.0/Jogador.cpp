#include "pch.h"
#include "Jogador.h"


Jogador::Jogador(sf::Texture* texture, Vector2u imageCount, float switchTime, float rapidez, float alturaPulo):
anima��o(texture,imageCount,switchTime)
{
	this->rapidez = rapidez;
	this->alturaPulo = alturaPulo;
	row = 0;
	faceRight = true;

	objP.setSize(sf::Vector2f(100.0f, 150.0f));
	objP.setOrigin(objP.getSize() / 2.0f);
	objP.setPosition(206.0f, 206.0f);
	objP.setTexture(texture);
}

Jogador::~Jogador()
{
}
void Jogador::Atualiza(float deltaTime)
{
	velocidade.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocidade.x -= rapidez;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocidade.x += rapidez;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && podePular)
	{
		podePular = false;
		velocidade.y = -sqrtf(2.0f * 9.79f * alturaPulo * 100.0f); //square root = 2.0f * gravidade * alturaPulo
	}
	velocidade.y += 9.79f * 100.0f * deltaTime;
	
	if (velocidade.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (velocidade.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
		
	}
	anima��o.Atualiza(row, deltaTime, faceRight);
	objP.setTextureRect(anima��o.uvRect);
	objP.move(velocidade * deltaTime);
}
void Jogador::EmColis�o(sf::Vector2f dire��o)
{
	if (dire��o.x < 0.0f)
	{
		velocidade.x = 0.0f; //Colis�o Esquerda
	}
	else if (dire��o.x > 0.0f)
	{
		velocidade.x = 0.0f; //Colis�o Direita
	}
	if (dire��o.y < 0.0f)
	{
		velocidade.y = 0.0f; //Colis�o embaixo
		podePular = true;
	}
	else if (dire��o.y > 0.0f)
	{
		velocidade.y = 0.0f; //Colis�o em cima
	}

}

void Jogador::Desenha(sf::RenderWindow& window)
{
	window.draw(objP);
}

sf::Vector2f Jogador::getPosition()
{
	return (objP.getPosition());
}
Colisor Jogador::getColis�o()
{
	return(Colisor(objP));
}
