#include <iostream>

using namespace std;

class numbered
{
    private:
        static int id; //��̬���ݳ�Ա��������������ж��������� 
    public:
        int mysn;
        numbered() { mysn = id++; }
        numbered(const numbered &n) { mysn = id++; } //�������캯��
        numbered &operator=(const numbered &n) { mysn = id++; } //������ֵ�����
};

int numbered::id = 0; //��̬��Ա��ʼ��

//void f(numbered s)
void f(numbered &s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b; //b��c�ĳ�ʼ�������Զ��忽�����캯��
    f(a); //�����ô��ݲ�������������Զ���Ŀ������캯��
    f(b);
    f(c);

    return 0;
}