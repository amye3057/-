#include <stdio.h>
#include <stdlib.h>
#define size 100

int sum(char a[]) {
	int s = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] > 47 && a[i] < 58) { //���ڿ� �� ���ڿ� �ش��ϴ� �ƽ�Ű�ڵ尡 ���ý�
			int j = 0;
			char n[10] = {}; //����Ǵ� ������ ���̰� 10�� ���� �ʴ´ٰ� ����.
			do {
				n[j] = a[i];
				j++;
				i++;
			} while (a[i] > 47 && a[i] < 58); //�װ� ������ ������ ����
			s += atoi(n); //n ����ȯ �� ����ȭ ���Ѽ� s�� ���ϱ�.
		}
		
	}
	return s;
}

int main() {
	char a[size] = {};
	printf("Input a string: ");
	scanf_s("%s", a, size);
	int s = sum(a);
	printf(" -> %d", s);
	return 0;
}