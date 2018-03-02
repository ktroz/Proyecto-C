#include <stdio.h>

int convertir(int,int);

int main(){

	int W,distancia,nVehiculos;
	float t = 0;
	scanf("%d%d%d",&W,&distancia,&nVehiculos);
	int arrPeso[nVehiculos];
	int velocidad[nVehiculos];
	for (int i = 0; i < nVehiculos; ++i){
		scanf("%d%d",&arrPeso[i],&velocidad[i]);
	}
	int contador = 0, suma = 0, j = 0, menor;
	for(int i=0;i<nVehiculos;i++){
		suma += arrPeso[i];
		if (suma + arrPeso[i+1] > W)
		{
			menor = velocidad[i];
			while(j <= i){
				if (velocidad[j] < menor){
					menor = velocidad[j];
				}
				j++;
			}
			t =+ t + convertir(distancia,menor);
			suma = 0;
		}
	}
	printf("%.1f\n",t);
	return 0;
}

int convertir(int distancia,int s){
	float segundos;
	segundos=((float)distancia/(float)s)*60;
	return segundos;
}
