#include <stdio.h>

int main() {
	int a, b; // a�� ������ ������� ���� ��. a�� b����ŭ ������ ġŲ 1���� ȹ�� ����
	while (scanf_s("%d %d", &a, &b) != EOF) {
		int chicken = 0;

		chicken += a;

		 do {
			chicken += a / b;
			a = a / b + a % b;
		 } while (a >= b); // �� �̻� ġŲ������ ���� �� ���� ������. (ó���� a / b >= b�� ������ �־��༭ Ʋ��)
		 chicken += a / b; // a/b < b�� ��� ������ ���������µ� �̶� ���������� �� �� �� ���������
		printf("%d\n", chicken);
	}
}