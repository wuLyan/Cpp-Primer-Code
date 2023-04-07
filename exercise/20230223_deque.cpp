#include <iostream>
#include <deque>

using namespace std;

int main()
{
    //deque�൱�ڼ�ǿ���vector
    //��������
    deque<int> q1;        //����һ��û���κ�Ԫ�صĿ�˫�˶���
    deque<int> q2(5);     //����һ��ӵ��5��Ԫ�ص�˫�˶��У�����ÿ��Ԫ�ض����ö�Ӧ���͵�Ĭ��ֵ
    deque<int> q3(5, 5);  //����һ��ӵ��5��Ԫ�ص�˫�˶��У���Ϊÿ��Ԫ�ض�ָ����ʼֵ
    deque<int> q4(q3);    //���������ʼ��
    deque<int> q5(q3);    //���������ʼ��

    q3.push_front(1); //�ڶ�ͷ����Ԫ��
    q3.push_back(6);  //�ڶ�β����Ԫ��

    //�������
    int len1 = q3.size();
    for (int i = 0; i < len1; i ++)
    {
        cout << q3.front() << ' '; //���ض�ͷԪ��
        q3.pop_front(); //������ͷԪ��
    }
    cout << endl;
    
    q4.push_front(2); //�ڶ�ͷ����Ԫ��
    q4.push_back(7);  //�ڶ�β����Ԫ��

    //�������
    int len2 = q4.size();
    for (int i = 0; i < len2; i ++)
    {
        cout << q4.back() << ' '; //���ض�βԪ��
        q4.pop_back(); //������βԪ��
    }
    cout << endl;

    q5.push_front(3); //�ڶ�ͷ����Ԫ��
    q5.push_back(8);  //�ڶ�β����Ԫ��

    //ʹ�õ������������
    for (auto i = q5.begin(); i != q5.end(); i ++) 
        cout << *i << ' ';
    cout << endl;

    q3.clear();
    cout << q3.size() << endl;
    if (q3.empty())
        puts("��ʱ����q3Ϊ��");
    else
        puts("��ʱ����q3��Ϊ��");

    
    return 0;
}