#include"listasD.h"
#include<fstream>
#include"MIniVector.h"
void interfazvisual() {
	int opcion = 0;
	string nombrearch="";
	string contra;
	string line = "";
	Archivos* archi = new Archivos();
	while (true){
		system("cls");
		do{
			system("cls");
			cout << "--------Bienvenido----------\n";
			cout << "1._Cargar Datos\n";
			cout << "2._Ingresa a ver/modificar datos\n";
			cin >> opcion;
		} while (opcion<1||opcion>2);
		switch (opcion)
		{
		case 1: cout << "Ingrese el archivo curso a cargar\n";
			cin >> nombrearch;
			archi->leernuevo(nombrearch);
			cout << "Carga de datos Completada";
			archi->mostrarTodos();
			getline(cin, line);
			getline(cin, line);
			break;
		case 2: 
			if (archi->vacio()){
				cout << "\nNo hay archivos disponibles\n";
				getline(cin, line);
				getline(cin, line);
			}else{
				do {
					cout << "Ingresar contrasena de estudiante para ver datos\n";
					cout << "Ingresar contrasena de profesor para modificar datos\n";
					cin >> contra;
				} while (contra != "Walter" && contra != "Estudiante");
				if (contra == "Walter") {
					InterfazProfesor_Estudiante(archi, 1);
				}
				else {
					InterfazProfesor_Estudiante(archi, 0);
				}
			}
			break;
		default:break;
		}
	}
	delete archi;
}
