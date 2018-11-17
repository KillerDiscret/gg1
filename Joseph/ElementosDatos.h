#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
class elemento
{
private:
	double sen;
	double cos;
	int enumeracion;
	double longitud;
	double area;
	double young;
	int inicial;
	int final;
	double xi, yi;
	double xf, yf;
public:
	elemento();
	void set_area();
	void set_young();
	void set_inicial();
	void set_final();
	void set_xi(double valor);
	void set_yi(double valor);
	void set_xf(double valor);
	void set_yf(double valor);
	void set_enumeracion(int valor);
	void set_longitud(double valor);
	void set_sen(double valor);
	void set_cos(double valor);
	double get_sen();
	double get_cos();
	double get_longitud();
	int get_enumeracion();
	int get_inicial();
	int get_final();

	double get_area();
	double get_young();
	double get_xi();
	double get_yi();
	double get_xf();
	double get_yf();
	~elemento();
};
elemento::elemento()
{

}

void elemento::set_area()
{
	int confirmar;
	do {
		cout << "Ingrese el area(cm^2): " << endl;
		cin >> area;
		cout << endl;
		cout << endl;
		cout << "¿Esta seguro del dato ingresado?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
		cin >> confirmar;
	} while (confirmar==2);

}
void elemento::set_young()
{
	int confirmar;
	do
	{
		cout << "Ingrese el modulo de Young(Toneladas/(m^2)): " << endl;
		cin >> young;
		cout << endl;
		cout << "¿Esta seguro del dato ingresado?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
		cin >> confirmar;
	} while (confirmar==2);
}

void elemento::set_inicial()
{
	int confirmar;
	do
	{
		cout << "Ingrese el numero del nodo inicial:" << endl;
		cin >> inicial;
		cout << endl;
		cout << "¿Esta seguro del dato ingresado?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
		cin >> confirmar;

	} while (confirmar==2);
}
void elemento::set_final()
{
	int confirmar;
	do
	{
		cout << "Ingrese el numero del nodo final:" << endl;
		cin >> final;
		cout << endl;
		cout << "¿Esta seguro del dato ingresado?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
		cin >> confirmar;

	} while (confirmar == 2);
	
}
void elemento::set_xi(double valor)
{
	xi = valor;
}
void elemento::set_yi(double valor)
{
	yi = valor;
}
void elemento::set_xf(double valor)
{
	xf = valor;
}
void elemento::set_yf(double valor)
{
	yf = valor;
}
void elemento::set_enumeracion(int valor)
{
	enumeracion = valor;
}

void elemento::set_longitud(double valor)
{
	longitud = valor;
}
void elemento::set_sen(double valor)
{
	sen = valor;
}
void elemento::set_cos(double valor)
{
	cos = valor;
}
double elemento::get_sen()
{
	return sen;
}
double elemento::get_cos()
{
	return cos;
}
double elemento::get_longitud()
{
	return longitud;
}
int elemento::get_inicial()
{
	return inicial;
}
int elemento::get_final()
{
	return final;
}
double elemento::get_xi()
{
	return xi;
}
double elemento::get_yi()
{
	return yi;
}
double elemento::get_xf()
{
	return xf;
}
double elemento::get_yf()
{
	return yf;
}
int elemento::get_enumeracion()
{
	return enumeracion;
}

double elemento::get_area()
{
	return area;
}
double elemento::get_young()
{
	return young;
}

elemento::~elemento()
{

}