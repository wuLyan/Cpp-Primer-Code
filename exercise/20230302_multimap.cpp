#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    multimap<string, int> mmp;

    mmp.insert({"bb", 4});
    mmp.insert({"aa", 2});
    mmp.insert({"aa", 1});
    mmp.insert({"aa", 3});

    //ʹ�õ��������б�����˵�� multimap ά�����ǵ������У����յ�һ�ؼ��ֵ��ֵ����������
    //����һ�ؼ�����ͬ����ڶ��ؼ��ְ��ղ����˳���������
    for (auto i = mmp.begin(); i != mmp.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    
    //cout << mp["aa"] << endl; // ��Ϊ multimap ���������ظ�Ԫ�س��֣�������ֲ�ѯ��ʽ�п��ܻ���������Ψһ�������﷨����ȷ

    return 0;
}