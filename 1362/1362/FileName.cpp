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
		if (nw == 0) // 0 0�� �Էµ� ��� ����.
			break;
		while (1) {
			scanf("%c %d", &a, &b);
			//printf("nw = %d, w = %d, a = %c, b = %d\n", nw, w, a, b); // Ȯ�ο�
			if (a == '#')
				break;
			else if (a == 'F') {
				w += b;
				printf("���� : %d\n", w); // Ȯ�ο�
			}
			else if (a == 'E') {
				w -= b;
				printf("���� : %d\n", w); // Ȯ�ο�
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