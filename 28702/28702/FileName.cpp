#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char a[9] = {};
	char b[9] = {};
	char c[9] = {};
	int d;
	scanf("%s", &a);
	scanf("%s", &b);
	scanf("%s", &c);
	printf("%s %s %s", a, b, c); //Ȯ�ο�
	
	if (c == "Fizz" || c == "Buzz" || c == "FizzBuzz") { // ���⿡ ������ FizzBuzz �̰� ��.. �갡 �ν��� ������.
		if (b == "Fizz" || b == "Buzz" || b == "FizzBuzz") {
			if (a == "Fizz" || a == "Buzz" || a == "FizzBuzz") { // a�� ������ ���
				d = atoi(a) + 3;
			}
			else {
				// 3���� ���ӵ� ���ڿ��� ��� ������ ���. (�� ��..�� �ʰ���? �� ���� �ϴ� �̷��� �ص�)
			}
		}
		else { // b�� ������ ���
			d = atoi(b) + 2;
			printf("d = %d\n", d); //Ȯ�ο�
		}
	}
	else { // c�� ������ ���
		printf("c ���� �� �̷��� %s\n", c); // Ȯ�ο�
		// c+1�� ������ ����ϵ���.
		d = atoi(c) + 1;
		printf("d = %d\n", d); //Ȯ�ο�
	}

	if (d % 3 == 0) {
		if (d % 5 == 0)
			printf("FizzBuzz");
		else
			printf("Fizz");
	}
	else if (d % 5 == 0) {
		printf("Buzz");
	}
	else
		printf("%d", d);

	return 0;
}