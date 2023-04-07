#include <map> // ������ map �� multimap
#include <iostream>

using namespace std;

int main()
{
    map<string, int> mp; //map �� multimap ������ͬ set �� multiset �����𣬼� map �в��������ظ��� key ���֣��������һ�β����� value Ϊ��
    // key ������Ϊ string�� value ������Ϊ int�� ���Ҳ����֧������Ƕ��
    // unordered_map �� map �������������е����в�������ģ������ɾ�Ĳ��ʱ�临�Ӷȶ���O(1)

    mp.insert({"wy", 666}); //�������б���ʽ�������
    mp["ly"] = 520; //������һ��ֱ��ͨ�� key ���� value
    mp["hello"] = 1314;
    cout << mp.size() << endl; // 3
    //����ѯ map �в����ڵ� key ʱ��int ���͵� value Ĭ��ֵΪ0�����һὫ����� map ��
    cout << mp["aa"] << endl; // 0

    //ʹ�õ��������б�����˵�� map ά�����ǵ������У����յ�һ�ؼ��ֵ��ֵ����������
    for (auto i = mp.begin(); i != mp.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl;

    mp["hello"] = 666; //������ͬ key �����룬�����һ�ε� value Ϊ����������������ͬ value ����
    for (auto i = mp.begin(); i != mp.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl;

    mp.erase(mp.find("hello")); //�������������ɾ��
    cout << mp.size() << endl; // 2
    mp.erase("wy"); //���� key ����ɾ��
    cout << mp.size() << endl; // 1

    //map֧�ֱȽ�����������յ�һ�ؼ��ֵ�˳���ֵ��������бȽ�
    map<string, int> mp1, mp2;
    mp1.insert({"ky", 520});
    mp2.insert({"ly", 521});
    if (mp > mp1)
        puts("mp > mp1"); // mp > mp1
    else
        puts("mp <= mp1"); 
    if (mp > mp2)
        puts("mp > mp2"); 
    else
        puts("mp <= mp2"); // mp <= mp2

    mp.clear();
    if (mp.empty())
        puts("��ʱmpΪ��"); // ��ʱmpΪ��
    else
        puts("��ʱmp��Ϊ��");

    return 0;
}