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

	// �������
	except = n * 30 / 100;
	if ((n * 30 / 100) % 1 >= 0.5) {
		except++;
	}
	if (except == 0)
		except = 1;

	// ���� ��ǥ ����
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

	// ���� ��ǥ �����ϰ� ��ü
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

	int ave = sum / (n - 2 * except); // ���
	//(double*)�� ����ȯ ���ִ� �� �� �˾Ҵµ� * ���� ����ؾ��ߴ�. 
	double banolim = (double)sum / (double)(n - 2 * except); // banolim % 1 �� �ϴµ� �ڲ� "�Ŀ� ���� �Ǵ� ������ �������� ���� ������ ������ �־�� �մϴ�." ��� �ߴ°Ŵ�.
	if (fmod(banolim, 1) >= 0.5) { // �˰� ���� �Ǽ����� ������ ������ ����� �� ����. <math.h> ���̺귯�� �ҷ��ͼ� fmod�� ������ �� �ִ�.
		ave++;
	}

	printf("%d", ave);
	return 0;
}