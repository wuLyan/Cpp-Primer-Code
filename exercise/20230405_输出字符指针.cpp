#include <iostream>

using namespace std;

int main()
{
    char *ch = "abcd"; //Warning��ISO C++ forbids converting a string constant to 'char*'
    ch += 2; //����ָ��ӷ�֮��chָ���ַ�c
    cout << ch << endl; 
    //����ַ�ָ��ʱ��cout���ܶ����ӵ�ǰλ�õ����ݿ�ʼ�����ֱ���������ַ�������������cd
    cout << *ch << endl; 
    //��Ϊʹ����ȡ���������������ֻ�����ָ��ch��ǰָ������ݣ�����һֱ����ȡ������������c
    cout << &ch << endl; 
    //��Ȼ����ch���Ǹ�ָ�룬������Ҫ�������ָ�����ĵ�ַ�������ټ�ȡ��ַ��������������ַ�c�ĵ�ַ��������ָ�뱾��ĵ�ַ

    //����������ֻ���ַ�ָ���������������������͵�ָ�밴��ָ���������⼴��

    return 0;
}