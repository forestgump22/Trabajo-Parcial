#pragma once
template<typename T>
class MVector {
private:
	int sizemin;
	T* arr;
public:
	MVector(){
		this->sizemin = 0;
		arr = new T[this->sizemin];
	}
	T at(int i) {
		return arr[i];
	}
	~MVector() {
		for (int i = 0; i < sizemini(); i++) {
			this->erase(i);
		}
		delete[] arr;
	}
	void resize(int size,T obj) {
		for (int i = 0; i < size; i++)
		{
			push_backMini(obj);
		}
	}
	void push_backMini(T obj) {
		T* aux = new T[sizemin + 1];
		for (int i = 0; i < sizemin; i++) {
			aux[i] = arr[i];
		}
		aux[sizemin] = obj;
		delete arr;
		arr = aux;
		++sizemin;
		aux = nullptr;
		delete aux;
	}
	int	sizemini() {
		return sizemin;
	}
	
	int begin() {
		return 0;
	}
	void erase(int pos) {
		if (sizemin > 0 && pos < sizemin && pos >= 0) {
			T* aux = new T[sizemin - 1];
			for (int i = 0; i < sizemin - 1; i++) {
				if (i < pos) {
					aux[i] = arr[i];
				}
				else {
					aux[i] = arr[i + 1];
				}
			}
			delete arr;
			arr = aux;
			--sizemin;
			aux = nullptr;
			delete aux;
		}
		else { return; }
	}
};
