#include <stdio.h>
#include <string.h>
#define SECURE_NO_WARNINGS

int main() {
	char arr[1000001] = {};
	scanf("%[^\n]s", &arr, 1000001);
	int i = 0;
	int g = 0;
	int len = strlen(arr);

	if (len == 0) { //�ƹ��͵� �Է����� ���� ��
		printf("0");
		return 0;
	}

	while (arr[i] == ' ') { //���� ���� ����
		i++;
	}

	if (i != len) { //���� ������ �� i=len�� �ȴ�. ���� �ܾ��� ���� ��� ���߳ĸ� ������ ��+1�� ���߱⿡, ���� ������ �ƴ� �� 1�� ���ϵ��� ���־���.
		g++;
	}

	while (i < len) {
		if (arr[i] == ' ' && (arr[i + 1] == ' ' || i + 1 == len)) //���� ������ ���¿��� 1.�ڿ� �� ������ ���ų� 2.���ڿ��� ���� ��� -> �� �̻� �ڿ� ī��Ʈ ���� ����
			break;
		if (arr[i] == ' ')
			g++;
		i++;
	}
	
	printf("%d", g);
	return 0;
}