#include <stdio.h>

int main() {
	int max = 0;
	int people = 0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		people -= a;
		people += b;
		if (people > max)
			max = people;
	}
	printf("%d", max);
	return 0;
}