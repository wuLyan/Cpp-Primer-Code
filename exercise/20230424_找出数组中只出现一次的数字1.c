#include <stdio.h>

#define SIZE    15

int findSingleNumber(int *array, int size);

int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1001};
    //int array[SIZE] = {1, 2, 3, 4, 5, 6, 1001, 1, 2, 3, 4, 5, 6, 1001, 1001};
    //int array[SIZE] = {2, 2, 3, 4, 5, 6, 1001, 2, 2, 3, 4, 5, 6, 1001, 1001};

    printf("The number in array appears only once is: ");
    printf("%d\n", findSingleNumber(array, SIZE));

    return 0;
}

//ʹ��������Ϊ����ʱ����Ϊ�������ı�����һ��ָ�룬���Ի��ô�������Ĵ�С��ȷ����ȡ�ı߽�
//���ַ���ֻ����������һ�������У�����һ������ֻ����������֮�⣬�������ֶ�������ż����
int findSingleNumber(int *array, int size)
{
    int result = array[0];

    for(int i = 1; i < size; i ++)
    {
        result ^= array[i]; //������㣺��ͬΪ�㣬��ͬΪһ
        //printf("%d\n", result);
        //�����������������ǣ���a�������ͬһ����b�����������a�����ͺ�����bû�в�������һ��
    }

    return result;
}