#include <stdio.h>
int jaritsu(int n);

int main() {
	int n;
	int J; // 입력받은 수의 자릿수
	scanf_s("%d", &n);
	J = jaritsu(n);
	int output = 0;

	int J10 = 1; // 10의 J-1승. (ex. 3자리 수면 10의 2승)
	for (int i = 0; i < J-1; i++) {
		J10 *= 10;
	}

	//printf("J10:%d, J:%d\n", J10, J);

	/*3자리 수면 대충 생성자가 되려면 분해합에서 1~27를 뺀 사이에 들어간다. (1~9*3)
      2자리 수면 1~18을 뺀 사이.  (1~9*2)
      즉 일단 자릿수를 구한다음, 자릿수에 맞게 시작 지점을 정해줄 수 있다. -> 시작을 n-9*J로 한 이유.*/

	for (int i = n - 9 * J; i < n; i++) {
		int sum = i;
		int j10 = J10;
		int k = i; // 어차피 자기자신을 더하기 때문에 sum에다 미리 자기자신을 더하는 것으로 시작.
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