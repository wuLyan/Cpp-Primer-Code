#include <iostream>
#include <string>

using namespace std;

typedef string arr[10];

string str[10];

string (&fun1(void))[10];
arr &fun2(void);
auto fun3(void) -> string (&)[10];
decltype(str) &fun4(void);

int main()
{
    
    return 0;
}

//���ذ���10��string��������������
string (&fun1(void))[10]
{

}

//ʹ�����ͱ���
arr &fun2(void)
{

}

//ʹ��β������
auto fun3(void) -> string (&)[10]
{

}

//ʹ��decltype�ؼ���
decltype(str) &fun4(void)
{

}
