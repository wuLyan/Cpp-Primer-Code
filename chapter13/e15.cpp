#include <iostream>

using namespace std;

class numbered
{
    private:
        static int id;
    public:
        int mysn;
        numbered() { mysn = id++; }
        numbered(const numbered &n) { mysn = id++; } //�������캯��
};

int numbered::id = 0; //��̬��Ա��ʼ��

void f(numbered s)
{
    cout << s.mysn << endl;
}   //��ֵ���ݲ���������ÿ������캯��

void f1(numbered &s)
{
    cout << s.mysn << endl;
}   //�����ô��ݲ�����������ÿ������캯��

int main()
{
    numbered a, b = a, c = b; //b��c�ĳ�ʼ�����ÿ������캯�����ֶ�����static���ݳ�Ա��Ȼ��ֵ��ÿ�����������mysn���ݳ�Ա
    f(a); //��ֵ���ݲ������ÿ������캯������ͬ
    f(b);
    f(c);

    cout << "-------------" << endl;

    f1(a);
    f1(b);
    f1(c);

    return 0;
}