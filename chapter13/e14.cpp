#include <iostream>

using namespace std;

class numbered
{
    private:
        static int id; //��̬��Ա���������������κζ��󣬶�����������
    public:
        int mysn;
        numbered() { mysn = id++; }
};

int numbered::id = 0; //��̬��Ա��ʼ��

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b; //b��c�ĳ�ʼ�����úϳɿ������캯��
    // ��������еĶ�����һ��static���ݳ�Ա����Ϊ�ϳɿ������캯��ֻ�Ǽ򵥵Ŀ����˶�������ݳ�Ա
    f(a); //��ֵ���ݲ������úϳɿ������캯������ͬ
    f(b);
    f(c);

    return 0;
}