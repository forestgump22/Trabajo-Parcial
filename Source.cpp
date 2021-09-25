#include <iostream>
#include "ListaDoble.h"
#include "Curso.h"
#include "Estudiante.h"
#include "Profesor.h"
#include <conio.h>

using namespace std;

void profesor()
{
	string name, contra;
	bool existe = false;
	Profesor Algoritmos("Walter","Algoritmos","Cueva", 30);
	Profesor MDiscreta("Jonathan", "Matematica Discreta", "Sueros", 30);
	Profesor MComputacional("Edgard", "Matematica Computacional", "Palacios", 30);
	Profesor Requerimientos("Monica", "Especificacion y Analisis de Requerimientos", "Priale", 30);
	Profesor Conta("Anita", "Contabilidad y Presupuestos", "Cruzado", 30);
	ListaDoble<Profesor> profesores;
	profesores.pushBack(Algoritmos);
	profesores.pushBack(MDiscreta);
	profesores.pushBack(MComputacional);
	profesores.pushBack(Requerimientos);
	profesores.pushBack(Conta);

	do
	{
		system("cls");
		cout << "Ingrese su nombre y contrasenia: \n- NOMBRE: ";
		cin >> name;
		cout << "- CONTRASENIA: ";
		cin >> contra;
		for (size_t i = 0; i < profesores.getSize(); i++)
			if (name == profesores.at(i).nombre && contra == profesores.at(i).contra)
				existe = true;
	} while (!existe);
	
	
	cout << "Estos son los estudiantes a tu cargo:\n";
	
	for (size_t i = 0; i < profesores.at(0).estudiantes.size(); i++)
	{
		cout << profesores.at(1).estudiantes.at(i).nombre << endl;
	}
	_getch();

}
void estudiante()
{

}

void interfaz()
{
	int opc;
	do
	{
		cout << "Desea ingresar como: \n 1) profesor \n 2) estudiante \n";
		cin >> opc;
	} while (opc > 2 || opc < 1);
	
	if (opc == 1)
		profesor();
	else
		estudiante();
}

int main()
{
	while(1)
	{
		interfaz();
		system("cls");
	}

	system("pause");
	return 0;
}