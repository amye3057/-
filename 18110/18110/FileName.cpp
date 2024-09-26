#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int except;
	int sum = 0;
	int survey[31] = {};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int ans;
		scanf_s("%d", &ans);
		survey[ans]++;
	}

	// 절사평균
	except = n * 30 / 100;
	if ((n * 30 / 100) % 1 >= 0.5) {
		except++;
	}
	if (except == 0)
		except = 1;

	// 낮은 투표 제외
	int i = 0;
	int FIRST = 0;
	int N = 0;
	while (N != except) {
		if (survey[i] == NULL)
			i++;
		else {
			survey[i]--;
			FIRST = i;
			N++;
		}
	}

	// 높은 투표 제외하고 전체
	int LAST = 0;
	int j = FIRST;
	while (LAST != n - except*2) {
		if (survey[j] == NULL)
			j++;
		else {
			sum += j;
			survey[j]--;
			LAST++;
		}
	}

	int ave = sum / (n - 2 * except); // 평균
	//(double*)로 형변환 해주는 건 줄 알았는데 * 빼고 사용해야했다. 
	double banolim = (double)sum / (double)(n - 2 * except); // banolim % 1 을 하는데 자꾸 "식에 정수 또는 범위가 지정되지 않은 열거형 형식이 있어야 합니다." 라고 뜨는거다.
	if (fmod(banolim, 1) >= 0.5) { // 알고 보니 실수형은 나머지 연산을 사용할 수 없음. <math.h> 라이브러리 불러와서 fmod로 나눠줄 수 있다.
		ave++;
	}

	printf("%d", ave);
	return 0;
}