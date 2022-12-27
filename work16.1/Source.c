#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int find_element(double* ptr_array, int n, double element);
int delete_k(double* ptr_arr, int size, double k);

int delete_k(double* ptr_arr, int size, double k) {
	int n = size - 1;
	printf("»ндекс элемента %lf = %d\n", k, find_element(ptr_arr, size, k));
	for (int i = (find_element(ptr_arr, size, k) - 1); i < (size - 1); i++) ptr_arr[i] = ptr_arr[i + 1];
	return n;
}

int find_element(double* ptr_array, int n, double element) {
	int elementId = -1;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element) {
			elementId = i + 1;
		}
	}
	return elementId;
}

double* insert(double* ptr_arr, int* size, int index, int num) {
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
		ptr_arr[i] = ptr_arr[i - 1];
	ptr_arr[index - 2] = num;
	*size = size_n;
	return ptr_arr;
}

int main(void)
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int* ptr_array;
	int size;

	//1

	puts("¬ведите размер массива:");
	scanf("%d", &size);

	ptr_array = (int*)malloc(size * sizeof(int));
	if (ptr_array == NULL)
	{
		puts("error");
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		ptr_array[i] = -100 + rand() % (100 - -100);
		printf("a[%d] = %d\n", i, ptr_array[i]);
	}

	int count = 0;
	float summ = 0;
	for (int i = 0; i < size; i++)
	{
		printf("\nA[%d] = %d ", i, ptr_array[i]);
		if (ptr_array[i] == 0)
		{
			ptr_array[i] = count;
		}
		printf("%9.2d", ptr_array[i]);
		count += 1;
		summ += ptr_array[i];
	}
	free(ptr_array);

	//2
	double* ptr_array_2;
	int size_2;
	puts("\n\n¬ведите размер массива:");
	scanf("%d", &size_2);

	ptr_array_2 = (double*)malloc(size_2 * sizeof(double));
	if (ptr_array_2 == NULL)
	{
		puts("error");
		return -1;
	}

	for (int i = 2; i < size_2; i++)
	{
		ptr_array_2[i] = -1 + 1.f * (1 - -1) * rand() / RAND_MAX;
		printf("a[%d] = %lf\n", i, ptr_array_2[i]);
	}
	free(ptr_array_2);

	//3

	double* ptr_array_3;
	int size_3;

	printf("\n\n¬ведите размер массива:");
	scanf("%d", &size_3);

	ptr_array_3 = (double*)malloc(size_3 * sizeof(double));
	if (ptr_array_3 == NULL)
	{
		puts("error");
		return -1;
	}

	for (int i = 0; i < size_3; i++)
	{
		ptr_array_3[i] = -1 + 1.f * (1 - -1) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, ptr_array_3[i]);
	}

	double max = -1000000;
	int j;
	for (j = 0; j < size_3; j++)
	{
		if (ptr_array_3[j] > max)
		{
			max = ptr_array_3[j];
		}
	}

	double min = 1000000;
	for (j = 0; j < size_3; j++)
	{
		if (ptr_array_3[j] < min)
		{
			min = ptr_array_3[j];
		}
	}

	printf("\n\nMax = %lf; Min = %lf\n", max, min);
	delete_k(ptr_array_3, size_3, max);
	size_3--;
	delete_k(ptr_array_3, size_3, min);
	size_3--;

	puts("\n");

	for (int i = 0; i < size_3; i++) {
		printf("array[%d] = %lf\n", i, ptr_array_3[i]);
	}

	//4

	double min2 = 1000000;
	for (int i = 0; i < size_3; i++) 
	{
		if (ptr_array_3[i] < min2) 
		{
			min2 = ptr_array_3[i];
		}
	}
	printf("\n\nMin = %lf;\n", min2);
	insert(ptr_array_3, &size_3, find_element(ptr_array_3, size_3, min2), -999);

	for (int i = 0; i < size_3; i++) {
		printf("array[%d] = %lf\n", i, ptr_array_3[i]);
	}

	return 0;
}