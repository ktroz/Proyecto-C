#include <stdio.h>
#include <stdlib.h>
int numeros[100][2];
int divisores[20];
int numRep,contador=0;
char temporal=',';
void isPerfect(int,int);
int obtenerDivisores(int);

int main( ){
  scanf("%d",&numRep);
  for(int x=0;x<numRep;x++){
    temporal=' ';
    contador=0;
    while(temporal!='\n'){
      scanf("%d%c",&numeros[x][contador],&temporal);
      contador++;
    }
  }
  for(int x=0;x<numRep;x++){
    isPerfect(numeros[x][0],numeros[x][1]);
  }

}

void isPerfect(int inicio,int cantidad){
  int bandera,suma;
  for(int x=inicio;x<=cantidad+inicio;x++){
      bandera=obtenerDivisores(x);
      suma=0;
      for(int y=0;y<bandera;y++){
        suma+=divisores[y];
      }
      if(suma==x){
        printf("%d es perfecto\n",x);
      }else{
        printf("%d no es perfecto\n",x);
      }
  }
}
int obtenerDivisores(int numero){
  int modulos=0;
  for(int x=1;x<=numero/2;x++){
      if(numero%x==0){
        divisores[modulos]=x;
        modulos++;
      }
    }
    return modulos;
}
