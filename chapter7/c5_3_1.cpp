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
        A a;

    public:
        void show() {a.show();}
};

int main()
{
    B b; //��B��ʹ��ϵͳ�ṩ�ĺϳ�Ĭ�Ϲ��캯�������Ƚ�����A��Ĭ�Ϲ��캯��
    b.show();

    return 0;
}