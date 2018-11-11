#include<iostream>
#include <conio.h>
#include <math.h>
#include "ElementosDatos.h"
#include "ArregloElementos.h"
#include "Nudos.h"
#include "ArrNudos.h"
using namespace std;
using namespace System;
int main()
{
	int nudos;
	int elementos;
	int NL;
	int AM;
	int AF;
	int GL;
	ArrElementos* arrobj;
	arrobj = new ArrElementos();
	elemento*obj;
	ArrNudos* arrnudos;
	arrnudos = new ArrNudos();
	Nudo*objnudos;

	
		do
		{
			do
			{
				cout << endl;
				cout << "Ingrese la cantidad total de nudos: " << endl;
				cin >> nudos;
				if (nudos<0)
				{
					cout << "Ingrese una cantidad positiva" << endl;
					cout << "(Presione cualquier tecla para reiniciar)...." << endl;
					getch();
				}
			} while (nudos<0);

			do
			{
				cout << endl;
				cout << "Ingrese el total de nudos libres: " << endl;
				cin >> NL;
				if (NL<0)
				{
					cout << "Ingrese una cantidad positiva" << endl;
					cout << "(Presione cualquier tecla para reiniciar)...." << endl;
					getch();
				}
			} while (NL<0);
			do
			{
				cout << endl;
				cout << "Ingrese el total de apoyos moviles: " << endl;
				cin >> AM;
				if (AM<0)
				{
					cout << "Ingrese una cantidad positiva" << endl;
					cout << "(Presione cualquier tecla para reiniciar)...." << endl;
					getch();
				}
			} while (AM<0);
			do
			{
				cout << endl;
				cout << "Ingrese el total de apoyos fijos: " << endl;
				cin >> AF;
				if (AF<0)
				{
					cout << "Ingrese una cantidad positiva" << endl;
					cout << "(Presione cualquier tecla para reiniciar)...." << endl;
					getch();
				}
			} while (AF<0);
			if (nudos != (NL + AM + AF))
			{
				cout << "La cantidad de nudos libres, moviles y fijos es diferente al total de nudos" << endl;
				cout << "(Presione cualquier tecla para reiniciar)...." << endl;
				getch();
				system("CLS");
			}
		} while (nudos != (NL + AM + AF));
		GL = 2 * nudos;
		cout << "\t ----DATOS----" << endl;
		cout << "Nudos libres: " << NL<<endl;
		cout << "Apoyos moviles: " << AM << endl;
		cout << "Apoyos fijos: " << AF << endl;
		cout << "Grados de libertad: " << GL << endl;
		
		for (int i=0; i<nudos;i++)
		{
			cout << "\t\t---Nudo "<<i+1<<"---" << endl;
			objnudos = new Nudo();
			arrnudos->agregar(objnudos);
			arrnudos->obtener(i)->set_x();
			arrnudos->obtener(i)->set_y();
			arrnudos->obtener(i)->set_dx(i+1);
			arrnudos->obtener(i)->set_dy(i + 1);
		}
		cout << "\t\t--DATOS DE NUDOS--" << endl;
		for (int i=0; i<nudos;i++)
		{
			
			cout << "NUDO " << i + 1 << " :" << endl;
			cout<<"eje X: "<<arrnudos->obtener(i)->get_x()<<endl;
			cout<<"eje Y: "<< arrnudos->obtener(i)->get_y() << endl;
			cout << "dx: " << arrnudos->obtener(i)->get_dx() << endl;
			cout << "dy: " << arrnudos->obtener(i)->get_dy() << endl;
		}
		cout << "\t\t----DATOS ELEMENTOS----" << endl;
		cout << "Ingrese la cantidad de elementos: " << endl;
		cin >> elementos;
		for (int i = 0; i < elementos; i++)
		{
			obj= new elemento();
			arrobj->agregar(obj);
			arrobj->obtener(i)->set_enumeracion(i+1);

			cout << "\tELEMENTO " << arrobj->obtener(i)->get_enumeracion() << " :" << endl;
			arrobj->obtener(i)->set_area();
			arrobj->obtener(i)->set_young();
			arrobj->obtener(i)->set_inicial();
			arrobj->obtener(i)->set_final();
			int auxinicial;
			int auxfinal;
			double auxXI;
			double auxYI;
			double auxXF;
			double auxYF;
			auxinicial=arrobj->obtener(i)->get_inicial();
			auxfinal= arrobj->obtener(i)->get_final();
			auxXI = arrnudos->obtener(auxinicial - 1)->get_x();
			auxYI = arrnudos->obtener(auxinicial - 1)->get_y();
			auxXF = arrnudos->obtener(auxfinal - 1)->get_x();
			auxYF = arrnudos->obtener(auxfinal - 1)->get_y();
			arrobj->obtener(i)->set_xi(auxXI);
			arrobj->obtener(i)->set_yi(auxYI);
			arrobj->obtener(i)->set_xf(auxXF);
			arrobj->obtener(i)->set_yf(auxYF);
		}
		//calcular la longitud
		for (int i=0;i<elementos;i++)
		{
			double xf= arrobj->obtener(i)->get_xf();
			double xi= arrobj->obtener(i)->get_xi();
			double yf= arrobj->obtener(i)->get_yf();
			double yi= arrobj->obtener(i)->get_yi();
			double longitud;
			longitud = sqrt(pow(xf-xi,2)+ pow(yf - yi, 2));
			arrobj->obtener(i)->set_longitud(longitud);
			double sen;
			double cos;
			sen = (yf - yi) / longitud;
			cos= (xf - xi) / longitud;
			arrobj->obtener(i)->set_sen(sen);
			arrobj->obtener(i)->set_cos(cos);
		}
		//leer los datos totales
		/*for (int i=0;i<elementos;i++)
		{
			cout << "\t\tELEMENTO " << i + 1 << endl;
			cout<<"area: "<<arrobj->obtener(i)->get_area()<<endl;
			cout << "young: " << arrobj->obtener(i)->get_young() << endl;
			cout << "xi: " << arrobj->obtener(i)->get_xi() << endl;
			cout << "xf: " << arrobj->obtener(i)->get_xf() << endl;
			cout << "yi: " << arrobj->obtener(i)->get_yi() << endl;
			cout << "yf: " << arrobj->obtener(i)->get_yf() << endl;
			cout << "longitud: " << arrobj->obtener(i)->get_longitud() << endl;
			cout << "seno: " << arrobj->obtener(i)->get_sen() << endl;
			cout << "coseno: " << arrobj->obtener(i)->get_cos() << endl;
		}*/
		//pasar los valores a una matriz


		_getch();
	return 0;
}