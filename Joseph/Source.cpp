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
	int confirmar;
	
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
				else
				{
					cout << "¿Esta seguro del dato ingresado?" << endl;
					cout << "1- SI" << endl;
					cout << "2- NO" << endl;
					cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
					cin >> confirmar;
				}
		
			} while (nudos<0||confirmar==2);

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
				else
				{
					cout << "¿Esta seguro del dato ingresado?" << endl;
					cout << "1- SI" << endl;
					cout << "2- NO" << endl;
					cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
					cin >> confirmar;
				}
			} while (NL<0||confirmar==2);
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
				else
				{
					cout << "¿Esta seguro del dato ingresado?" << endl;
					cout << "1- SI" << endl;
					cout << "2- NO" << endl;
					cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
					cin >> confirmar;
				}
			} while (AF<0||confirmar==2);
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
		do {
			cout << endl;
			cout << "\t\t----DATOS ELEMENTOS----" << endl;
			cout << "Ingrese la cantidad de elementos: " << endl;
			cin >> elementos;
			cout << endl;
			cout << "¿Esta seguro del dato ingresado?" << endl;
			cout << "1- SI" << endl;
			cout << "2- NO" << endl;
			cout << "Ingrese una opcion( 1 || 2 ) para confirmar: " << endl;
			cin >> confirmar;
		} while (confirmar == 2);
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
		//calcular la longitud//
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
			//se calcula cada elemento dentro de su matriz 4X4
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
				//cout<<"dxi: "<<dxi<<endl;
				//cout<<"dyi: "<<dyi<<endl;
				//cout<<"dxf: "<<dxf<<endl;
				//cout<<"dyf: "<<dyf<<endl;
				//cout << "escalar: " << escalar << endl;
				matriz[dxf][dxf] = matriz[dxf][dxf]+pow(coseno, 2)*escalar;
				matriz[dxf][dyf] = matriz[dxf][dyf]+seno*coseno*escalar;
				matriz[dxf][dxi] = matriz[dxf][dxi]+pow(coseno, 2)*escalar*-1;
				matriz[dxf][dyi] = matriz[dxf][dyi]+seno*coseno*escalar*-1;

				matriz[dyf][dxf] = matriz[dyf][dxf]+seno*coseno*escalar;
				matriz[dyf][dyf] = matriz[dyf][dyf]+pow(seno, 2)*escalar;
				matriz[dyf][dxi] = matriz[dyf][dxi]+seno*coseno*escalar*-1;
				matriz[dyf][dyi] = matriz[dyf][dyi]+pow(seno, 2)*escalar*-1;

				matriz[dxi][dxf] = matriz[dxi][dxf]+pow(coseno, 2)*escalar*-1;
				matriz[dxi][dyf] = matriz[dxi][dyf]+seno*coseno*escalar*-1;
				matriz[dxi][dxi] = matriz[dxi][dxi]+pow(coseno, 2)*escalar;
				matriz[dxi][dyi] = matriz[dxi][dyi]+seno*coseno*escalar;

				matriz[dyi][dxf] = matriz[dyi][dxf]+ seno*coseno*escalar*-1;
				matriz[dyi][dyf] = matriz[dyi][dyf]+ pow(seno, 2)*escalar*-1;
				matriz[dyi][dxi] = matriz[dyi][dxi]+ seno*coseno*escalar;
				matriz[dyi][dyi] = matriz[dyi][dyi]+ pow(seno, 2)*escalar;
		}
		//mostramos la matriz
		for (int i=1; i<GL+1;i++)
		{
			
			for(int j=1;j<GL+1;j++)
			{
				if (i == 0)
				{
					cout << "\t\t\t\t"<<matriz[i][j];		
				}
				else
				{
					cout << matriz[i][j] << " ";
				}
			}
			cout << endl;
			cout << endl;
			cout << endl;
		}
		cout << "Presione una tecla para continuar el preoceso...." << endl;
		_getch();
		system("CLS");
		//ingresamos los datos para la matriz de fuerzas
			//inicializamos todas las fuerzas en 0 y el angulo en 0
		for (int i=0;i<nudos;i++)
		{
			arrnudos->obtener(i)->set_fuerza(0);
			arrnudos->obtener(i)->set_angulo(0);

		}
		int nudoscargas;
		cout << "Ingrese el total de cargas que hay en los nudos: " << endl;
		cin >> nudoscargas;
		int continuar;
		double **matrizF;
		matrizF = new double*[(GL - (2 * AF)) + 1];
		for (int i = 0; i<(GL - 2 * AF) + 1; i++)
		{
			matrizF[i] = new double[1];
		}
		for (int i = 0; i<(GL - 2 * AF) + 1; i++)
		{
			matrizF[i][0] = 0;
		}
		do
		{
			int numeronudo;
			double fuerza;
			double angulo;
			cout << "Indique un nudo en que hay carga: " << endl;
			cin >> numeronudo;
			cout << "-------- Nudo " << numeronudo << " --------" << endl;
			cout << "Indique la magnitud de la fuerza en toneladas: " << endl;
			cin >> fuerza;
			arrnudos->obtener(numeronudo-1)->set_fuerza(fuerza);
			cout << "Ingrese el angulo de inclinacion en el eje X en grados sexagesimales: " << endl;
			cin >> angulo;
			arrnudos->obtener(numeronudo-1)->set_angulo(angulo);
			cout << endl;
			int  getdx = arrnudos->obtener(numeronudo - 1)->get_dx();
			int  getdy = arrnudos->obtener(numeronudo - 1)->get_dy();
			double getfuerza = arrnudos->obtener(numeronudo - 1)->get_fuerza();
			double getangulo = arrnudos->obtener(numeronudo - 1)->get_angulo();

			matrizF[getdx][0] = getfuerza*cos((getangulo*atan(1) * 4) / 180);
			matrizF[getdy][0] = getfuerza*sin((getangulo*atan(1) * 4) / 180);

			cout << "¿Desea agregar mas fuerzas?" << endl;
			cout << "1- SI" << endl;
			cout << "2- NO" << endl;
			cout << "Digite una opcion: " << endl;
			cin >> continuar;
		} while (continuar==1);
		
		//mostramos la matriz
		cout << "-------Matriz de fuerzas-------" << endl;
		for (int i = 1; i<(GL - 2 * AF) + 1; i++)
		{
			cout << "\t\t" << matrizF[i][0];
			cout << endl;
			cout << endl;
		}
		cout << "--------Matriz general subdividida--------" << endl;
		for (int i = 1; i<(GL - 2 * AF) + 1; i++)
		{
			for (int j=1;j<(GL - 2 * AF) + 1;j++)
			{
				cout << "\t\t" << matriz[i][j];
			}
			cout << endl;
			cout << endl;
		}
		cout << "--------Matriz general subdividida INVERSA--------" << endl;

		double** matrizI;
		matrizI = new double*[(GL - (2 * AF)) + 1];
		for (int i = 0; i<(GL - 2 * AF) + 1; i++)
		{
			matrizI[i] = new double[(GL - 2 * AF) + 1];
		}
		for (int i = 0; i<(GL - 2 * AF) + 1; i++)
		{
			for (int j = 0; j<(GL - 2 * AF) + 1; j++)
			{
				matrizI[i][j] = 0;
			}
		}
		//pasamos los valores a la matriz inversa
		for (int i = 1; i<(GL - 2 * AF) + 1; i++)
		{
			for (int j = 1; j<(GL - 2 * AF) + 1; j++)
			{
				matrizI[i][j]=matriz[j][i];
			}
			cout << endl;
			cout << endl;
		}
		//mostramos la matriz inversa
		for (int i = 1; i<(GL - 2 * AF) + 1; i++)
		{
			for (int j = 1; j<(GL - 2 * AF) + 1; j++)
			{
				cout << "\t\t" << matrizI[i][j];
			}
			cout << endl;
			cout << endl;
		}
		
		//multiplicamos la matriz de fuerza por la matriz inversa
		int auxi = 1;
		int auxj = (GL - (2* AF))+1;
		int contador = 1;
		int AUX = 0;
		double** matrizP;
		matrizP = new double*[(GL - (2 * AF)) + 1];
		for (int i = 0; i<(GL - (2 * AF)) + 1; i++)
		{
			matrizP[i] = new double[1];
		}
		for (int i = 0; i<(GL - 2 * AF) + 1; i++)
		{
				matrizP[i][0] = 0;	
		}
		do
		{
			if (contador<(GL - (2 * AF)) + 1)
			{
				matrizP[auxi][0] = matrizP[auxi][0] + matrizI[auxi][contador] * matrizF[contador][AUX];
				contador++;
			}
			if (contador== (GL - (2 * AF)) + 1)
			{
				contador = 0;
				
					auxi++;
			
			}

		} while (auxi<(GL - (2 * AF)) + 1);
		//mostramos la matriz
		cout << endl;
		cout << "--------Matriz del Producto Deformaciones--------" << endl;
		for (int i = 1; i<(GL - 2 * AF) + 1; i++)
		{
			cout << "\t\t" << matrizP[i][0];
			cout << endl;
			cout << endl;
		}
		
		//almacenamos esa martriz subdividida en un arreglo nuevo
		double** matrizS;
		matrizS = new double*[(2 * AF)+ 1];
		for (int i = 0; i<(2 * AF) + 1; i++)
		{
			matrizS[i] = new double[(GL - 2 * AF) + 1];
		}
		int contadorS=1;
		for (int i = (GL - 2 * AF) + 1; i<GL + 1; i++)
		{
			for (int j = 1; j<(GL - 2 * AF) + 1; j++)
			{
			matrizS[contadorS][j]=matriz[i][j];
			}
			contadorS++;
		}
		cout << "--------Matriz general subdividida por segunda vez--------" << endl;
		for (int i=1;i<(2 * AF) + 1;i++)
		{
			for (int j=1;j<(GL - 2 * AF) + 1;j++)
			{
				cout<<"\t\t"<<matrizS[i][j];
			}
			cout << endl;
			cout << endl;
		}

		int aui = 1;
		int auj = (GL - (2 * AF)) + 1;
		int cont = 1;
		int AU = 0;
		double** matrizP2;
		matrizP2 = new double*[(2 * AF) + 1];
		for (int i = 0; i<(2 * AF) + 1; i++)
		{
			matrizP2[i] = new double[1];
		}
		for (int i = 0; i<(2 * AF) + 1; i++)
		{
			matrizP2[i][0] = 0;
		}
		do
		{
			if (cont<(GL - (2 * AF)) + 1)
			{
				matrizP2[aui][0] = matrizP2[aui][0] + matrizS[aui][cont]*matrizP[cont][AU];
				cont++;
			}
			if (cont == (GL - (2 * AF)) + 1)
			{
				cont = 0;

				aui++;

			}

		} while (aui<(GL - (2 * AF)) + 1);
		//mostramos la matriz
		cout << endl;
		cout << "--------Matriz del Producto ultimo--------" << endl;
		for (int i = 1; i<(2 * AF) + 1; i++)
		{
			cout << "\t\t" << matrizP2[i][0];
			cout << endl;
			cout << endl;
		}


		_getch();
		system("pause");
	return 0;
}