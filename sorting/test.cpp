#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "sorting.h"

#define N 100000
#define Demo 0
#define COMPARE 1

void GenerateArray(int array[], int n)
{
	int i;
	srand((unsigned)time(0));

	for (i=0; i<n; i++){
		array[i] = rand();		//0-32767
	}
}

void PrintArray(int array[], int n)
{
	int i=0;
	for (i=0; i<n; i++){
		printf("%6d\t", array[i]);
	}
	printf("\n");
}

int main()
{
	printf("Starting...\n");
	int size = N;
	//int array[N] = {1,2,1,3,4,5,9,7,8,1};
	int array[N];
	GenerateArray(array, size);
#if COMPARE
	#if Demo
	printf("Before sorting--------\t");
	PrintArray(array, size);
	#endif
	clock_t start_bubble = clock();
	BubbleSort(array, size);
	clock_t end_bubble = clock();
	printf("Bubble:Running time is %lf ms\n", (double)(end_bubble-start_bubble)/CLOCKS_PER_SEC*1000);
	
	printf("---------------------------------------------------------\n");
	sleep(1);
	GenerateArray(array, size);
	clock_t start_exchange = clock();
	ExchangeSort(array, size);
	clock_t end_exchange = clock();
	printf("Exchange:Running time is %lf ms\n", (double)(end_exchange-start_exchange)/CLOCKS_PER_SEC*1000);

	printf("---------------------------------------------------------\n");
	sleep(1);
	GenerateArray(array, size);
	clock_t start_select = clock();
	SelectSort(array, size);
	clock_t end_select = clock();
	printf("Select:Running time is %lf ms\n", (double)(end_select-start_select)/CLOCKS_PER_SEC*1000);
	
	printf("---------------------------------------------------------\n");
	sleep(1);
	GenerateArray(array, size);
	clock_t start_insert = clock();
	InsertSort(array, size);
	clock_t end_insert = clock();
	printf("Insert:Running time is %lf ms\n", (double)(end_insert-start_insert)/CLOCKS_PER_SEC*1000);

	printf("---------------------------------------------------------\n");
	sleep(1);
	GenerateArray(array, size);
	clock_t start_shell = clock();
	ShellSort(array, size);
	clock_t end_shell = clock();
	printf("Shell:Running time is %lf ms\n", (double)(end_shell-start_shell)/CLOCKS_PER_SEC*1000);

	printf("---------------------------------------------------------\n");
	sleep(1);
	GenerateArray(array, size);
	clock_t start_quick = clock();
	QuickSort(array, size);
	clock_t end_quick = clock();
	printf("Quick:Running time is %lf ms\n", (double)(end_quick-start_quick)/CLOCKS_PER_SEC*1000);
#endif

	//PrintArray(array, size);

	return 0;
}

