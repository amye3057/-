#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
int main() {


    //�ƿ�. �Ѽ��Ծ� ���� �����ַ��ٰ� �ð��� �� ������. �� ��վ��� �ߴµ� �� ������ �߳� �úη� ��� �߸��Ȱǵ�!!
    //�� 7��°���� ������ �迭�� �״�� ��µǳİ�! �ƿ� ���� �� ���� �ؾ��ϴµ� �� �ð��̳�.


    char data[6];
    int i, j, num, rightshift_num, p, SIX;
    rightshift_num = 1;

    printf("2019124223 �Ѽ���\n\n");
    printf("Right shiftȽ�� :");
    scanf("%d", &num);
    printf("5���ڸ� �Է��Ͻÿ�:");
    scanf("%s", data);

    printf("\n[output]\n");
    printf("Original: %s\n", data);

    while (num != 0)
    {
            printf("Rightshift(%d):", rightshift_num); //6��° ����(data[5])�� �ϴ� �� ������ �����س���(SIX = data[5]), �������� ������� �ڷ� ���ش�.
                                           //ex) data[4]->data[5], data[3]->data[4] ... data[0]->data[1] �� ���� SIX->data[0]
            SIX = data[5]; //�迭�� ������ ���
            i = 4, j = 5; //���⼭ ������ ����� while���� �ݺ��Ǿ��� �� i, j�� ���� ������ �ʰ� �ʱ�ȭ�� �ȴ�. i�� 4, j�� 5�� ������ 22��° �ּ��� �ִ�.
            while (i >= 0) //data[0]���� �ݺ�
            {
                data[j] = data[i]; //data �迭���� i��°(��) ���ڸ� j��°(��) �ڽ����� �����Ѵ�.
                j = j - 1;
                i = i - 1;
            }
            data[0] = SIX;
            for (p = 0; p < 6; p++) //�迭�� ũ�Ⱑ 6�̰� Ȯ���Ϸ��� ���� �� 5�ڸ��̹Ƿ�
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