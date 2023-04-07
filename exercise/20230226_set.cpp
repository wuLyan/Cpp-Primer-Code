#include <set> // ������ set �� multiset
#include <iostream>

using namespace std;

int main()
{
    // set Ҳ�ǻ��ڹ�ϣ��ʵ�ֵģ�����ʹ�� set �����洢�ĸ�����ֵ�ԣ�Ҫ�� key �� value �������
    set<int> s;       //���������ظ�Ԫ�أ���������ظ�Ԫ�أ������������ԣ�������һ����Խ���ȥ��
    multiset<int> ms; //�������ظ�Ԫ��

    //����Ԫ��
    s.insert(2);
    s.insert(4);
    s.insert(1);
    s.insert(3);
    cout << s.size() << endl; // 4

    //ʹ�õ��������б�����˵�� set ά�����ǵ�������
    for (auto i = s.begin(); i != s.end(); i ++)
        cout << *i << ' '; // 1 2 3 4
    cout << endl;

    s.insert(3); //���Բ�����ͬԪ�صĲ���
    cout << s.size() << endl; // 4

    //����Ԫ�أ�����Ԫ�ش����򷵻�ָ���Ԫ�صĵ�����������Ԫ�ز������򷵻� set �����һ��Ԫ�صĵ�����
    cout << *s.find(2) << endl; // 2
    cout << *s.find(5) << endl; // 4

    cout << s.count(4) << endl; //����Ԫ�س��ֵĴ�������Ϊ set ���������ظ�Ԫ�أ���˷���ֵֻ����0��1

    s.erase(4);
    cout << s.count(4) << endl;
    s.erase(s.begin()); //Ҳ�������������
    for (auto i = s.begin(); i != s.end(); i ++)
        cout << *i << ' ';
    cout << endl;

    s.clear();
    if (s.empty())
        puts("��ʱsΪ��");
    else
        puts("��ʱs��Ϊ��");

    return 0;
}