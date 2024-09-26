#include <stdio.h>

int main() {
	int t;
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		int price;
		scanf_s("%d", &price);

		int option;
		scanf_s("%d", &option);
		
		for (int j = 0; j < option; j++) {
			int a, b;
			scanf_s("%d %d", &a, &b);
			price += a * b;
		}
		printf("%d\n", price);
	}
	return 0;
}