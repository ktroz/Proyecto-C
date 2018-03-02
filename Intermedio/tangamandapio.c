#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tangadec(int);
int nums[10];
char idiomaRaro[10][20];
int index[20];

int main(){

	char input='.';

	int contador = 0, tamanio = 0;
	int numerosDecimales[20];
	while(input!='#'){
		scanf("%c", &input);
		if(input == '\n'){
			index[contador] = tamanio;
			contador++;
			tamanio = 0;
		}else{
			idiomaRaro[contador][tamanio] = input;
			tamanio++;
		}
	}

	for(int i=0; i<contador; i++)
		for(int j=0; j<index[i]; j++){
			numerosDecimales[j]=tangadec(idiomaRaro[i][j]);
			nums[i]=nums[i]+numerosDecimales[j]*pow(6, index[i]-j-1);
		}
	for(int i=0; i<contador; i++)
		printf("\n%d", nums[i]);
	return EXIT_SUCCESS;

}

int tangadec(int a){
	if(a==41)
		return 1;
	else if(a==126)
		return 2;
	else if(a==64)
		return 3;
	else if(a==63)
		return 4;
	else if(a==92)
		return 5;
	else if(a==36)
		return -1;
	else
		return 0;
}
