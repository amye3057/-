#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void get_data(int data[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		data[i] = rand() % 31 + 160; //160~190cm 범위
		printf("키 %d : %dcm\n", i+1, data[i]);
	}
}

int minof(const int a[], int n) {
	int min = 200;
	for (int i = 0; i < n; i++) {
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

int sumof(const int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

int main() {
	srand(time(NULL));
	int n = rand() % 16 + 5;
	printf("사람의 키 : %d개의 데이터\n", n);
	int* data = (int*)calloc(n, sizeof(int));
	get_data(data, n);

	printf("가장 작은 키는 %dcm입니다.\n", minof(data, n));
	double sum = sumof(data, n);
	double ave = sum / n;
	printf("키의 총합은 %d입니다. 평균값은 %.3f입니다.\n", sumof(data, n), ave);
	return 0;
}