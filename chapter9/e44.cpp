#include <string>
#include <iostream>

using namespace std;

void replace_str(string &s, const string &s1, const string &s2);

int main()
{
    string str = "tho"; //Ŀ�꣺tho -> though

    replace_str(str, "tho", "though");
    cout << str << endl;

    return 0;
}

void replace_str(string &s, const string &s1, const string &s2)
{
    auto pos = s.find(s1); //���������г��ֵ�λ��
    s.replace(pos, s1.size(), s2);
}