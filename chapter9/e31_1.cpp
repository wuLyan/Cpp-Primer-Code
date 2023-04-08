#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = l.begin();

    while(iter != l.end())
    {
        if(*iter % 2 != 0)
        {
            iter = l.insert(iter, *iter);
            iter++, iter++; //ע������������Ĳ������ܼӼ�����
            //list�ĵ�����ֻ���������㣬����ֻ�ֿܷ�д����
        }
        else
            iter = l.erase(iter);
    }

    for(const auto &r : l)
        cout << r << " ";
    cout << endl;

    return 0;
}