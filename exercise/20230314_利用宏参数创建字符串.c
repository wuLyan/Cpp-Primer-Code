#include <stdio.h>

#define SQUARE(x)   (printf(""#x" square is %d\n", (x) * (x)))
//#define SQUARE(x)   (printf("%d square is %d\n", x, (x) * (x)))
//��3�е��������ݱ��ʽ�����ڵ��������������Ч����ͬ

int main()
{
    SQUARE(4);

    SQUARE(2 + 4); 
    //ʹ�õ�3��Ԥ���������2 + 4 square is 36
    //ʹ�õ�4��Ԥ���������6 square is 36

    return 0;
}