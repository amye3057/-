#include <stdio.h>
#define CRT_SECURE_NO_WANINGS

//���� ���ķ� �����ߴ��� �ð� �ʰ���. ����

void bubblesort(int array[], int n) {
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				int b = array[j + 1];
				array[j + 1] = array[j];
				array[j] = b;
			}
		}
	}
}

int main() {
	int a;
	int arr[1000000];
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &arr[i]); //���⿡ & �� �ٿ��ٰ� ��� �� �Ծ �ָ���
	}

	bubblesort(arr, a);

	for (int i = 0; i < a; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}