#include <iostream>
#include <string>

//���֪ʶ����C++ Primer P240 7.2С�� ʹ��class��struct�ؼ���

using namespace std;

struct A
{
    //structҲ�ܶ����Ա����
    void show(){cout << "Hello World" << endl;}
};

class B
{
    void show(){cout << "Good Morning" << endl;}
};
/*
ʹ��struct��class�������Ψһ�������Ĭ�Ϸ���Ȩ��
��struct�У������ڵ�һ�����ʿ��Ʒ�֮ǰ�ĳ�Ա��public��
��class�У������ڵ�һ�����ʿ��Ʒ�֮��ĳ�Ա��private��
*/

int main()
{
    A a;
    a.show();

    B b;
    //b.show(); //������Ϊclass��Ĭ�Ϸ���Ȩ����private

    return 0;
}