#include <stdio.h>

int main(){
	printf("\nStarting\n");
	int N = 10000;
	int array[N];
	printf("Loading...\n");
	for(int i=1; i<=N; i++){
		array[i] = i;	
	}
	for(int j=1;j<N;j++){
		array[j]+= 10;
	}
	printf("Finished\n");
	return 0;
}
