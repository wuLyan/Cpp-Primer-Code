#include <iostream>

using namespace std;

class A
{
    private:
        int n1;
        int n2;
    public:
        //Ĭ�Ϲ��캯����Ҫô���ṩ�κ��βΣ�Ҫ��Ϊ�����β��ṩĬ��ֵ
        A() : n2(1), n1(n2 + 2) {}
        //��Ա��������ʼ����˳�������Ǳ�������˳�򣬶����������ڳ�ʼ���б��е�˳��
        void print()
        {
            cout << "n1 = " << n1 << endl;
            cout << "n2 = " << n2 << endl;
        }
};

int main()
{
    A a;
    a.print();

    return 0;
}