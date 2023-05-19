#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    allocator<string> alloc;
    auto const p = alloc.allocate(100); //�����ڴ�

    string s;
    string *q = p;
    while(cin >> s && q != p + 100)
        alloc.construct(q++, s); //�������

    const size_t size = q - p;
    for (int i = 0; i < size; i ++)
        cout << p[i] << " ";
    cout << endl;

    while(q != p)
        alloc.destroy(--q); //���ٶ���
    alloc.deallocate(p, 100); //�ͷ��ڴ�

    return 0;
}