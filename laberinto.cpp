// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//funcion crea una matriz n x n
char** createMatrix(int);

// funcion libera la memoria asignada a una matriz n x n
void freeMatrix(int, char**);

//imprime matriz en la consola
void prinMatrix(int, char**);

int main (int argc, char* argv[]) {
  char letra;
  int size;
  char** matrix;
  ifstream myfile (argv[1]);
  if (myfile.is_open())
  {
    int cont=0;


    //TODO: Leer el tama�o de la matriz e iniciarlizarla
    myfile >> size;
	
    matrix =  createMatrix(size);
    
    //leer la matriz que contiene el laberinto     
    for(int i = 0; i < size; i++) {
	for(int j = 0; j < size; j++) {
		myfile >> matrix[i][j];
	}
    }


    /*while ( !myfile.eof() )
    {
      myfile >> letra;
      cout<<" "<<letra;
      if(cont == 9){
         cout<<endl;
         cont=0;
      }else
          cont++;

	//TODO:Llenar la matriz
      
    }*/

    myfile.close();
  }

  else cout << "El archivo no existe"; 
  
  //Imprimir Laberinto
  prinMatrix(size, matrix);

  //TODO: llamar funci�n SalirLaberinto

  //Liberar Memoria
  freeMatrix(size, matrix);
  return 0;
}

void prinMatrix(int size, char** matrix){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++) {
			 cout << "  " << matrix[i][j];
		}
		cout << endl; 
	}
}

char** createMatrix(int n){
	char** retVal = new char*[n];

	for(int i = 0; i < n; i++) {
		retVal[i] = new char[n];

	}
	return retVal;

}

void freeMatrix(int n, char** matrix){
	for(int i = 0; i < n; i++){
		delete[] matrix[i];
	}
	
	delete[] matrix;
}
