#include<stdio.h>
#include "sorting.h"

void swap(int & a, int & b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//冒泡排序
void BubbleSort(int array[], const int size)
{
	for (int i=0; i<size; i++){
		for (int j=size-1; j>=i; j--){
			if (array[j]<array[j-1])
				swap(array[j], array[j-1]);
		}
	}
}

//选择排序
void ExchangeSort(int array[], const int size)
{
	for (int i=0; i<size; i++){
		for (int j=i+1; j<size; j++){
			if (array[i]>array[j])
				swap(array[i], array[j]);
		}
	}
}

//选择排序
void SelectSort(int array[], const int size)
{
	for (int i=0; i<size; i++){
		int temp = array[i];
		int	pos = i;
		for (int j=i+1; j<size; j++){
			if (temp>array[j]){
				temp = array[j];
				pos = j;
			}
		}
		array[pos] = array[i];
		array[i] = temp;
	}
}

//插入排序
void InsertSort(int array[], const int size)
{
	int temp;
	int pos;
	for (int i=1; i<size; i++){
		temp = array[i];
		pos = i-1;
		while ((pos>=0) && (temp<array[pos])){
			array[pos+1] = array[pos];
			pos = pos - 1;
		}
		array[pos+1] = temp;
	}
}

//希尔排序
void ShellSort(int array[], const int size)
{
	int increment = size/2;
	while (increment>=1){

		for (int i=increment; i<size; i++){
			if (array[i] < array[i-increment]){
				int guard = array[i];
				int j;
				for (j=i-increment;(j>=0)&&(guard<array[j]);j-=increment){
					array[j+increment] = array[j];
				}
				array[j+increment] = guard;
			}
		}
		increment = increment/2;
	}
}

//快速排序
void QuickSort(int array[], const int size)
{	
	if (size <= 1)
		return;
	int key = array[0];
	int i = 0;
	int j = size -1;
	int index = 0;
	while (i < j){
		while (j>i && array[j]>=key)
			j--;
		if (i == j)
			break;
		else{
			swap(array[i], array[j]);
			index = j;
		}
		while (i<j && array[i]<=key)
			i++;
		if (i == j)
			break;
		else{
			swap(array[i], array[j]);
			index = i;
		}
	}
	QuickSort(array, index);
	QuickSort(array + index + 1, size - 1 - index);
}

