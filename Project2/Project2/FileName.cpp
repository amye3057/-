#include <stdio.h>

int sumRaw(int* a, int b, int c) {
	int ans = 0;
	int d = b * c;
	for (int i = -1; i < b - 1; i++) { //i=0, i<b�� ������ ����� �迭�� ������ ����� �����ߴ�.
		ans += a[*a + d + i]; //�����ּҸ� ��� �ű⼭ �ڷ� b����ŭ�� ���Ҹ� ���Ѵ�.
		printf("ans = +=y[%d] = %d\n", *a + d + i, ans);
	}
	return ans;
}
int main() {
	int y[4][4] = { {1,2,3,4},{2,3,4,5},{4,5,6,7},{5,6,7,8} };

	printf("%d\n", sumRaw(&(y[0][0]), 3, 2));
	return 0;
}