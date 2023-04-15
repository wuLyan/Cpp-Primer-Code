#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void eliDups(vector<string> &words);
void biggies(vector<string> &words, vector<string>::size_type sz);
bool check_size(const string &str, string::size_type sz);

int main()
{
    vector<string> v = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(v, 4);

    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    eliDups(words); //�����ֵ�������ȥ��
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size();}); //���ճ������򲢱����ֵ��򲻱�
    //auto wc = partition(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz;}); //�ҵ���һ�����ȴ��ڵ���Ŀ�곤�ȵ�Ԫ��
    //auto count = wc - words.begin(); //ʹ�õ������ļ������м���
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz)); //�ҵ���һ�����ȴ��ڵ���Ŀ�곤�ȵ�Ԫ��
    auto count = wc - words.begin(); //ʹ�õ������ļ������м���
    cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), wc, [](const string &s) {cout << s << " ";}); //Ϊ��ʹ��lambda���ʽ������ʹ��for_each������ʹ�÷�Χfor���
    cout << endl;
}

void eliDups(vector<string> &words)
{
    for_each(words.begin(), words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;

    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;
}

bool check_size(const string &str, string::size_type sz)
{
    return str.size() >= sz; 
}