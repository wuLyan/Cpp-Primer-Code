#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[] = "flower";

    //��ʾ��ISO C++ forbids converting a string constant to 'char*'
    char *p = "dog";
    char *q = "cat";

    cout << sizeof(a) << " " << strlen(a) << endl;
    //sizeof�����������Ǳ�����ռ�ڴ�Ĵ�С����˼��������'\0'�����7
    //strlen�������ص����ַ����ĳ��ȣ���˲����������'\0'�����6

    cout << a << " " << p << " " << q << endl;
    //���ַ�ָ�봫�ݸ�cout���ܶ��󣬻�һֱ���ֱ���������ַ�Ϊֹ

    p = q; //p��qָ��ͬһ�ڴ�ռ�
    //a = q; //������Ϊ�������������Ǹ��������޷����丳ֵ

    cout << p << " " << q << endl;

    return 0;
}