#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<char> v = {'h', 'e', 'l', 'l', 'o'};
    string str(v.data(), v.size()); //��Ա����data������Ԫ�صĵ�ַ
    cout << str << endl;

    return 0;
}