#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<functional>
using namespace std;
using namespace System;
template<typename T>
class Nodo {
public:
	T dato;
	Nodo<T>* next;
	Nodo<T>* back;
public:
	Nodo(T dato, Nodo<T>* next = nullptr, Nodo<T>* back = nullptr)
		:dato(dato), next(next), back(back) {}
	~Nodo() {
		this->next = nullptr;
		this->back = nullptr;
	}

	T& getdato() {return this->dato;}
};

template<class T>
class ListaDoble {
private:
	Nodo<T>* begin;
	Nodo<T>* end;
	Nodo<T>* aux;
	size_t size;
	function<bool(T)> comparar;
	function<string(T)> getInfo;
	void _InvertRecursi(Nodo<T>*& end,ListaDoble<T>& listaaux){
		if (end==nullptr){return;}
		_InvertRecursi(end->back,listaaux);
		listaaux.pushFront(end->dato);
	}
	void _rotar2() {
		end = end->back;
		end->next->next = begin;
		begin->back = end->next;
		begin = end->next;
		end->next = nullptr;
		begin->back = nullptr;
	}
	void _recursiRotar1(int cont, int cant) {
		if (cont >= cant) {
			end = aux;
			begin = aux->next;
			begin->back = nullptr;
			end->next = nullptr;
			return;
		}
		aux = aux->back;
		_recursiRotar1(++cont, cant);
	}
	void _recursiRotar2(int cont, int cant) {
		if (cont >= cant) { return; }
		_rotar2();
		_recursiRotar2(++cont, cant);
	}
public:
	ListaDoble() {
		size = 0;
		aux = begin = end = nullptr;
	}
	~ListaDoble() {
		eraseAll();
	}
	void eraseAll() {
		while (!empty()) {
			popFront();
		}
	}
	void popFront() {
		if (size <= 0) { return; }
		Nodo<T>* eliminado = begin;
		begin = begin->next;
		if (size != 1) {
			begin->back = nullptr;
		}
		eliminado->next = nullptr;
		delete eliminado;
		--size;
		if (size == 0) { begin = end = nullptr; }
		if (size == 1) { end = begin; }
	}
	void popBack() {
		if (size <= 0) { return; }
		if (size == 1) { popFront(); return; }
		Nodo<T>* eliminado = end;
		end = end->back;
		eliminado->back = nullptr;
		end->next = nullptr;
		delete eliminado;
		--size;
		if (size == 1) { end = begin; }
		if (size == 0) { end = begin = nullptr; }
	}
	T& cumplecondicion(function<bool(T)>comparar) {
		aux = begin;
		while (aux != nullptr) {
			if (comparar(aux->dato)){
				return aux->dato;
			}
			aux = aux->next;
		}
	}
	void eraseAt(int pos) {
		if (size <= 0) { return; }
		else if (pos <= 0) { popFront(); return; }
		else if (pos >= size - 1) { popBack(); return; }
		else
		{
			aux = begin;
			int cont = 0;
			while (cont++ < pos - 1) {
				aux = aux->next;
			}
			Nodo<T>* eliminado = aux->next;
			aux->next = aux->next->next;
			aux->next->back = aux;
			eliminado->next = nullptr;
			eliminado->back = nullptr;
			delete eliminado;

			/*aux->next->back = nullptr;
			aux->next->next = nullptr;
			aux->next = aux->next->next;
			delete aux->next->back;
			aux->next->back = aux;*/
			--size;
		}
	}
	void swapP(T* a, T* b) {
		T aux = *a;
		*a = *b;
		*b = aux;
	}
	void conectar() {
		begin->back = end;
		end->next = begin;
	}
	void desconectar() {
		begin->back = nullptr;
		end->next = nullptr;
	}
	void ordenar(function<bool(T, T)> comparar){
		aux = begin;
		int i = 0;
		conectar();
		while (i < size-1){
			if (comparar(aux->dato,aux->next->dato)){
				swapP(&aux->dato, &aux->next->dato);
				if (i==0){
					aux=aux->back;
					i -= 1;
				}else{
					aux=aux->back->back;
					i -= 2;
				}
			}
			i++;
			aux = aux->next;
		}
		desconectar();
	}
	T& front() {
		return begin->dato;
	}
	T& back() {
		return end->dato;
	}
	T& at(int pos) {
		aux = begin;
		if (size >= 0) {
			if (size == 1 || pos <= 0) { return this->front(); }
			else if (pos >= size - 1) { return this->back(); }
			else {
				aux = begin;
				int cont = 0;
				while (cont++ < pos){
					aux = aux->next;
				}
				return aux->dato;
			}
		}
	}
	T& operator[](size_t pos) {
		aux = begin;
		if (size >= 0) {
			if (size == 1 || pos <= 0) { return this->front(); }
			else if (pos >= size - 1) { return this->back(); }
			else {
				aux = begin;
				int cont = 0;
				while (cont++ < pos) {
					aux = aux->next;
				}
				return aux->dato;
			}
		}
	}
	void pushFront(T dato) {
		Nodo<T>* nuevo = new Nodo<T>(dato);
		if (size == 0) {
			begin = end = nuevo;
		}
		else {
			nuevo->next = begin;
			begin->back = nuevo;
			begin = nuevo;
		}
		size++;
	}
	void pushBack(T dato) {
		if (size == 0) { pushFront(dato); }
		else{
			Nodo<T>* nuevo = new Nodo<T>(dato);
			end->next = nuevo;
			nuevo->back = end;
			end = nuevo;
			size++;
		}
	}
	void insertAt(T dato, int pos) {
		if (pos <= 0) { pushFront(dato); return; }
		else if (pos >= size) { pushBack(dato); return; }
		else {
			aux = begin;
			Nodo<T>* nuevo = new Nodo<T>(dato);
			int cont = 0;
			while (cont++ < pos - 1) {
				aux = aux->next;
			}
			nuevo->next = aux->next;
			nuevo->next->back = nuevo;
			nuevo->back = aux;
			aux->next = nuevo;
			size++;
		}
	}
	void rotar1(int cant) {
		if (size <= 0 || size == 1) { return; }
		else if (cant <= 0) { return; }
		int cont = 0;
		aux = end;
		end->next = begin;
		begin->back = end;
		while (cont++ < cant) {
			aux = aux->back;
		}
		end = aux;
		begin = aux->next;
		begin->back = nullptr;
		end->next = nullptr;
	}

