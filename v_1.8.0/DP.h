#pragma once
#include "Inimigo.h"
class DP : public Inimigo
{
private:
	static int quantidade;
public:
	DP();
	~DP();
	void Inicializa();
	void setPosicao();
};



