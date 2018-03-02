#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char palabra[100];
int vocales[10][5];
void toLowChar();
void countVocals(int numPalabra);
int main(){
  char letraTemporal='a';
  int numPalabra=0;
  while(palabra[0]!='#'){
    scanf("%[^\n]",palabra);
    toLowChar();
    countVocals(numPalabra);
    numPalabra++;
  }


  return EXIT_SUCCESS;
}



void toLowChar(){
  int cont=0;
  while(palabra[cont]!='\0'){
    if(palabra[cont]>=65&&palabra[cont]<=90)
      palabra[cont]-=32;
    cont++;
  }
}
void countVocals(int numPalabra){
  vocales[numPalabra][0]=0;
  vocales[numPalabra][1]=0;
  vocales[numPalabra][2]=0;
  vocales[numPalabra][3]=0;
  vocales[numPalabra][4]=0;
  int cont=0;
  while(palabra[cont]!='\0'){
    if(palabra[cont]==97){
      vocales[numPalabra][0]+=1;
    }else if(palabra[cont]==101){
      vocales[numPalabra][1]+=1;
    }else if(palabra[cont]==105){
      vocales[numPalabra][2]+=1;
    }else if(palabra[cont]==111){
      vocales[numPalabra][3]+=1;
    }else if(palabra[cont]==117){
      vocales[numPalabra][4]+=1;
    }
    cont++;
  }
}
