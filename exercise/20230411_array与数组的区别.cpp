#include <array>
#include <iostream>

using namespace std;

int main()
{
    array<int, 10> arr1 = {1, 2, 3}; //δ��ֵ��Ԫ��ִ��ֵ��ʼ��
    array<int, 10> arr2 = {6, 6, 6};

    for(const auto &r : arr1)
        cout << r << " ";
    cout << endl;

    arr1 = arr2; //������ͬ��array�����໥��ֵ��array�����Ͱ���Ԫ��������������С
    arr2 = {1}; //����ʹ�û������б�Ϊarray��ֵ

    return 0;
}