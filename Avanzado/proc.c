#include <stdio.h>
#include <stdlib.h>

int main(){

	int repeticionPrograma;
	scanf("%d", &repeticionPrograma);
	int contador = 0;
	while(contador<repeticionPrograma){
		int renglones, columnas;
		scanf("%d%d", &renglones,&columnas);
		int matrizSecundaria[renglones][columnas];
		for(int i = 0; i < renglones; i++)
			for(int j = 0; j < columnas; j++){
				scanf("%d",&matrizSecundaria[i][j]);
			}

		int miMatrizReng, miMatrizCol;
		scanf("%d%d",&miMatrizReng, &miMatrizCol);
		int matrizPrincipal[miMatrizReng][miMatrizCol];
		for(int i = 0; i < miMatrizReng; i++)
			for(int j = 0; j < miMatrizCol; j++){
				scanf("%d",&matrizPrincipal[i][j]);
			}

		//Inicia el recorrido de la matriz
		for(int i = 0; i < miMatrizReng - renglones + 1; i++)
			for(int j = 0; j < miMatrizCol - columnas + 1; j++){
				if (matrizPrincipal[i][j] == matrizSecundaria[0][0]){
					int bandera = 1;
					for(int x = 0; x < renglones && bandera==1; x++){
						for(int y = 0; y < columnas; y++){
							if(matrizSecundaria[x][y] != matrizPrincipal[i + x][j + y]){
								bandera = 0;
							}
					}
				}
				if( bandera == 1 ){
					for( int m = 0; m < renglones; m++ )
						for( int n = 0; n < columnas; n++ ){
							if( matrizPrincipal[i + m][j + n] == 1 )
								matrizPrincipal[ i + m][ j + n ] = 2;
							else
								matrizPrincipal[i + m ][ j + n ] = -1;
						}
				}
			}
		}

		puts("");
		for(int i = 0; i < miMatrizReng; i++){
			for(int j = 0; j < miMatrizCol; j++){
				if(matrizPrincipal[i][j]==-1)
					printf("* ");
				else
					printf("%d ",matrizPrincipal[i][j]);
			}
			puts("");
		}
		puts("");
		contador++;
	}
	return EXIT_SUCCESS;
}
