#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(5, 2);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;

    v.resize(8);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;

    v.resize(10, -1);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;

    // resize() ֻ��ı���������ЧԪ�ص�����������������ڴ棬��һ��Ҫ�ر�ע��
    v.resize(5);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;
    cout << v.size() << " " << v.capacity() << endl;

    v.resize(0);
    cout << v.size() << " " << v.capacity() << endl;

    return 0;
}