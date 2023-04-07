#include <iostream>
#include <string>

//���֪ʶ����C++ Primer P263 7.5.4С�� ��ʽ��������ת��

using namespace std;

class A
{
    private:
        string str;
        int x = 0;
    public:
        A() {} //�����Լ��ṩ�˹��캯������һ��Ҫдһ��Ĭ�Ϲ��캯��
        //Ĭ�Ϲ��캯�����Բ����κβ�����Ҳ����Ϊ���в�������Ĭ��ֵ
        A(const string s) : str(s) {}
        void show() {cout << str << " " << x << endl;}
        void test(const A &a) {str = a.str; x = a.x + 1;}
};

int main()
{
    //��ʽ����ת�������Ļ�����������ͨ��һ��ʵ�ε��õĹ��캯��
    A a1("hello");
    a1.show();

    //������ֻ���Զ�ִ��һ������ת��
    A a2, a3, a4;
    //a2.test("hello"); //�������Ҫ���õĻ��������������ʽ����ת�����ַ�������ֵ -> string���� -> ��A�Ķ���
    a2.test(a1); //û�з�����ʽ����ת��
    a2.show();
    a3.test(A("hello")); //�ַ�������ֵ��ʽת��Ϊstring����string������ʽת��Ϊ��A�Ķ���
    a3.show();
    a4.test(string("hello")); //�ַ�������ֵ��ʽת��Ϊstring����string������ʽת��Ϊ��A�Ķ���
    a4.show();

    //ʹ�ùؼ���explicit��ֹ��ʽ����ת����������Ȼ������ʽ����ת��

    return 0;
}