#include <stdio.h>

int main() {

	int T;
	scanf("%d", &T);
	int i, m, n;
	int arr[1000];
	for (i = 0; i < T; i++) {
		scanf("%d %d", &n, &m);
		arr[i] = num_of_cases(n, m);
	}

	for (i = 0; i < T; i++) {
		printf("%d", arr[i]);
	}

}

int num_of_cases(int n, int m) {
	//���⼭ �𸣰ڴµ�?? ��ġ�� �����鼭 �ǵ���.. �Ӹ��� �� ���ư��� �ϴ� ���߿�
}