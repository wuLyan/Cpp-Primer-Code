//���ڣ�20221221
//���ݣ�����ָ�롢����ָ�롢��������ȼ�
//����->ָ�룺���ָ������飻ָ��->���飺ָ�������ָ�룻ָ��->����������ָ�룻����->ָ�룺����ָ��ĺ������ȳ��ֵ����������ֵ��Ƕ���
#include <iostream>

using namespace std;

char ch1 = 'w';
char ch2 = 'y';
char ch3 = 'L';
char *const pt1 = &ch1; //����ָ�룬��ζ�Ų����ٸ���ָ��ָ���������������pt1��ָ���ַ����͵ĳ���ָ��
const char *pt2 = &ch2; //ָ������ָ�룬��ζ�Ų���ͨ��ָ���޸���ָ������ֵ�����ⲻ����ch2�ǳ��������Ǵ�ָ��ĽǶ�����ch2�ǳ���
char const *pt3 = &ch3; //C++��׼�涨const�ؼ��ַ����������������֮ǰ���ǵȼ۵ģ����pt3��pt2�ĺ�����ͬ

char *const *fun();

int main()
{
    char *const *(*next)();
    /*
    1):Բ�������ȼ���ߣ�(*next) --> next�Ǹ�ָ��
    2):Բ�������ȼ�����ȡ�����������(*next)() --> next�Ǹ�����ָ��
    3):char *const pt; --> pt��һ��ָ���ַ����͵ĳ���ָ��
    4):char *const *(*next)() --> next��һ������ָ�룬��ָ���β�Ϊ�ա�
            ����ֵΪָ���ַ����͵ĳ���ָ���ָ��ĺ���
    */

    next = fun;
    cout << **next() << endl;

    return 0;
}

char *const *fun()
{
    char *const *ppt1 = &pt1; //ppt1��ָ���ַ����͵ĳ���ָ���ָ��
    //cout << **ppt1 << endl;
    return ppt1;
}

char const *(*(*const bar)[5])(int);
//(*const bar)[5] --> bar��ָ��ӵ�����Ԫ�ص�����ĳ���ָ��
//char const *pt --> pt��ָ��const char���͵�ָ�� 
//char const *(*a)(int) --> a�Ǻ���ָ�룬��ָ�����һ��int���͵��βΡ�����ֵΪָ��const char���͵�ָ��ĺ���
//���bar��ָ��ӵ�����Ԫ�ص�����ĳ���ָ�룬�����е�ÿ��Ԫ�ض��Ǻ���ָ�룬ָ�����һ��int���͵��βΡ�����ֵΪָ��const char���͵�ָ��ĺ���

//https://blog.csdn.net/struggle6688/article/details/71725244