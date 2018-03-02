#include <stdio.h>
#include <stdlib.h>

void cifrarPalabra(int,int);
char ruleta(int,int,char,int);
char frasesIndividuales[10][200];
int key[10];

int main(){
	int bandera=1,cont=0,contFrase=0;
	while(bandera!=0){
		bandera=scanf("%d%*c%[^\n]%*c", &key[cont],&frasesIndividuales[cont][0]);
		cont++;
	}
	for(int frase=0;frase<cont;frase++){
		cifrarPalabra(key[frase],frase);
	}
	for(int frase=0;frase<cont;frase++){
		contFrase=0;
		while(frasesIndividuales[frase][contFrase]!='\0'){
			printf("%c",frasesIndividuales[frase][contFrase]);
			contFrase++;
		}
		printf("\n");
	}


	return EXIT_SUCCESS;
}
void cifrarPalabra(int rango,int fraseActual){
	char caracterTemporal;
	int caracterActual=0;
	int recorridoMayus=rango/26;
	recorridoMayus=rango-recorridoMayus*26;
	int recorridoMinus=rango/26;
	recorridoMinus=rango-recorridoMinus*26;
	int recorridoNum=rango/10;
	recorridoNum=rango-recorridoNum*10;
	while(frasesIndividuales[fraseActual][caracterActual]!='\0'){
		if(frasesIndividuales[fraseActual][caracterActual]>64 && frasesIndividuales[fraseActual][caracterActual]<91){
			caracterTemporal=frasesIndividuales[fraseActual][caracterActual];
			frasesIndividuales[fraseActual][caracterActual]=ruleta(65,91,caracterTemporal,recorridoMayus);
		}else if(frasesIndividuales[fraseActual][caracterActual]>96 && frasesIndividuales[fraseActual][caracterActual]<123){
			caracterTemporal=frasesIndividuales[fraseActual][caracterActual];
			frasesIndividuales[fraseActual][caracterActual]=ruleta(97,123,caracterTemporal,recorridoMinus);
		}else if(frasesIndividuales[fraseActual][caracterActual]>47 && frasesIndividuales[fraseActual][caracterActual]<58){
			caracterTemporal=frasesIndividuales[fraseActual][caracterActual];
			frasesIndividuales[fraseActual][caracterActual]=ruleta(48,58,caracterTemporal,recorridoNum);
		}
		caracterActual++;
	}
}
char ruleta(int vInicio, int vFinal,char numActual,int recorrido){
	if(recorrido<0){
		for(int x=-recorrido;x>0;x--){
			numActual--;
			if(numActual<vInicio)
				numActual=vFinal-1;
		}
	}else if(recorrido>0){
		for(int x=0;x<recorrido;x++){
			numActual++;
			if(numActual>=vFinal-1)
				numActual=vInicio;
		}
	}
	return numActual;
}
