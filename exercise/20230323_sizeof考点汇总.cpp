#include <iostream>
#include <vector>

//���֪ʶ����C++ Primer P139 4.9С�� sizeof�����

using namespace std;

void func(char str[], int n);

int main()
{
    char q[] = "WUYAN";
    char *qt = q;
    int x = 1;
    double *p;
    vector<int> vi(10, 1);

    cout << sizeof(q) << endl; //���6����Ϊ���������ռ���ڴ�ռ�Ĵ�С(��ʱ�����������˻�Ϊָ��)������ĩβ����һ��������
    cout << sizeof(qt) << endl; //���8����Ϊ�������ָ�뱾����ռ�õ��ڴ��С
    cout << sizeof(*qt) << endl; //���1����Ϊ�������ָ����ָ��Ķ���(�ַ������ַ�)��ռ�õ��ڴ��С

    func(q, sizeof(q));

    cout << "1) x = " << x << endl;
    cout << sizeof(x++) << endl;
    cout << "2) x = " << x << endl; //sizeof���������ʵ�ʼ�������������ֵ

    cout << sizeof(p) << endl; //���8�����е�ָ��������Ч

    for(auto i = vi.begin(); i != vi.end(); i ++)
        cout << *i << ' ';
    cout << endl << sizeof(vi) << endl; //���24��ֻ���ظ����͹̶�����(����ָ��)�Ĵ�С�������������е�Ԫ��ռ���˶��ٿռ�

    return 0;
}

//���о��棬��ʾ����Ϊstr��ת��Ϊָ��
void func(char str[], int n)
{
    cout << "Hello World" << endl;
    cout << sizeof(str) << endl; //���8����Ϊ��������Ϊ��������ʱ�Զ��˻�Ϊָ��
    return;
}