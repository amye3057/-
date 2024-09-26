#include <stdio.h>
int jaritsu(int n);

int main() {
	int n;
	int J; // �Է¹��� ���� �ڸ���
	scanf_s("%d", &n);
	J = jaritsu(n);
	int output = 0;

	int J10 = 1; // 10�� J-1��. (ex. 3�ڸ� ���� 10�� 2��)
	for (int i = 0; i < J-1; i++) {
		J10 *= 10;
	}

	//printf("J10:%d, J:%d\n", J10, J);

	/*3�ڸ� ���� ���� �����ڰ� �Ƿ��� �����տ��� 1~27�� �� ���̿� ����. (1~9*3)
      2�ڸ� ���� 1~18�� �� ����.  (1~9*2)
      �� �ϴ� �ڸ����� ���Ѵ���, �ڸ����� �°� ���� ������ ������ �� �ִ�. -> ������ n-9*J�� �� ����.*/

	for (int i = n - 9 * J; i < n; i++) {
		int sum = i;
		int j10 = J10;
		int k = i; // ������ �ڱ��ڽ��� ���ϱ� ������ sum���� �̸� �ڱ��ڽ��� ���ϴ� ������ ����.
		while (k != 0) {
			sum += k / j10;
			k %= j10;
			j10 /= 10;
			//printf("sum:%d, k:%d, J10:%d\n", sum, k, j10);
		}
		if (sum == n) {
			output = i;
			break;
		}
	}

	printf("%d", output); 
	return 0;
}

int jaritsu(int n) {
	int j = 0;
	while (n != 0) {
		n /= 10;
		j++;
	}
	return j;
}