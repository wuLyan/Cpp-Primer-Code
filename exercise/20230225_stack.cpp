#include <stack>
#include <iostream>

using namespace std;

int main()
{
    stack<int> stk;

    //��ջ������Ԫ��
    stk.push(3);
    stk.push(4);
    stk.push(1);
    stk.push(2);

    cout << stk.top() << endl; // ����ջ��Ԫ�ص�������
    stk.pop();                 // ����ջ��Ԫ��
    cout << stk.top() << endl; 

    cout << stk.size() << endl;
    if (stk.empty())
        puts("��ʱջstkΪ��");
    else
        puts("��ʱջstk��Ϊ��");


    return 0;
}