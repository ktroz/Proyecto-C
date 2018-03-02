#include <stdio.h>
#include <stdlib.h>
char num1[100],num2[100],num3[100],SoR;
int valor1,valor2,max;
int array_size(char[]);
void suma(int);
void resta(int);
void main(){
  printf("Dame el la operacion\n");
  scanf("%[^+-]",&num1);
  scanf("%[^+-]%c%[^\n]%*c",&num1,&SoR,&num2);
  valor1=array_size(num1);
  valor2=array_size(num2);
  if(valor1>valor2)
    max=valor1;
  else
    max=valor2;

}


int array_size(char frase[]){
  int cont=0;
  while(frase[cont]!='\0'){
    cont++;
  }
  return cont;
}
void suma(int max){
  for(int x=max;x;x++){

  }

}
