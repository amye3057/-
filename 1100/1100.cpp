#include <stdio.h>
int main() {

	//�ƿ쾾 �� �߸��Ѱ�.

	int i, j;
	int x = 0;
	char chess[8][8];

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			scanf_s("%c", chess[i][j]);
		}
	}

	for (i = 0; i < 8; i++) {
		if (i % 2 != 0) { //Ȧ���� ���
			for (j = 1; j < 8; j += 2) {
				if (&chess[i + 1][j] == "F")
					x += 1;
			}
		}
		else { //¦���� ���
			for (j = 2; j < 9; j += 2) {
				if (&chess[i + 1][j] == "F")
					x += 1;
			}
		}
	}

	printf("%d", x);
}