#include <iostream>
#include <queue>
#include <deque> //deque = double-ended queue

using namespace std;

int main()
{
    queue<int> q;

    for (int i = 0; i < 5; i ++)
        q.push(3 * i - 2); //���β����Ԫ��
    q.pop(); //������ͷԪ��

    cout << "��ʱ��ͷԪ����: " << q.front() << endl; //���ض�ͷԪ��
    cout << "��ʱ��βԪ����: " << q.back() << endl;  //���ض�βԪ��

    q.pop();
    cout << "��ʱ��������" << q.size() << "��Ԫ��" << endl;

    q = queue<int>(); //û��clear��ն��еĺ�����ֻ�ܲ������ַ���
    if (q.empty())
        puts("��ʱ����Ϊ��");
    else
        puts("��ʱ���в�Ϊ��");

    return 0;
}