#include <iostream>

using namespace std;

class A
{
    private:
        int len;
    public:
        A(int n) : len(n) {}

        void print()
        {
            cout << &len << ": " << len << endl;
        }
};

int main() 
{
    A a1(5);
    A a2 = a1; //�ڶ����ͬʱ��ʼ��ʹ��Ĭ�ϸ��ƹ��캯���������Ǹ�ֵ�����

    //��Ա����ֻ�л����������ͣ���˿���ʹ��ǳ����
    a1.print();
    a2.print();

    return 0; 
}