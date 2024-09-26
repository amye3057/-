#include <stdio.h>
#include <string.h>

int main() {
	char arr[101] = {};
	int n = 0;
	scanf_s("%s", arr, 101);
	for (int i = 0; i < strlen(arr); i++) {
		//이딴 노가다 말고 크로아티아 문자열 배열 하나 만들어놓고 그거랑 비교해서 숫자 세는 함수 만들면 될 것 같긴 한데.. 
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