#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() { //����. �Է½� �ٷ� ����ϴ°� �����̾��� ��. �ٵ� ������ ���⼭ ����� �� �̰� �̻���..
	char c;

	while (scanf("%c", &c) != EOF) {
		printf("%c", c);
	}

	return 0;
}

int fake_main()
{
	/*���� § �ǵ� �̰� �ƴϾ���*/
	char ch;
	int string[101][101] = {};
	int i = 0;
	int n = 1;

	while (n)
	{
		int j = 0;
		while ((ch = getchar()) != '\n' && ch != 26 && ch != EOF) {
			string[i][j] = ch;
			//printf("string[%d][%d]=%d\n", i, j, ch); //Ȯ�ο�
			j++;
		}
		printf("Ȯ�� : %c\n", ch); //Ȯ�ο�
		
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
			printf("EOF �ߵ�");
		}
	}
	//\n ���Ŀ� �ٷ� EOF(Ctrl+Z)�� �Է��ϸ� ������µ� ������ �������� �Է��ϸ� ����ǥ�� ������ ���� ��µȴ�. �ƽ�Ű �ڵ�26�̶� ������ ó����.
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (string[i][j] == EOF)
				break;
			printf("%c", string[i][j]);
		}
	}

	return 0;
}