#pragma once
#include "pch.h"

template <class TIPO>
class Lista
{
public:
	template <class TIPO>
	class Elemento
	{
	private:
		Elemento<TIPO>* pProx;
		TIPO* P;
	public:
		Elemento<TIPO>(){}
		~Elemento<TIPO>(){}
		Elemento<TIPO>* getProx() { return pProx; }
		void setProx(Elemento<TIPO>* pElem) { pProx = pElem; }
		void setInfo(TIPO* info) { P = info; }
		TIPO* getInfo() { return P; }
	};

private:
	Elemento<TIPO>* pPrim;
	Elemento<TIPO>* pAtual;
public:
	Lista();
	~Lista();
	void incluir(TIPO* p);
	Elemento<TIPO>* getPrim();
	void limpa();
	void remove();
};

template <class TIPO>
Lista<TIPO>::Lista()
{
	pPrim = NULL;
	pAtual = NULL;
}
template <class TIPO>
Lista<TIPO>::~Lista()
{
	limpa();
}
template<class TIPO>
void Lista<TIPO>::incluir(TIPO* p)
{
	Elemento<TIPO>* pAux = NULL;
	pAux = new Elemento<TIPO>;
	pAux->setInfo(p);

	if (pPrim == NULL)
	{
		pPrim = pAux;
		pAtual = pAux;
	}
	else
	{
		pAtual->setProx(pAux);
		pAtual = pAux;
	}
}

template<class TIPO>
Lista<TIPO>::Elemento<TIPO>* Lista<TIPO>::getPrim()
{
	return pPrim;
}
template <class TIPO>
void Lista<TIPO>::limpa()
{
	Elemento<TIPO>* pAux = pPrim;

	while (pAux != NULL)
	{
		pPrim = pPrim->getProx();
		delete pAux;
		pAux = pPrim;
	}
}

template<class TIPO>
void Lista<TIPO>::remove()
{
	Elemento<TIPO>* pAux = pPrim, pAux2 = NULL;
	while (pAux != NULL)
	{
		pAux2 = pAux->getProx();
		pAux->setProx(NULL);
		pAux = pAux2;
	}
}
