#include <stdio.h>
#include <stdlib.h>

void rotarDerecha(int[]);
int matriz[]={0,1,2,3,4,5,6,7,8,9};
int main() {
  int rep;
  printf("Cuantas veces quieres que se ejecute la funcion rotar?\n");
  scanf("%d",&rep);
  for(int x=0;x<rep;x++)
    rotarDerecha(matriz);

  return EXIT_SUCCESS;
}
void rotarDerecha(int matriz[]){
  int temporal=matriz[9];
  for(int x = 9; x >0 ; x--) {
    matriz[x]=matriz[x-1];
  }
  matriz[0]=temporal;
  for (int x = 0; x < 10; x++) {
    printf("%d",matriz[x]);
  }
  printf("\n");
}
