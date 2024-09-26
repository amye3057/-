#include <stdio.h>

int main() {
	int arr[8] = {};
	int asc = 0;
	int des = 0;
	scanf_s("%d", &arr[0]);
	for (int i = 1; i < 8; i++) {
		scanf_s("%d", &arr[i]);
		if (arr[i] > arr[i - 1])
			asc++;
		else
			des++;
	}
	if (asc == 7)
		printf("ascending");
	else if (des == 7)
		printf("descending");
	else
		printf("mixed");

	return 0;
}