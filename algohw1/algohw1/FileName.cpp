#include <stdio.h>
#include <sys/time.h>

int foo1(int a[], int n) {
	int i, j;
	int s = 0;
	for (i = 1; i <= n; i = i + 1) {
		for (j = 0; j < i; j++)
			s += a[j];
	}
	return s;
}

int main() {
	struct timeval tstart, tfinish;
	double tsecs;
	int x[1000];
	int i;
	int r;
	printf("강예지\n"); // 본인 이름을 출력하도록 수정하시오.
	for (i = 0; i < 1000; i++)
		x[i] = i;
	gettimeofday(tstart, NULL);
	r = foo1(x, 1000);
	gettimeofday(tfinish, NULL);
	tsecs = tfinish.tv_sec - tstart.tv_sec) + 1e-6 * (tfinish.tv_usec - tstart.tv_usec);
	printf("%f\n", tsecs);
}