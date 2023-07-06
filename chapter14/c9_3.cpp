#include <iostream>

using namespace std;

class A
{
    friend int operator+(A &a, int x);
    private:
        int n;
    public:
        A() : n(10) { }
        // operator int() const { return n; }
        int operator+(int x) { return this->n + x; }
};

int operator+(A &a, int x)
{
    return a.n + x;
}

int main()
{
    A a;

    // cout << a + 20 << endl; //��������ת�������
    // cout << a + 20 << endl; //�������ص����ڼӷ������
    // cout << a + 20 << endl; //�������ص���Ԫ�ӷ������

    // ������ĳ�Ա�����ͷǳ�Ա�����ĵ��÷�ʽ��ͬ����˲��ᷢ����ͻ
    cout << a.operator+(20) << endl;
    cout << operator+(a, 20) << endl;

    return 0;
}