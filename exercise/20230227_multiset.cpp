#include <set> // ������ set �� multiset
#include <iostream>

using namespace std;

int main()
{
    multiset<int> ms; //�������ظ�Ԫ�س���

    //����Ԫ��
    ms.insert(2);
    ms.insert(4);
    ms.insert(1);
    ms.insert(3);
    cout << ms.size() << endl; // 4

    //ʹ�õ��������б�����˵�� multiset ά�����ǵ�������
    for (auto i = ms.begin(); i != ms.end(); i ++)
        cout << *i << ' '; // 1 2 3 4
    cout << endl;
    //�⺯�� end ����ָ���������һ��Ԫ��(ע�⣬�����ź�������һ��)����λ�ú�һ��λ�õ�˫�������

    ms.insert(3); //���������ͬԪ�صĲ���
    cout << ms.size() << endl; // 5

    //����Ԫ�أ�����Ԫ�ش����򷵻�ָ���Ԫ�صĵ�����������Ԫ�ز������򷵻� set �����һ��Ԫ�صĵ�����
    cout << *ms.find(2) << endl; // 2
    cout << *ms.find(100) << endl; // 5

    cout << ms.count(3) << endl; //����Ԫ�س��ֵĴ�������Ϊ�������ظ�Ԫ�أ���˿������κηǸ�����

    //����һ��ָ��ǰ multiset �����е�һ�����ڻ���� val ��Ԫ�صĵ�����
    cout << *ms.lower_bound(2) << endl;
    //����һ��ָ��ǰ multiset �����е�һ������ val ��Ԫ�صĵ�����
    cout << *ms.upper_bound(2) << endl;

    ms.erase(3); //��ɾ������ֵΪ3�Ľڵ㣬���� multiset����Ϊ�������ظ�Ԫ�أ���һ��������ɾ������ڵ�
    ms.erase(ms.begin()); //Ҳ�������������
    for (auto i = ms.begin(); i != ms.end(); i ++)
        cout << *i << ' ';
    cout << endl;
    
    ms.clear();
    if (ms.empty())
        puts("��ʱmsΪ��");
    else
        puts("��ʱms��Ϊ��");

    return 0;
}