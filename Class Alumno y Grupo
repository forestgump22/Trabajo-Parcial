#include"listasD.h"
#include<fstream>
#include"MIniVector.h"
class Alumno
{
private:
	string nombre;
	string apellido;
	string comentario;
	float nota_TP;
	int nroGrupo;
public:
	Alumno(string nombre="", string apellido="",  int nroGrupo=0, float nota_TP = 0)
		:nombre(nombre), apellido(apellido),nroGrupo(nroGrupo), nota_TP(nota_TP) {
		comentario = "";
	}
	~Alumno() {}
	string getNombre() {
		return nombre;
	}
	string getApellido() {
		return apellido;
	}
	string getInfo() {
		return this->nombre + "\t\t" + this->apellido + "\t"
			+ std::to_string(this->nota_TP) + "\t" + std::to_string(this->nroGrupo) + "\t"
			+comentario+"\n";
	}
	int getgrupo() {
		return this->nroGrupo;
	}
	int getNota() {
		return this->nota_TP;
	}
	void setNota(int nota){
		this->nota_TP = nota;
	}
	void setcoment(string comentario) {
		this->comentario = comentario;
	}
};
class Grupo
{
private:
	int numeroG;
	ListaDoble<Alumno*> grupo;
public:
	Grupo(int numeroG=0):numeroG(numeroG){}
	~Grupo() { grupo.eraseAll(); }
	void addalumno(Alumno* alumn){
		grupo.pushBack(alumn);
	}
	void printGrupo() {
		cout << "Grupo " << numeroG << "\n";
		auto mostrar = [](Alumno* a)->void {cout << a->getInfo(); };
		grupo.print(mostrar);
	}
	int getnrGrpo(){
		return numeroG;
	}
	Alumno*& getalumno(string nombre){
		auto cumplecon = [=](Alumno* al)->bool {return al->getNombre() == nombre; };
		return grupo.cumplecondicion(cumplecon);
	}
};
