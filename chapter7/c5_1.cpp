#include <iostream>

using namespace std;

class B
{
    private:
        int val;
    public:
        B() {cout << "Good Morning" << endl;}
        B(int n) : val(n) {cout << "Hello World" << endl;}
};

class A
{
    private:
        B b;
    public:
        //A(int v) : b(v) {} //��Ա��ʼ���б�ʽ
        A(int v) {b = v;} //��ֵ��ʽ���൱���ȵ���Ĭ�Ϲ��캯����ʼ�����ٵ��ú��ι��캯����ֵ
};

int main()
{
    int x = 10;
    A a(x);

    return 0;
}