	void recursiRotar1(int cant) {
		if (size <= 0 || size == 1) { return; }
		else if (cant <= 0) { return; }
		int cont = 0;
		aux = end;
		end->next = begin;
		begin->back = end;
		_recursiRotar1(cont, cant);
	}

	void recursiRotar2(int cant) {
		if (size <= 0) { return; }
		else if (size == 1) { return; }
		else if (cant <= 0) { return; }
		aux = begin;
		int cont = 0;
		_recursiRotar2(cont, cant);
	}
	void rotar2(int cant) {
		if (size <= 0) { return; }
		else if (size == 1) { return; }
		else if (cant <= 0) { return; }
		aux = begin;
		int cont = 0;
		while (cont++ < cant) {
			_rotar2();
		}
	}
	void InvertRecursi(ListaDoble<T>& lista){
		aux = end;
		_InvertRecursi(aux, lista);
	}
	bool empty() {
		return (size == 0);
	}
	void print(function<void(T)> mostrar) {
		aux = begin;
		while (aux != nullptr) {
			mostrar(aux->dato);
			cout << "\n\n";
			aux = aux->next;
		}
	}
	size_t getsize() {
		return this->size;
	}
	bool search(function<bool(T)>compar) {
		aux = begin;
		bool bandera = false;
		while (aux!=nullptr){
			bandera=compar(aux->dato);
			if (bandera){
				return bandera;
			}
			aux = aux->next;
		}
		return bandera;
	}
	void modifyFront(T dato) {
		if (size <= 0) { return; }
		begin->dato = dato;
	}
	void modifyBack(T dato) {
		if (size <= 0) { return; }
		end->dato = dato;
	}
	void modifyAt(T dato, int pos) {
		if (size <= 0) { return; }
		else if (pos <= 0) { modifyFront(dato); return; }
		else if (pos >= size) { modifyBack(dato); return; }
		else {
			aux = begin;
			int cont = 0;
			while (cont++ < pos) {
				aux = aux->next;
			}
			aux->dato = dato;
		}
	}
	void filterShow(function<bool(T)>comp,function<void(T)>getInfo) {
		aux = begin;
		while (aux!=nullptr) {
			if (comp(aux->dato)) {
				getInfo(aux->dato);
			}
			aux = aux->next;
		}
		cout << "\n";
	}
	void filterList(ListaDoble<T>& lista, function<bool(T)>comp) {
		aux = begin;
		while (aux != nullptr){
			if (comp(aux->dato)){
				lista.pushBack(aux->dato);
			}
			aux = aux->next;
		}
	}
	void printWriteArch(string nombrearch,function<string(T)> getInfo) {
		ofstream arch(nombrearch);
		aux = begin;
		while (aux != nullptr) {
			arch << getInfo(aux->dato);
			aux = aux->next;
		}
		arch.close();
	}
};


