#include <stdio.h>

#define XNAME(n)    x##n //ʵ�� x �� n ���ϣ�ʹ���������������Է��ſ�����һ�����Է���

int main()
{
    //int x1 = 10;
    int XNAME(1) = 10;
    printf("%d\n", x1);

    return 0;
}