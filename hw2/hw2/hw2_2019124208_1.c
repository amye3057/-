#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
//희소행렬의 크기 설정
#define x 100
#define y 3

//읽어들이는 파일명의 크기 제한
#define n 20

void input_array(int array[][y], char name[]) { //입력할 배열, 읽어들이는 파일명
	FILE* fp = NULL;
		 //name 파일을 read mode(읽기모드)로 열기
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
			if (character == '-') { //숫자가 아닌 - 문자가 들어가 있을 경우 한 칸 뒤로 이동 시킨 뒤, 해당 문자를 정수값으로 변환 후 음수화 시킨다.
				character = getc(fp);
				array[i][j] = -atoi(&character); //여기서 막히길래 atoi 함수가 왜 안 먹히나.. 했는데 인자가 문제인가? 해서 앞에 &를 붙였더니 된다..
			}
			else {
				array[i][j] = atoi(&character);
			}
			j++;
		}
		if (j == 3) {
			j = 0;
			i++;
			character = getc(fp); //한 줄마다 오는 맨끝의 0을 없애기 위해서
		}
	} while (character != EOF);

	fclose(fp);

	printf("희소행렬을 생성했습니다.\n");
	for (int a = 0; a < i; a++) {
		for (int b = 0; b < y; b++) {
			printf("%d ", array[a][b]);
		}
		printf("\n");
	}
}

void plus_array(int a1[][y], int a2[][y], int a3[][100], int sizeofarray[]) {
	int sum = a1[0][2];
	for (int i = 1; i < a1[0][2] + 1; i++) { //희소행렬의 첫번째 행에 담긴 정보를 이용, 1행 3열의 0이 아닌 원소의 개수만큼 반복해서 집어넣음.
		a3[a1[i][0]][a1[i][1]] += a1[i][2];
	}
	for (int i = 1; i < a2[0][2] + 1; i++) {
		if (a3[a2[i][0]][a2[i][1]] == 0)
			sum++; //a1에서 대입한 곳과 동일하지 않은 곳을 대입하게 될 경우, 총 개수를 하나 늘린다.
		a3[a2[i][0]][a2[i][1]] += a2[i][2];
		if (a3[a2[i][0]][a2[i][1]] == 0)
			sum--; //더했는데 0이 될 경우, 총 개수를 하나 줄인다.
	}
	printf("더한 결과입니다.\n");

	int a, b; //만약 희소행렬 a1, a2의 배열의 크기가 각각 다를 경우를 위해 아래 if문을 만들었다. (이번 경우엔 4 6으로 둘 다 동일하다..)

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

	//a3에 저장한 값을 희소행렬로 출력
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
	printf("희소 행렬을 행렬 형태로 출력합니다.\n");
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
	printf("희소행렬을 파일에 저장했습니다.\n");
}


int main() {
	int array1[x][y] = { 0 };
	int array2[x][y] = { 0 }; //더할 값이 들어갈 공간.
	int array3[100][100] = { 0 }; //행렬형태로 출력할 배열. 100X100 크기.
	int savearray[x][y] = { 0 }; //저장할 값이 들어갈 공간.

	int sizeofarray[3] = { 0 }; //희소행렬의 첫행에서 배열의 크기를 가져오려고 했으나 return 값을 2개 이상 받을 수 없어서 그냥 배열로 받기로 했다.

	char filename[n] = "";

	int i;
	while (1) {
		printf("> 원하는 작업을 선택하세요 (1:입력, 2: 행렬 더하기, 3: 출력, 4:저장, 0:종료) : ");
		scanf_s("%d", &i);
		switch (i) {
			getchar();
		case 1:
			printf("파일 이름을 입력하세요: ");
			scanf_s("%s", filename, n);
			input_array(array1, filename);
			break;
		case 2:
			printf("파일 이름을 입력하세요: ");
			scanf_s("%s", filename, n);
			printf("더할 ");
			input_array(array2, filename);
			plus_array(array1, array2, array3, sizeofarray); //array1과 array2 희소행렬을 더한 뒤 array3에 저장한 걸 희소행렬 형태로 출력
			break;
		case 3:
			print_array(array3, sizeofarray);
			break;
		case 4:
			printf("파일 이름을 입력하세요: ");
			scanf_s("%s", filename, n);
			save_array(array3, sizeofarray, filename);
			break;
		default:
			printf("Bye~");
			return 0;
		}
	}
}