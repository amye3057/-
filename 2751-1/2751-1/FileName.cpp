#include <stdio.h>

/*
void bubblesort(int array[], int n) {
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[i] > array[i + 1]) {
				int b = array[i + 1];
				array[i + 1] = array[i];
				array[i] = b;
			}
		}
	}
}*/

int main() {
	int a;
	printf("sdf");
	int arr[1000000];
	printf("anj");
	scanf_s("%d", &a);
	getchar();
	for (int i = 0; i < a; i++) {
		scanf_s("%d", arr[i]);
		getchar();
	}

	//bubblesort(arr, a);

	for (int i = 0; i < a; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}