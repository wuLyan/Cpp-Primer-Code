#include <iostream>

using namespace std;

class A
{
    private:
        int n;
    public:
        A(){n = 200;}
        void show() {cout << "n = " << n << endl;}
};

class B
{
    private:
        int x;
        A a;

    public:
        B(int a) : x(a) {}
        void show() {cout << "x = " << x << endl; a.show();} 
};

int main()
{
    B b(10); //��B�Ĺ��캯���У���A�Ķ���û�б���ʾ�ĳ�ʼ�����򽫵���A��Ĭ�Ϲ��캯��
    b.show();

    return 0;
}