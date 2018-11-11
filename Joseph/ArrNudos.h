#pragma once
#include "Nudos.h"
class ArrNudos
{
private:
	int *N;
	Nudo**arreglo;

public:
	ArrNudos();
	void agregar(Nudo*obj);
	Nudo*obtener(int indice);
	int get_N();
	~ArrNudos();
};
ArrNudos::ArrNudos()
{
	arreglo = NULL;
	N = new int;
	*N = 0;
}
void ArrNudos::agregar(Nudo*obj)
{
	Nudo**temporal;
	temporal = new Nudo*[*N + 1];
	for (int i = 0; i<*N; i++)
	{
		temporal[i] = arreglo[i];
	}
	temporal[*N] = obj;
	*N = *N + 1;
	arreglo = temporal;
}
Nudo* ArrNudos::obtener(int indice)
{
	return arreglo[indice];
}
int ArrNudos::get_N()
{
	return *N;
}
ArrNudos::~ArrNudos()
{

}