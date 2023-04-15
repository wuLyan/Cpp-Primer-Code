#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l = {10};

    /*
    auto it = v.end() - 3;
    cout << *it << endl;
    */
    /*
    auto it1 = back_inserter(v);
    *it1 = 100;
    //it1 = 100; //����д������֣����ǲ��ᱨ��
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;
    */

    // back_inserter���÷�
    /*
    copy(v.begin(), v.end(), back_inserter(l));
    for(const auto &r : l)
        cout << r << " ";
    cout << endl;
    */

    // front_inserter���÷�
    /*����vector��Ϊ������push_front()���������Բ���ʹ��front_inserter
    auto it2 = front_inserter(v);
    *it2 = 100;
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;
    */
    /*
    auto it2 = front_inserter(l);
    *it2 = 100;
    for(const auto &r : l)
        cout << r << " ";
    cout << endl;
    */

    // inserter���÷�
    /*
    auto it3 = v.end() - 3;
    cout << *it3 << endl;
    auto it4 = inserter(v, it3);
    *it4 = 100;
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;
    */
    copy(v.begin(), v.end(), inserter(l, l.begin()));
    for(const auto &r : l)
        cout << r << " ";
    cout << endl;
    
    return 0;
}