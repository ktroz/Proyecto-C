#include <stdio.h>
#include <stdlib.h>

int *elemento=0;
char fraseEncriptada[200],fraseDesEncriptada[200];
int filasOcupadas=0,columnasOcupadas;

int array_size();
void desencriptar(char[filasOcupadas][columnasOcupadas],int,int);
void construirMatriz(char[filasOcupadas][columnasOcupadas],int,int);


int main(){
	printf("Dame el valor de las columnas ocupadas\n");
	scanf("%d%*c",&columnasOcupadas);
	printf("Dame el mensaje que quieres descifrar\n");
	scanf("%[^\n]%*c",&fraseEncriptada);
	filasOcupadas=array_size()/columnasOcupadas;
	char matrizEncriptada[filasOcupadas][columnasOcupadas];
	construirMatriz(matrizEncriptada,filasOcupadas,columnasOcupadas);
	desencriptar(matrizEncriptada,filasOcupadas,columnasOcupadas);
	puts(fraseDesEncriptada);
	return EXIT_SUCCESS;
}


void desencriptar(char matriz[filasOcupadas][columnasOcupadas],int fila,int columna){
	int contador=0;
	int elemento=0;
	int menor=0;
	menor=(fila<columna)?fila:columna;
	for(int reng=0;reng<menor;reng++){
			for(int col=0;col<reng;col++){
					fraseDesEncriptada[elemento]=matriz[col][reng-col];
					elemento++;
			}
			contador++;
		}
		if(fila==columna)
			menor=0;
		if(fila>columna){
			for(int diagonal=menor;diagonal<fila;diagonal++){
				for(int col=menor;col<diagonal;col++){
					fraseDesEncriptada[elemento]=matriz[contador-col][col];
					elemento++;
				}
				contador++;
			}
		}else if(columna>fila){
			for(int diagonal=menor;diagonal<columna;diagonal++){
				for(int col=0;col<=contador;col++){
					fraseDesEncriptada[elemento]=matriz[col][contador-col];
				}
				contador++;
			}
		}
		if(columna>fila){
			for(int reng=contador-fila+1;reng>=fila;reng++)
				for(int col=reng;col>=fila;col--){
					fraseDesEncriptada[elemento]=matriz[reng][col];
					elemento++;
				}
		}else if(columna<fila){
			for(int reng=contador-columna;reng>=fila;reng++)
				for(int col=reng-1;col>=fila;col--){
					fraseDesEncriptada[elemento]=matriz[reng][col];
					elemento++;
				}
		}

}
void construirMatriz(char matriz[filasOcupadas][columnasOcupadas],int filas,int columnas){
	int cont=0;
	for(int f=0;f<filas;f++){
		for(int reng=0;reng<columnas;reng++){
			matriz[f][reng]=fraseEncriptada[cont];
		}
	}

}
int array_size(){
  int cont=0;
  while(fraseEncriptada[cont]!='\0'){
    cont++;
  }
  return cont;
}
