#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int registros, diferenciaHoras, diferenciaMinutos, minTotal=0, promedio;

int main(){
    scanf("%d", &registros);
    int oHora[registros], oMinuto[registros], aHora[registros], aMinuto[registros];
    for(int i=0; i<registros; i++)
        scanf("%d%*c%d%*c%d%*c%d", &oHora[i], &oMinuto[i], &aHora[i], &aMinuto[i]);
    for(int i=0; i<registros; i++){
        diferenciaHoras=aHora[i]-oHora[i];
        diferenciaMinutos=aMinuto[i]- oMinuto[i];
        minTotal+=diferenciaMinutos+diferenciaHoras*60;
    }

    promedio = minTotal/registros;
    printf("%d", promedio);

    return EXIT_SUCCESS;
}
