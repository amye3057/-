#include <stdio.h>
#include <string.h>

int main() {
	char a[250] = {};
	char b[10000] = {};
	int c[10000] = {};
	while (1) {
		scanf_s("%[^\n]s", a, 250);
		if (strcmp(a,"#"))
			break;
		for (int i = 0; i < sizeof(a); i++) { //�Է¹��� ���ڿ��� ũ�⸦ �� �� �ִ� ����� ����
		
		}
	}
}