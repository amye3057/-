#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	wchar_t a;
	wscanf_s(L"%c", &a);
	//wprintf(L"�Է� ���� ��� : %c\n", a);
	printf("%d", a - L'��' + 1);
	return 0;
}

// ���� : https://jimmy-ai.tistory.com/274