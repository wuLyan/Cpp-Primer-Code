//���ڣ�20221223
//���ݣ����ַ���������ʼ���ַ�ָ�롢�ַ����������ڴ��е�λ��
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    char *pt1 = "AAA"; //��C�У���һ����ȫû���⣻������C++�лᷢ�����棺���⽫�ַ���������ֵ��char *����
    char pt2[4] = "BBB";

    printf("%s\n", pt1);
    printf("%s\n", pt2);

    cout << "---------" << endl;
    pt1[0] = 'C'; //�ַ������������ֻ�������У�Ҫ����ͨ��ָ���޸����ǵ�ֵ
    pt2[0] = 'C';

    //printf("%s\n", pt1);
    //printf("%s\n", pt2);
    cout << "---------" << endl;

    return 0;
}