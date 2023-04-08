#include <forward_list>
#include <iostream>

using namespace std;

int main()
{
    forward_list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = l.begin();
    auto cur = l.before_begin();

    while(cur != l.end())
    {
        if(*cur % 2 != 0)
        {
            //ע���Ա����insert_after()���صĵ�������ָ���λ��
            cur = l.insert_after(pre, *cur);
            pre = cur;
            cur++; 
        }
        else
            cur = l.erase_after(pre);
    }

    for(const auto &r : l)
        cout << r << " ";
    cout << endl;

    return 0;
}