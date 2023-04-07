#include <iostream>

using namespace std;

class A
{
    private:
        int len;
        int *pt;
    public:
        A(int n, int *p) : len(n) 
        {
            pt = new int;
            *pt = *p;
        }
        A(const A &s)
        {
            len = s.len;
            pt = new int;
            *pt = *s.pt;
        }
        ~A()
        {
            delete pt; //new �� delete����ɶԳ���
        }

        void print()
        {
            cout << &len << ": " << len << endl;
            cout << pt << ": " << *pt << endl;
        }
};

int main() 
{
    int i = 100;
    cout << &i << ": " << i << endl;

    A a1(5, &i);
    A a2 = a1; //�ڶ����ͬʱ��ʼ��ʹ��Ĭ�ϸ��ƹ��캯���������Ǹ�ֵ�����

    //��Ա�����к���ָ�룬��̬�����ڴ�ռ䣬��˱���ʹ�����
    a1.print();
    a2.print();

    return 0; 
}