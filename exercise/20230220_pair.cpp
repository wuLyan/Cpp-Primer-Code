#include <vector>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<string, string> Author;

int main()
{
    //�����ն���
    pair<string, string> anon;         // ����Ԫ�����Ͷ��� string
    pair<int, string> word_count1;     // ����Ԫ�����ͷֱ��� string �� int
    pair<int, string> word_count2;     // ����Ԫ�����ͷֱ��� string �� int
    pair<int, pair<int, int>> line;    // ����Ԫ�����ͷֱ��� int �� pair(����Ƕ��)

    //�����ͬʱ��ʼ��
    pair<string, string> author("James","Joy"); // ����һ��author��������Ԫ�����ͷֱ�Ϊstring���ͣ���Ĭ�ϳ�ʼֵΪJames��Joy��
    pair<string, int> name_age("Tom", 18);
    pair<string, int> name_age2(name_age); // ���������ʼ��

    //ʹ��typedef������
    Author proust("March", "Proust");
    Author joy("James", "Joy");

    //first �� second �ĵ��ò���()���ֱ����ڷ��ص�һ�ؼ��ֺ͵ڶ��ؼ���
    cout << name_age.first << " is " << name_age.second << " years old." << endl;

    //�����¶���
    anon = {"Hello", "World!"};
    word_count1 = make_pair(5, "Hello");
    word_count2 = make_pair(6, "World!");

    //֧�ֱȽ�����(�ֵ���Ƚ�ԭ����Զ���ؼ��ֱȽϷ�ʽ)��firstΪ��һ�ؼ��֣�secondΪ�ڶ��ؼ���
    if (word_count1 < word_count2)
        puts("word_count1 < word_count2");

    return 0;
}