#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> mset = {0, 1, 2, 3, 3, 3, 3, 5, 6, 7, 8, 9};

    auto it1 = mset.lower_bound(3);
    cout << *it1 << endl;

    auto it2 = mset.upper_bound(3);
    cout << *it2 << endl;

    auto it3 = mset.lower_bound(4);
    cout << *it3 << endl;

    auto it4 = mset.upper_bound(3);
    cout << *it4 << endl;
    //���û��Ԫ��������ؼ���ƥ�䣬��lower_bound()��upper_bound()������ȵĵ�����
    //���صĵ�������ָ������ؼ��ֵĲ���㣬�ܱ���������Ԫ��˳��Ĳ���λ��

    return 0;
}