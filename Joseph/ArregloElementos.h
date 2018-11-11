#pragma once
#include "ElementosDatos.h"
class ArrElementos
{
private:
	int *N;
	elemento**arreglo;

public:
	ArrElementos();
	void agregar(elemento*obj);
	elemento*obtener(int indice);
	int get_N();
	~ArrElementos();
};
ArrElementos::ArrElementos()
{
	arreglo = NULL;
	N = new int;
	*N = 0;
}
void ArrElementos::agregar(elemento*obj)
{
	elemento**temporal;
	temporal = new elemento*[*N + 1];
	for (int i=0; i<*N;i++)
	{
		temporal[i] = arreglo[i];
	}
	temporal[*N] = obj;
	*N = *N + 1;
	arreglo = temporal;
}
elemento* ArrElementos::obtener(int indice) 
{
	return arreglo[indice];
}
int ArrElementos::get_N()
{
	return *N;
}
ArrElementos::~ArrElementos()
{

}