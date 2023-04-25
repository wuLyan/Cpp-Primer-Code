#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    multimap<string, string> books;
    books.insert({"Jinyong", "Ludingji"});
    books.insert({"Jinyong", "Shediaoyingxiongzhuan"});
    books.insert({"Gulong", "Xiaollifeidao"});

    for(const auto &r : books)
        cout << r.first << ": ��" << r.second << "��" << endl;

    cout << "Please enter the author whose books you want to remove: " << endl;
    string author;
    cin >> author;

    auto pos = books.equal_range(author);
    if(pos.first == pos.second) //����Ĺؼ��ֲ���map����
        cout << "No books by " << author << endl;
    else
        books.erase(pos.first, pos.second); //ɾ��һ����Χ�ڵ�Ԫ��

    for(const auto &r : books)
        cout << r.first << ": ��" << r.second << "��" << endl;

    return 0;
}