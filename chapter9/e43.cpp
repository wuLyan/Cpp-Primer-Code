#include <string>
#include <iostream>

using namespace std;

void replace_str(string &s, const string &s1, const string &s2);

int main()
{
    string str = "tho"; //Ŀ�꣺tho -> though
    cout << 1 << endl;

    replace_str(str, "tho", "though");
    cout << str << endl;

    return 0;
}

void replace_str(string &s, const string &s1, const string &s2)
{
    auto iter = s.begin(); //����Ŀ���ַ�������ʼλ��

    while(iter < s.end())
    {
        auto iter1 = iter;
        auto iter2 = s1.begin();
        while(*iter2 == *iter1 && iter2 != s1.end()) //s1��s��һ���֣����Կ϶����ȵ���ĩβ
        {
            iter1++, iter2++;
        }
        if(iter2 == s1.end()) //�ҵ���Ҫ�滻��Ŀ��������
        {
            iter = s.erase(iter, iter1); //����ҿ��ĵ���������
            auto iter3 = s2.end(); //�Ӻ���ǰ����
            do
            {
                iter3--;
                iter = s.insert(iter, *iter3);
            }while(iter3 > s2.begin());
            iter += s2.size(); //�����²�����ַ�����Ѱ���Ƿ�����һ��Ŀ��������
        }
        else //����һ���ַ���ʼ���±Ƚ�Ŀ��������
            iter++;
    }
}