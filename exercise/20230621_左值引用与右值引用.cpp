#include <iostream>

using namespace std;

int main()
{
    int r = 42;
    int &r1 = r; //��ֵ���ã��󶨵�������
    // int &&rr1 = r; //error���޷�����ֵ���ð󶨵���ֵ��
    int &&rr2 = 42; //��ֵ���ã��󶨵���ֵ����(����ֵ)��
    int &&rr3 = r * 2; //��ֵ���ã��󶨵���ֵ����(���ʽ)��
    const int &r3 = r; //const��ֵ���ÿ��԰󶨵���ֵ��
    // int &&rr4 = r3; //error����ֵ�������͵ı�����������ֵ���޷�����ֵ���ð󶨵���ֵ��

    return 0;
}