#include <iostream>
#include <string>

using namespace std;

void func(const string &str);

int main(void)
{
        func("ABC");  //"ABC"-->string���󣬷�����ʽ����ת����������ʱstring���󴫵ݸ��β�
        //��ʱstring��������ֵ����ֵ�޷������ǳ���������

        return 0;
}

//������ʱ������βα����ǳ�������
void func(const string &str)
{

}