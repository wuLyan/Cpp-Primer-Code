#include <stdio.h>

#define SIZE    22

int findSingleNumber(int *array, int size);

int main()
{
    //printf("%ld", sizeof(int)); //int����ռ4���ֽ�
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1001, 1, 2, 3, 4, 5, 6, 7};

    printf("The number in array appears only once is: ");
    printf("%d\n", findSingleNumber(array, SIZE));

    return 0;
}

//ʹ��������Ϊ����ʱ����Ϊ�������ı�����һ��ָ�룬���Ի��ô�������Ĵ�С��ȷ����ȡ�ı߽�
//���ַ���ֻ����������һ�������У�����һ������ֻ����һ��֮�⣬�������ֶ����������μ�����(���ܶ�Ҳ������)
//�����ǲ���������һ�������У�����һ������ֻ����һ��֮�⣬�������ֶ�����������
int findSingleNumber(int *array, int size)
{
    int bitSum[32] = {0}; //�����洢ÿһ��������λ�ϵ���
    //bitSum[i]�洢�����������������ֵĶ����Ʊ�ʾ�е�iλ�ĺ�(���Ҳ��Ϊ��0λ)

    //�������е�ÿһ������ÿһλ��������
    for(int i = 0; i < size; i ++)
    {
        for(int j = 0; j < 32; j ++)
        {
            bitSum[j] += (array[i] >> j) & 1; //����λ�� & �� �߼��� &&
            //�Ȱ�������λ����jλ������1���������㣬��ȡ����arr[i]�ĵ�jλ����󽫽���ӵ�bitSum������
        }
    }

    //��bitSum�����е�ÿһ������3ȡ�࣬�õ��Ľ������ֻ����һ�ε����Ķ����Ʊ�ʾ
    //��Ϊ�������г������ε����ֵĶ�����λ��3ȡ��Ľ������0
    int result = 0;

    for(int i = 0; i < 32; i ++)
    {
        //result += (bitSum[31 - i] % 3) << (31 - i);
        result += (bitSum[i] % 3) << (i); //����д��������
        //�ȶ�bitSum[i]��3ȡ�࣬������(31-i)λ����󽫽���ӵ�result��
    }

    return result;
}