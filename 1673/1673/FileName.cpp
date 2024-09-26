#include <stdio.h>

int main() {
	int a, b; // a를 도장의 개수라고 보면 됨. a가 b개만큼 있으면 치킨 1마리 획득 가능
	while (scanf_s("%d %d", &a, &b) != EOF) {
		int chicken = 0;

		chicken += a;

		 do {
			chicken += a / b;
			a = a / b + a % b;
		 } while (a >= b); // 더 이상 치킨쿠폰을 받을 수 없을 때까지. (처음에 a / b >= b로 조건을 넣어줘서 틀림)
		 chicken += a / b; // a/b < b인 경우 루프를 빠져나오는데 이때 마지막으로 한 번 더 더해줘야함
		printf("%d\n", chicken);
	}
}