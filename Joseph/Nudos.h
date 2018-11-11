#pragma once
#include <conio.h>
#include <iostream>
using namespace std;
using namespace System;
class Nudo
{
private:
	int orden;
	double x;
	double y;
	int dx;
	int dy;
public:
	Nudo();
	void set_x();
	void set_y();
	double get_x();
	double get_y();
	void set_orden(int valor);
	int get_orden();
	void set_dx(int valor);
	void set_dy(int valor);
	int get_dx();
	int get_dy();
	~Nudo();
};

Nudo::Nudo()
{

}
void Nudo::set_x()
{
	cout << "Ingrese la cordenada en el eje X: " << endl;
	cin >> x;
}
void Nudo::set_y()
{
	cout << "Ingrese la cordenada en el eje Y: " << endl;
	cin >> y;
}

void Nudo::set_orden(int valor)
{
	orden = valor;
}
int  Nudo::get_orden()
{
	return orden;
}
void Nudo::set_dx(int valor)
{
	dx = (valor* 2) - 1;
}
void Nudo::set_dy(int valor)
{
	dy = (valor* 2);
}
int Nudo::get_dx()
{
	return dx;
}
int Nudo::get_dy()
{
	return dy;
}
double  Nudo::get_x()
{
	return x ;
}
double  Nudo::get_y()
{
	return y;
}
Nudo::~Nudo()
{

}