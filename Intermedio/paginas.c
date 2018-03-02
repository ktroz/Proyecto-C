#include <stdio.h>
#include <stdlib.h>
int numsPag(int);

int main(){
	int rp;
	scanf("%d",&rp);
  int nd[rp];
	for(int i=0; i<rp;i++){
		scanf("%ld",&nd[i]);
	}
	for(int i=0; i<rp;i++){
		if((numsPag(nd[i]))==0)
			printf("imposible\n");
		else{
      printf("%d\n",numsPag(nd[i]));
    }
	}
	return EXIT_SUCCESS;
}

int numsPag(int nd){
	int paginas=0;
	printf("%d\n",nd);
	if(nd%2==0){
		return 0;
	}
	for (int i=1;i<=nd;i++){
		if(i<=9){
			paginas=paginas+1;
		}
	}
	int sum=(nd-9)/2;
	return paginas+sum;
}
