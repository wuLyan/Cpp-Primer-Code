#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    unique_ptr<string> p1(new string("Hello"));

    //unique_ptr<string> p2(p1); // error: copy is not allowed

    /*
    unique_ptr<string> p3;
    p3 = p1; // error: assignment is not allowed
    */

    unique_ptr<string> p4(p1.get());
    /*
    ע�⣺����ͨ���������Ʋ�����ϵ������unique_ptr����ָ��ͬһ���ڴ�ռ䣬���롢ִ�ж����ᱨ��
    ���ǵ�����һ��unique_ptr������ʱ����һ��unique_ptr�ͻ��Ϊ����ָ�룬�����ͻᵼ�³������
    ���Ի��ǲ��Ƽ������÷�
    */

    return 0;
}