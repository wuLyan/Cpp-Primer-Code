#include <stdio.h>

int main()
{
    unsigned int i = 0;
    printf("i = %ud\n", i);

    unsigned int j = ~0; //�ڲ�֪��ϵͳλ��ʱ��ͨ������Сֵ��ÿһλȡ���õ����ֵ
    printf("j = %ud\n", j);

    //printf("%d", sizeof(int));

    return 0;
}