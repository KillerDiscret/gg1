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
	double fuerza;
	double angulo;
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
	void set_fuerza(double valor);
	void set_angulo(double valor);
	double get_fuerza();
	double get_angulo();
	int get_dx();
	int get_dy();
	~Nudo();
};

Nudo::Nudo()
{

}
void Nudo::set_x()
{
	int confirmar;
	do {
		cout << "Ingrese la cordenada en el eje X: " << endl;
		cin >> x;
		cout << endl;
		cout << "¿Esta seguro del dato ingresado?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
		cin >> confirmar;
	} while (confirmar==2);
}
void Nudo::set_y()
{
	int confirmar;
	do {
		cout << "Ingrese la cordenada en el eje Y: " << endl;
		cin >> y;
		cout << endl;
		cout << "¿Esta seguro del dato ingresado?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
		cin >> confirmar;
	} while (confirmar == 2);
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
void Nudo::set_fuerza(double valor)
{
	fuerza = valor;
}
void Nudo::set_angulo(double valor)
{
	angulo = valor;
}
double Nudo::get_fuerza()
{
	return fuerza;
}
double Nudo::get_angulo()
{
	return angulo;
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