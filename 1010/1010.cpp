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
	//여기서 모르겠는데?? 겹치지 않으면서 되도록.. 머리가 안 돌아가서 일단 나중에
}