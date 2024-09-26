#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
int main() {


    //아오. 한설규씨 과제 도와주려다가 시간이 꽤 지났네. 뭐 재밌었긴 했는데 왜 에러가 뜨냐 시부럴 어디가 잘못된건데!!
    //왜 7번째마다 이전의 배열이 그대로 출력되냐고! 아오 몰라 내 과제 해야하는데 잘 시간이네.


    char data[6];
    int i, j, num, rightshift_num, p, SIX;
    rightshift_num = 1;

    printf("2019124223 한설규\n\n");
    printf("Right shift횟수 :");
    scanf("%d", &num);
    printf("5문자를 입력하시오:");
    scanf("%s", data);

    printf("\n[output]\n");
    printf("Original: %s\n", data);

    while (num != 0)
    {
            printf("Rightshift(%d):", rightshift_num); //6번째 숫자(data[5])를 일단 한 곳에다 저장해놓고(SIX = data[5]), 나머지를 순서대로 뒤로 빼준다.
                                           //ex) data[4]->data[5], data[3]->data[4] ... data[0]->data[1] 그 다음 SIX->data[0]
            SIX = data[5]; //배열의 마지막 요소
            i = 4, j = 5; //여기서 선언을 해줘야 while문이 반복되었을 때 i, j가 값이 쌓이지 않고 초기화가 된다. i가 4, j가 5인 이유는 22번째 주석에 있다.
            while (i >= 0) //data[0]까지 반복
            {
                data[j] = data[i]; //data 배열에서 i번째(앞) 숫자를 j번째(뒤) 박스에다 대입한다.
                j = j - 1;
                i = i - 1;
            }
            data[0] = SIX;
            for (p = 0; p < 6; p++) //배열의 크기가 6이고 확인하려는 것은 앞 5자리이므로
            {
                printf("%c", data[p]);
            }
            num = num - 1;
            rightshift_num = rightshift_num + 1;
            printf("\n");
        }
    }
 

    return 0;
}