#include <stdio.h>

int sumRaw(int* a, int b, int c) {
	int ans = 0;
	int d = b * c;
	for (int i = -1; i < b - 1; i++) { //i=0, i<b로 조건을 만들면 배열의 범위를 벗어나서 조정했다.
		ans += a[*a + d + i]; //시작주소를 잡고 거기서 뒤로 b개만큼의 원소를 더한다.
		printf("ans = +=y[%d] = %d\n", *a + d + i, ans);
	}
	return ans;
}
int main() {
	int y[4][4] = { {1,2,3,4},{2,3,4,5},{4,5,6,7},{5,6,7,8} };

	printf("%d\n", sumRaw(&(y[0][0]), 3, 2));
	return 0;
}