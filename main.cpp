/*
  Angel Odiel Treviño Villanueva
  A01336559
  Fecha: 18/Marzo Materia: Diseño y Analisis de Algoritmos
*/

#include <iostream>
#include <climits>

using namespace std;

#define N 11

//algoritmo de Floyd
void AlgoritmoFloyd(int D[N][N], int Nodos){
  for(int k = 0; k < Nodos; k++){
    for(int i = 0; i < Nodos; i++){
      for(int j = 0; j < Nodos; j++){
        if(D[i][k] != INT_MAX && D[k][j] != INT_MAX){
          if(D[i][k] + D[k][j] < D[i][j]){
            D[i][j] = D[i][k]+D[k][j];
          }
        }
      }
    }
  }
}

//copiar las matrices
void Copiar(int First[N][N], int Second[N][N], int Nodos){
  for(int i = 0; i < Nodos; i++){
    for(int j = 0; j < Nodos; j++){
      Second[i][j] = First[i][j];
    }
  }
}

int main(){

  int Nodos; //cantidad de puntos en la ciudad
  int Calles; //cantidad de calles

  cin >> Nodos >> Calles;

  int Original[N][N]; //esta tiene los datos originales
  //iniciar la matriz
  for(int i = 0; i < Nodos; i++){
    Original[i][i] = 0;
    for(int j = i + 1; j < Nodos; j++){
      Original[j][i] = Original[i][j] = INT_MAX;
    }
  }

  // lee los arcos donde a y b son los caminos y c el valor del arco
  int a, b, c;
  for(int i = 0; i < Calles; i++){
    cin >> a >> b >> c;
    Original[a-1][b-1] = Original[b-1][a-1] = c;
  }

  int Cambios[N][N]; //la cual se guardaran la matriz original y los cambios hechos
  int Aplicacion[N][N]; //en esta se aplicara floyd
  Copiar(Original, Cambios, Nodos);

  int k; //cantidad de movimientos
  cin >> k;
  char instruccion;
  while(k > 0){
    cin >> instruccion;
    if(instruccion == 'e'){//quitamos un camino
      cin >> a >> b;
      Cambios[a-1][b-1] = Cambios[b-1][a-1] = INT_MAX;
    }else if(instruccion == 'b' || instruccion == 'l'){//cambinos se restablecen
      cin >> a >> b;
      Cambios[a-1][b-1] = Cambios[b-1][a-1] = Original[a-1][b-1];
    }else if(instruccion == 'r'){//caminos se multiplican
      cin >> a >> b;
      Cambios[a-1][b-1] = Cambios[b-1][a-1] = Cambios[a-1][b-1]*4;
    }else if(instruccion == 'q'){//imprimir caminos
      Copiar(Cambios, Aplicacion, Nodos); //para que no se pierdan los cambios despues de floyd
      AlgoritmoFloyd(Aplicacion, Nodos);
      cin >> a >> b;
      cout << Aplicacion[a-1][b-1] << endl;
    }
    k--;
  }
  return 0;
}
