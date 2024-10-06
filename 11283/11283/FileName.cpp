#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	wchar_t a;
	wscanf_s(L"%c", &a);
	//wprintf(L"입력 받은 결과 : %c\n", a);
	printf("%d", a - L'가' + 1);
	return 0;
}

// 참조 : https://jimmy-ai.tistory.com/274