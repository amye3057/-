#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() { //정답. 입력시 바로 출력하는게 정답이었나 봄. 근데 오히려 여기서 출력할 땐 이게 이상함..
	char c;

	while (scanf("%c", &c) != EOF) {
		printf("%c", c);
	}

	return 0;
}

int fake_main()
{
	/*내가 짠 건데 이게 아니었음*/
	char ch;
	int string[101][101] = {};
	int i = 0;
	int n = 1;

	while (n)
	{
		int j = 0;
		while ((ch = getchar()) != '\n' && ch != 26 && ch != EOF) {
			string[i][j] = ch;
			//printf("string[%d][%d]=%d\n", i, j, ch); //확인용
			j++;
		}
		printf("확인 : %c\n", ch); //확인용
		
		if (ch == '\n') {
			if (string[i][j] == EOF)
				n = 0;
			else {
				string[i][j] = ch;
				i++;
			}
		}
		if (ch == EOF || ch == 26)
		{
			n = 0;
			printf("EOF 발동");
		}
	}
	//\n 이후에 바로 EOF(Ctrl+Z)를 입력하면 상관없는데 문장의 마지막에 입력하면 물음표가 반전된 것이 출력된다. 아스키 코드26이라서 저렇게 처리함.
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (string[i][j] == EOF)
				break;
			printf("%c", string[i][j]);
		}
	}

	return 0;
}