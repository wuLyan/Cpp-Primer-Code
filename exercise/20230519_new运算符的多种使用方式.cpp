#include <iostream>

using namespace std;

int main()
{
    int *p1 = new int;
    *p1 = 10;
    cout << "*p1 = " << *p1 << endl;

    int *p2 = new int(20); //�����ڴ�ռ䣬�������
    cout << "*p2 = " << *p2 << endl;

    int *p3 = new int[10]; //10��δ����ʼ����int�������ŵ�������ֵ
    cout << "*p3 = " << *p3 << endl;

    int *p4 = new int[10](); //10����ʼ��Ϊ0��int
    cout << "*p4 = " << *p4 << endl;

    int *p5 = new int[10]{1, 2, 3, 4, 5}; //10����ʼ��Ϊ1, 2, 3, 4, 5, 0, 0, 0, 0, 0��int
    cout << "*p5 = " << *p5 << endl;

    const int *p6 = new const int[10](); //10����ʼ��Ϊ0��const int
    //*p6 = 10; //error�������޸�*p6��ֵ
    cout << "*p6 = " << *p6 << endl;

    int *p7 = new (nothrow) int; //���׳��쳣������ʧ�ܷ���0����һ��Ĭ�Ϸ���ʧ��ʱ�׳��쳣
    // nothrow���ɱ�׼�ⶨ��Ķ��󣬴����ͷ�ļ�<new>��
    if (p7 == 0)
        cout << "p7 is null" << endl;
    cout << "*p7 = " << *p7 << endl;

    int data = 0;
    int *p8 = new (&data) int(1); //��data�ĵ�ַ�Ϲ���һ��int����
    // ��λnew���ʽ�����û���new���ݶ���Ĳ�������Щ���������ݸ�operator new����
    cout << "*p8 = " << *p8 << endl;
    cout << "data = " << data << endl;
}