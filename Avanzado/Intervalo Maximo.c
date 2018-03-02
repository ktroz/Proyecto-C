#include <stdio.h>
#include <stdlib.h>
int numeros[10][20];
int intervalos[10];
int numRep,contador=0;
char temporal=',';
void comprobarIntervalo(int);

int main(){
  scanf("%d",&numRep);
  for(int x=0;x<numRep;x++){
    temporal=',';
    contador=0;
    while(temporal!='\n'){
      scanf("%d%c",&numeros[x][contador],&temporal);
      contador++;
    }
    intervalos[x]=contador;
  }
  for(int y=0;y<numRep;y++)
      comprobarIntervalo(y);
  return EXIT_SUCCESS;
}

void comprobarIntervalo(int numArreglo){
  int maximo=numeros[numArreglo][0],suma,inicio=0,final=0;
  suma=0;
  for(int x=0;x<intervalos[numArreglo];x++){
    for(int y=x;y<intervalos[numArreglo];y++){
      suma+=numeros[numArreglo][y];
      if(suma>maximo){
        inicio=x;
        final=y;
        maximo=suma;
      }
    }
    suma=0;
  }
  printf("%d-%d:%d\n",inicio,final,maximo);
}
