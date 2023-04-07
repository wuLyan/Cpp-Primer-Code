#include <string>
#include <iostream>
#include <unordered_map> // ������unordered_map �� unordered_multimap
#include <unordered_set> // ������unordered_set �� unordered_multiset

using namespace std;

int main()
{
    unordered_map<string, int> ump1, ump2;

    ump1.insert({"bb", 1});
    ump1.insert({"aa", 10});
    ump1.insert({"aa", 2});
    ump1.insert({"aa", 3}); //������ key �ظ�
    ump1.insert({"dd", 1}); //���� value �ظ�

    //�� [] �����λ�� = �Ҳ�ʱ��������Ӽ�ֵ�Եļ�Ϊ [] ������ڵ�Ԫ�ء�ֵΪ��ֵ��Ҫ���ֵ���͵�Ĭ��ֵ(int ����Ĭ��ֵΪ0)
    int x = ump1["cc"]; 
    cout << x << endl; // 0

    //�� [] �����λ�� = ���ʱ��������Ӽ�ֵ�Եļ�Ϊ [] ������ڵ�Ԫ�أ���ֵΪ = �Ҳ��Ԫ�ء��㷨���ж������ֲ��뷽ʽ
    ump1["bd"] = 6; 
    //����ϣ���в�����Ҫ���ҵ� key ʱ��int ���͵� value Ĭ��ֵΪ0��Ȼ���ڹ�ϣ���м��������ֵ��
    cout << ump1["wy"] - 1 << endl; // -1

    cout << ump1["aa"] << endl; // �����ظ��� key ���룬�Ե�һ�β���ʱ�� value Ϊ׼

    //ʹ�õ��������б�����˵�� unordered_map ά�������������У��Ȳ������ֵ�������Ҳ�����ղ�����Ⱥ�˳������
    // begin ���ص��ǵ�һ����ֵ�Եĵ�ַ��end ���ص������һ����ֵ�Ե���һ����ַ����˿�����Ϊ��ֹ����
    for (auto i = ump1.begin(); i != ump1.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl << endl;

    ump2.insert({"cc", 5});
    ump2.insert({"bc", 3});
    ump2.insert({"ab", 10});
    ump2["ca"] = 8;

    if (ump2.count("cd")) // ��ѯʱ�����Ӧ���� key�������Ǽ�ֵ�ԣ����س��ִ���
        puts("Yes");
    else
        puts("No"); 
    //���ֲ�ѯ��ʽû�о���û�У������� [] ��ѯһ������û�е�������Զ�ʹ�� value ��Ĭ��ֵ���� map ��

    if (ump2["wy"]) //�㷨�����״β�ѯǧ����ʹ�����ַ�ʽ����Ϊ��ѯ���֮��ᵼ���Զ�����
        puts("Yes");
    else
        puts("No");

    //ʹ�õ��������б�����˵�� unordered_map ά�������������У��Ȳ������ֵ�������Ҳ�����ղ�����Ⱥ�˳������
    for (auto i = ump2.begin(); i != ump2.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl;

    //�����������ֻ�ܱȽ���Ȼ���ȣ����ܱȽϴ�С
    if (ump1 == ump2) 
        cout << "ump1 == ump2" << endl;
    else
        cout << "ump1 != ump2" << endl; // ump1 != ump2

    unordered_set<int> s;
    s.insert(1);

    if (s.count(1))
        puts("Yes");
    else
        puts("No");

    return 0;
}