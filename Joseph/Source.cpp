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
				cout << "Ingrese el total de apoyos fijos: " << endl;
				cin >> AF;
				if (AF<0)
				{
					cout << "Ingrese una cantidad positiva" << endl;
					cout << "(Presione cualquier tecla para reiniciar)...." << endl;
					getch();
				}
			} while (AF<0);
			if (nudos != (NL +AF))
			{
				cout << "La cantidad de nudos libres y fijos es diferente al total de nudos" << endl;
				cout << "(Presione cualquier tecla para reiniciar)...." << endl;
				getch();
				system("CLS");
			}
		} while (nudos != (NL +AF));
		GL = 2 * nudos;
		cout << "\t ----DATOS----" << endl;
		cout << "Nudos libres: " << NL<<endl;
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
			arrnudos->obtener(i)->set_dy(i+1);
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
		
		//creamos una matriz cuadrática 
		double **matriz;
		matriz = new double*[GL+1];
		for (int i=0; i<GL+1;i++)
		{
			matriz[i] = new double[GL+1];
		}
		//pasamos los valores a la matriz, todos son ceros inicialmente
		for (int i=0; i<GL+1;i++)
		{
			for (int j=0;j<GL+1;j++)
			{
				
				matriz[i][j] = 0;
			}
		}
		//pasamos las variables de la matriz pequeña a la grande multiplicando directamente con el escalar
		for (int i = 0; i<elementos; i++)
		{
			double area=arrobj->obtener(i)->get_area();
			double young=arrobj->obtener(i)->get_young();
			int inicial=arrobj->obtener(i)->get_inicial();
			int final=arrobj->obtener(i)->get_final();
			double longitud = arrobj->obtener(i)->get_longitud();
			double seno = arrobj->obtener(i)->get_sen();
			double coseno = arrobj->obtener(i)->get_cos();
			double escalar = ((young*area) / longitud)*pow(10, -4);
			int dxi=(arrnudos->obtener(inicial - 1)->get_dx());
			int dyi=(arrnudos->obtener(inicial - 1)->get_dy());
			int dxf = (arrnudos->obtener(final - 1)->get_dx());
			int dyf=(arrnudos->obtener(final - 1)->get_dy());
				cout<<"dxi: "<<dxi<<endl;
				cout<<"dyi: "<<dyi<<endl;
				cout<<"dxf: "<<dxf<<endl;
				cout<<"dyf: "<<dyf<<endl;
				cout << "escalar: " << escalar << endl;
				matriz[dxf][dxf] = pow(coseno, 2)*escalar;
				matriz[dxf][dyf] = seno*coseno*escalar;
				matriz[dxf][dxi] = pow(coseno, 2)*escalar*-1;
				matriz[dxf][dyi] = seno*coseno*escalar*-1;

				matriz[dyf][dxf] = seno*coseno*escalar;
				matriz[dyf][dyf] = pow(seno,2)*escalar;
				matriz[dyf][dxi] = seno*coseno*escalar*-1;
				matriz[dyf][dyi] = pow(seno, 2)*escalar*-1;

				matriz[dxi][dxf] = pow(coseno, 2)*escalar*-1;
				matriz[dxi][dyf] = seno*coseno*escalar*-1;
				matriz[dxi][dxi] = pow(coseno, 2)*escalar;
				matriz[dxi][dyi] = seno*coseno*escalar;

				matriz[dyi][dxf] = seno*coseno*escalar*-1;
				matriz[dyi][dyf] = pow(seno, 2)*escalar*-1;
				matriz[dyi][dxi] = seno*coseno*escalar;
				matriz[dyi][dyi] = pow(seno, 2)*escalar;
		}
		//mostramos la matriz
		for (int i=0; i<GL+1;i++)
		{
			
			for(int j=0;j<GL+1;j++)
			{
				if (i == 0)
				{
					cout << "\t  "<<matriz[i][j];		
				}
				else
				{
					cout << matriz[i][j] << " ";
				}
			}
			cout << endl;
		}
		_getch();
	return 0;
}