#include <iostream>

using namespace std;

class A
{
    public:
        A() {cout << "1)" << endl;}
        A(int x) {cout << "2)" << endl;}
};

int main()
{
    A a1;
    A a2(2);
    A *pa1; //��û�е��ù��캯����ֻ���ڴ�������Ϊ���󿪱��ڴ�ռ�ʱ�Ż���ù��캯��
    A *pa2 = new A;

    return 0;
}