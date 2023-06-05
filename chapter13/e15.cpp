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
}

int main()
{
    numbered a, b = a, c = b; //b��c�ĳ�ʼ�������Զ��忽�����캯�����ֶ�����static���ݳ�Ա��Ȼ��ֵ��ÿ�����������mysn���ݳ�Ա
    f(a); //��ֵ���ݲ��������Զ��忽�����캯������ͬ
    f(b);
    f(c);

    return 0;
}