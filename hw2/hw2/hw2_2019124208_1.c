#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
//�������� ũ�� ����
#define x 100
#define y 3

//�о���̴� ���ϸ��� ũ�� ����
#define n 20

void input_array(int array[][y], char name[]) { //�Է��� �迭, �о���̴� ���ϸ�
	FILE* fp = NULL;
		 //name ������ read mode(�б���)�� ����
	if (fopen_s(&fp, name, "r") != NULL) {
		printf("fail to get file");
		return 0;
	}

	char character;
	int i = 0;
	int j = 0;
	do
	{
		character = getc(fp);
		if (character != ' ') {
			if (character == '-') { //���ڰ� �ƴ� - ���ڰ� �� ���� ��� �� ĭ �ڷ� �̵� ��Ų ��, �ش� ���ڸ� ���������� ��ȯ �� ����ȭ ��Ų��.
				character = getc(fp);
				array[i][j] = -atoi(&character); //���⼭ �����淡 atoi �Լ��� �� �� ������.. �ߴµ� ���ڰ� �����ΰ�? �ؼ� �տ� &�� �ٿ����� �ȴ�..
			}
			else {
				array[i][j] = atoi(&character);
			}
			j++;
		}
		if (j == 3) {
			j = 0;
			i++;
			character = getc(fp); //�� �ٸ��� ���� �ǳ��� 0�� ���ֱ� ���ؼ�
		}
	} while (character != EOF);

	fclose(fp);

	printf("�������� �����߽��ϴ�.\n");
	for (int a = 0; a < i; a++) {
		for (int b = 0; b < y; b++) {
			printf("%d ", array[a][b]);
		}
		printf("\n");
	}
}

void plus_array(int a1[][y], int a2[][y], int a3[][100], int sizeofarray[]) {
	int sum = a1[0][2];
	for (int i = 1; i < a1[0][2] + 1; i++) { //�������� ù��° �࿡ ��� ������ �̿�, 1�� 3���� 0�� �ƴ� ������ ������ŭ �ݺ��ؼ� �������.
		a3[a1[i][0]][a1[i][1]] += a1[i][2];
	}
	for (int i = 1; i < a2[0][2] + 1; i++) {
		if (a3[a2[i][0]][a2[i][1]] == 0)
			sum++; //a1���� ������ ���� �������� ���� ���� �����ϰ� �� ���, �� ������ �ϳ� �ø���.
		a3[a2[i][0]][a2[i][1]] += a2[i][2];
		if (a3[a2[i][0]][a2[i][1]] == 0)
			sum--; //���ߴµ� 0�� �� ���, �� ������ �ϳ� ���δ�.
	}
	printf("���� ����Դϴ�.\n");

	int a, b; //���� ������ a1, a2�� �迭�� ũ�Ⱑ ���� �ٸ� ��츦 ���� �Ʒ� if���� �������. (�̹� ��쿣 4 6���� �� �� �����ϴ�..)

	if (a1[0][0] > a2[0][0])
		a = a1[0][0];
	else
		a = a2[0][0];
	if (a1[0][1] > a2[0][1])
		b = a1[0][1];
	else
		b = a2[0][1];

	sizeofarray[0] = a;
	sizeofarray[1] = b;
	sizeofarray[2] = sum;

	//a3�� ������ ���� �����ķ� ���
	printf("%d %d %d\n", a, b, sum);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (a3[i][j] != 0) {
				printf("%d %d %d\n", i, j, a3[i][j]);
			}
		}
	}
}

void print_array(int array[][100], int sizeofarray[]) {
	printf("��� ����� ��� ���·� ����մϴ�.\n");
	for (int i = 0; i < sizeofarray[0]; i++) {
		for (int j = 0; j < sizeofarray[1]; j++) {
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}

}

void save_array(int array[][100], int sizeofarray[], char name[n]) {
	FILE* fp = NULL;
	if (fopen_s(&fp, name, "w+") != NULL) {
		printf("fail to generate file");
		return 0;
	}
	fprintf(fp, "%d %d %d\n", sizeofarray[0], sizeofarray[1], sizeofarray[2]);
	for (int i = 0; i < sizeofarray[0]; i++) {
		for (int j = 0; j < sizeofarray[1]; j++) {
			if (array[i][j] != 0) {
				fprintf(fp, "%d %d %d\n", i, j, array[i][j]);
			}
		}
	}
	fclose(fp);
	printf("�������� ���Ͽ� �����߽��ϴ�.\n");
}


int main() {
	int array1[x][y] = { 0 };
	int array2[x][y] = { 0 }; //���� ���� �� ����.
	int array3[100][100] = { 0 }; //������·� ����� �迭. 100X100 ũ��.
	int savearray[x][y] = { 0 }; //������ ���� �� ����.

	int sizeofarray[3] = { 0 }; //�������� ù�࿡�� �迭�� ũ�⸦ ���������� ������ return ���� 2�� �̻� ���� �� ��� �׳� �迭�� �ޱ�� �ߴ�.

	char filename[n] = "";

	int i;
	while (1) {
		printf("> ���ϴ� �۾��� �����ϼ��� (1:�Է�, 2: ��� ���ϱ�, 3: ���, 4:����, 0:����) : ");
		scanf_s("%d", &i);
		switch (i) {
			getchar();
		case 1:
			printf("���� �̸��� �Է��ϼ���: ");
			scanf_s("%s", filename, n);
			input_array(array1, filename);
			break;
		case 2:
			printf("���� �̸��� �Է��ϼ���: ");
			scanf_s("%s", filename, n);
			printf("���� ");
			input_array(array2, filename);
			plus_array(array1, array2, array3, sizeofarray); //array1�� array2 �������� ���� �� array3�� ������ �� ������ ���·� ���
			break;
		case 3:
			print_array(array3, sizeofarray);
			break;
		case 4:
			printf("���� �̸��� �Է��ϼ���: ");
			scanf_s("%s", filename, n);
			save_array(array3, sizeofarray, filename);
			break;
		default:
			printf("Bye~");
			return 0;
		}
	}
}