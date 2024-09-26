#include <stdio.h>

void shell_sort(int arr[], int n) { //n=5라고 칠때
	int k, v;
	for (int h = n / 2; h > 0; h /= 2) { //첫번째 h=2
		for (int i = 0; i < h; i++) { //첫번째 i=0,1
			for (int j = i + h; j < n; j += h) { //첫번째 j=2,4
				v = arr[j]; //첫번째 arr[2], arr[4]의 값
				k = j; //첫번째 2,4 저장
				while (k > h - 1 && arr[k - h] > v) { //2>1(k=h-1이 될 경우를 방지하기 위해서 들어간거) && arr[2-2]>arr[2] (앞에 있는 값이 뒤에 있는 값보다 클 경우 값 교환)
					arr[k] = arr[k - h]; //arr[2] = arr[2-2]
					k -= h; //k = 2-2 = 0
				}
				arr[k] = v; //arr[0]=v(본래 arr[2]값)
			}
		}
	}
}
//어렵다 걍 자주 작성해봐야할듯

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