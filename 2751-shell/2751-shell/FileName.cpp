#include <stdio.h>

void shell_sort(int arr[], int n) { //n=5��� ĥ��
	int k, v;
	for (int h = n / 2; h > 0; h /= 2) { //ù��° h=2
		for (int i = 0; i < h; i++) { //ù��° i=0,1
			for (int j = i + h; j < n; j += h) { //ù��° j=2,4
				v = arr[j]; //ù��° arr[2], arr[4]�� ��
				k = j; //ù��° 2,4 ����
				while (k > h - 1 && arr[k - h] > v) { //2>1(k=h-1�� �� ��츦 �����ϱ� ���ؼ� ����) && arr[2-2]>arr[2] (�տ� �ִ� ���� �ڿ� �ִ� ������ Ŭ ��� �� ��ȯ)
					arr[k] = arr[k - h]; //arr[2] = arr[2-2]
					k -= h; //k = 2-2 = 0
				}
				arr[k] = v; //arr[0]=v(���� arr[2]��)
			}
		}
	}
}
//��ƴ� �� ���� �ۼ��غ����ҵ�

int main() {
	int a;
	int arr[1000000];
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &arr[i]);
	}

	shell_sort(arr, a);
	for (int i = 0; i < a; i++) {
		printf("%d\n", arr[i]);
	}
}