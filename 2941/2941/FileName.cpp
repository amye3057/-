#include <stdio.h>
#include <string.h>

int main() {
	char arr[101] = {};
	int n = 0;
	scanf_s("%s", arr, 101);
	for (int i = 0; i < strlen(arr); i++) {
		//�̵� �밡�� ���� ũ�ξ�Ƽ�� ���ڿ� �迭 �ϳ� �������� �װŶ� ���ؼ� ���� ���� �Լ� ����� �� �� ���� �ѵ�.. 
		if (arr[i] == 'c' && arr[i + 1] == '=') {
			i += 1;
			n++;
		}
		else if (arr[i] == 'c' && arr[i + 1] == '-') {
			i += 1;
			n++;
		}
		else if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=') {
			i += 2;
			n++;
		}
		else if (arr[i] == 'd' && arr[i + 1] == '-') {
			i += 1;
			n++;
		}
		else if (arr[i] == 'l' && arr[i + 1] == 'j') {
			i += 1;
			n++;
		}
		else if (arr[i] == 'n' && arr[i + 1] == 'j') {
			i += 1;
			n++;
		}
		else if (arr[i] == 's' && arr[i + 1] == '=') {
			i += 1;
			n++;
		}
		else if (arr[i] == 'z' && arr[i + 1] == '=') {
			i += 1;
			n++;
		}
		else
			n++;
	}

	printf("%d", n);
	return 0;
}