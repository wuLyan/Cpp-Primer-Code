//���⣺��C��C++�У�free()��delete����β���ָ��̬�����ڴ��ָ��ģ�
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char *p = new char[100];
    strcpy(p, "wuyan");
    cout << "p = " << p << endl;
    delete []p; //delete��������һ��������
    cout << "p = " << p << endl;

    if (p != 0) //C++�У�������0��ʾ��ָ��
    {
        strcpy(p, "Hello World");
        cout << "p = " << p << endl;
    }
    //ͨ�����ϳ�����Կ�����deleteֻ�ǰѶ�̬���ٵ��ڴ��ͷŵ������û���ò�Ҫ��ʹ�ã��п��ܴ�ŵ�������ֵ
    //����ָ����ڴ�ռ��ָ�벻�����ٴ������Ի����ٶ��丳ֵ
    //������������������ȫ��ָ���п���ָ���޷����ʵĿռ䣬���Խ������²���
    p = 0;

    return 0;
}