#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define dead -1

int main() {
	int nw, w; // normal weight, weight
	char a;
	int b;
	int pet_status;
	int i = 1;
	while(1){
		pet_status = 0;
		scanf("%d %d", &nw, &w);
		if (nw == 0) // 0 0이 입력될 경우 종료.
			break;
		while (1) {
			scanf("%c %d", &a, &b);
			//printf("nw = %d, w = %d, a = %c, b = %d\n", nw, w, a, b); // 확인용
			if (a == '#')
				break;
			else if (a == 'F') {
				w += b;
				printf("무게 : %d\n", w); // 확인용
			}
			else if (a == 'E') {
				w -= b;
				printf("무게 : %d\n", w); // 확인용
			}

			if (w <= 0)
				pet_status = dead;

		};

		if (pet_status == dead) {
			printf("%d RIP\n", i);
		}
		else if (w > nw / 2 && w < nw * 2) { // happy
			printf("%d :-)\n", i);
		}
		else // sad
			printf("%d :-(\n", i);

		i++;
	}
	return 0;
}