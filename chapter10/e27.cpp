#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 2, 4, 4, 6, 7, 7, 9};
    list<int> l;

    unique_copy(v.begin(), v.end(), back_inserter(l)); 
    //ֻ�н�vector���ظ���Ԫ�ط���һ�����ʵ��ȥ�ع���
    for(const auto &r : l)
        cout << r << " ";
    cout << endl;

    return 0;
}