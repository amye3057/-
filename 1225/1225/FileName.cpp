#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char arr[100000] = {};
	char brr[100000] = {};
	long long sum = 0;

	scanf("%s", &arr);
	scanf("%s", &brr);

	for (int i = 0; i < strlen(arr); i++) {
		for (int j = 0; j < strlen(brr); j++) {
			sum += (arr[i]-'0') * (brr[j] - '0'); // atoi�� ������ �ߴµ� char�� �ƴ� *char�� ����ȯ��Ű�� ���̾���. �׷��� �迭�� �� �κи� ����ȯ�ϴ� ����� ã�ƺ��� �̷� �� �־���.
			/* ������ �ƽ�Ű ���� 48������ 0~9�� �Ҵ��ϰ� �����Ƿ�, char�� '1'�� ������ 49�� ������.
			���� 0�� �ƽ�Ű ���� 48�� char���� ������ ���ָ� ������ ���ڸ� �� �� �ִ�. �ٵ� -48�� ������ �ڵ带 �б� �����. (���ڱ� 48�� �� ����? �̷��� �Ǵϱ�)
			�׷��� �׳� '0'�� ���ذŴ�. */
		}
	}
	printf("%lld", sum);
	return 0;
}