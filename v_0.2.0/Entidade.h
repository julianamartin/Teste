#pragma once
#include "pch.h"
class Entidade
{
private:
	float x;
	float y;
public:
	Entidade();
	~Entidade();
	virtual void mover() = 0;
};

