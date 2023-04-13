#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

int main()
{
    list<int> l;
    for(size_t i = 0; i != 4; i ++) //size_t���ͣ����������ص��޷�����������
        l.push_front(i); //��ͷ������
    for(const auto &r : l)
        cout << r << " ";
    cout << endl;

    vector<int> v;
    for(size_t i = 0; i != 4; i ++)
        v.push_back(i); //vector��������push_front
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;

    //ʹ��insert��beginʵ��������push_front�Ĺ���
    int n = 3;
    while(n--)
        v.insert(v.begin(), 5); //�ڸ����ĵ�����֮ǰ����Ԫ��
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;

    v.insert(v.end(), 6, 6);
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;

    list<string> sl = {"hello", "world", "good"};
    sl.push_front("morning");
    auto iter = sl.begin();
    string word;
    while(cin >> word)
        iter = sl.insert(iter, word); //����ָ�����Ԫ�صĵ�����
    for(const auto &r : sl)
        cout << r << " ";
    cout << endl;


    return 0;
}