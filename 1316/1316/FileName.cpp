#include <stdio.h>
#include <string.h>

int main() {
	int t;
	int n = 0; //�׷�ܾ��� ����
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		int ok = 1;
		char arr[101] = {};
		int alphabet[26] = {}; //97~122 //���� �ܼ������ 25 �ߴ��� ���� �����÷ο� ���� ������
		scanf_s("%s", arr, 101);
		for (int j = 0; j < strlen(arr); j++) {
			//printf("%d ������ : %d\n", arr[j], alphabet[arr[j]-97]);
			if (alphabet[arr[j] - 97] == 1) {
				ok = 0;
				break;
			}
			if (arr[j] != arr[j + 1]) {
				alphabet[arr[j] - 97]++;
				//printf("alphabet[%d]++\n", arr[j]);
			}
		}
		if (ok == 1)
			n++;
	}
	printf("%d", n);
	return 0;
}