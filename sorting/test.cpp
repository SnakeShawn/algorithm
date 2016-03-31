#include<stdio.h>
#include "sorting.h"

int main(){
	printf("Starting...\n");
	int size = 10;
	int array[10] = {1,2,1,3,4,5,9,7,8,1};
	//BubbleSort(array, size);
	//ExchangeSort(array, size);
	//SelectSort(array, size);
	InsertSort(array, size);
	for (int i=0; i<size; i++){
		printf("%d\n", array[i]);
	}
	return 0;
}

