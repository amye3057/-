#include <stdio.h>
int main() {
	int n;
	int a[1000000] = {};
	int b, c;
	long long int sum; // ����� �� �Ǵµ� ���� ������ �ֳ� �ߴ���, �ʹ� ū ������ �ԷµǾ sum�� ũ�Ⱑ Ŀ���鼭 �����÷ο찡 ��. sum�� �ڷ����� �ٲ��ְ� ��µ� %lld�� �ٲٴ� ����.

	scanf_s("%d", &n);
	sum = n; // �Ѱ������� ������ �Ѹ��� �ʿ���
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d %d", &b, &c);

	for (int i = 0; i < n; i++) {
		a[i] -= b; // �Ѱ������� ������ �Ѹ��� �ʿ���
		if (a[i] <= 0) // a[i]�� 0���� �۾��� ��Ȳ�� ������� �ʰ� a[i]==0 ���� ������ �ξ Ʋ����.
			continue; // ���⸦ break�� �־ for���� n�� ���ƾ��ϴµ� ��� ������ �������Դ� �ſ���.
		if (a[i] < c) {
			sum++;
		}
		else {
			sum += a[i] / c;
			if (a[i] % c != 0)
				sum++;
		}
	}
	printf("%lld", sum);
	return 0;
}