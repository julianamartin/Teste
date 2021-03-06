#pragma once
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:
	float moveu;
	float amplitude;
	bool esquerda;

public:
	Inimigo();
	~Inimigo();
	void Mover(float deltaTime);
	virtual void Inicializa() = 0;
};

