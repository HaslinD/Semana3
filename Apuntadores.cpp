#include <iostream>

using namespace std;

int main(){
 	int arregloEstatico[5];
	
	cout << "Dir arr" << arregloEstatico<< endl;
	//apuntador de enteros
	int* apuntador = arregloEstatico;

	cout << "Dir ptr: " << apuntador<< endl;
	//inicializar
	for(int i = 0; i < 5; i++) {
		arregloEstatico[i] = i + 1;
	}
	
	cout << " Contenedor de ptr: " << endl;
	//imprimir contenido
	for(int i = 0; i < 5; i++){
		cout << apuntador[i] << endl;
	}
	
	cout << " ____________ " << endl;
	cout << *(apuntador + 4) << endl;	


	apuntador = new int[10];		
	cout << "Dir arreglo en heap: " << apuntador << endl;
	

	//liberar memoria 
	delete[] apuntador;
	
	 apuntador = NULL;	

	delete[] apuntador;
	
	//Matrices
	int** matriz;
	matriz = new int*[5];

	for(int i = 0; i < 5; i++){
		matriz[i] = new int[5];
	}

	//Poblar Matriz
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++) {
			matriz[i][j] = i * j;
		}
	}
	
	//Usar la Matriz
	for(int i = 0; i < 5; i++){
		delete[] matriz[i];	
	}

	delete[] matriz;

	//Liberar la memoria

	return 0;
}
