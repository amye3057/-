#include <stdio.h>

void f(int fi[], int n) {
	if (n == 0) {
		fi[n] = 1;
	}
	else if (n == 1) {
		fi[0] = fi[1] = 1;
	}
	else {
		f(fi, n - 1);
		fi[n] = fi[n - 1] + fi[n - 2];
	}
}

int main() {
	int fi[100];
	f(fi, 5);
	printf("%d", fi[5]);
}