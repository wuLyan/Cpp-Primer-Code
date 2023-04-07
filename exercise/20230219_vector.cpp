#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int len = 5;
    vector<vector<int>> arr;
    vector<int> arr1, arr2, arr3, arr4; //�����ն���

    //��ֵ����һ��ʹ�÷�����������ѯʱ����ָ������
    arr1.resize(len); // ��ʼ����ʽ��vector<int> arr1(len);
    for (int i = 0; i < len; i ++)
    {
        arr1[i] = 2 * i; 
    }
    cout << "��� arr1 �е�Ԫ��: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;
         
    //��ֵ������������Ԫ��ֵ��ͬ�Ķ�̬����
    arr2 = vector<int>(len, 6); // ��ʼ����ʽ��vector<int> arr2(len, 6);
    cout << "��� arr2 �е�Ԫ��: ";
    for (auto &i : arr2)
        cout << i << ' ';
    cout << endl;

    //��ֵ����������δ�Զ�̬����ָ������֮ǰʹ�ÿ⺯��push_back
    //cout << arr.size() << endl; //δָ�����峤��ʱΪ��
    for (int i = 0; i < len; i ++)
        arr3.push_back(2 * i + 1);
    cout << "��� arr3 �е�Ԫ��: ";
    for (auto &i : arr3)
        cout << i << ' ';
    cout << endl;

    //��ֵ�����ģ���Ա��ʼ���б�
    arr4 = {10, -1, 0, 20, 11};
    cout << "��� arr4 �е�Ԫ��: ";
    for (auto &i : arr4)
        cout << i << ' ';
    cout << endl;

    //��άvector��ʼ��
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    arr.push_back(arr4);
    cout << "��ʱarr ��" << arr.size() << "�С�" << arr[0].size() << "��" << endl; 

    //���յ�һ��Ԫ�ص��ֵ�����бȽ�
    if (arr1 < arr2)
        puts("arr1 < arr2");

    //��շ���һ��ʹ�ÿ⺯��clear
    arr2.clear();
    cout << "��ʱ arr2 �е�Ԫ�ظ���Ϊ: " << arr2.size() << ", ";
    if (arr2.empty()) //�⺯��empty��ʱ�临�Ӷ�ΪO(1)
        cout << "��� arr2 Ϊ��" << endl;
    else
        cout << "��� arr2 ��Ϊ��" << endl;

    //��շ�������ʹ�ÿ⺯��pop_back
    for (int i = 0; i < len; i ++)
        arr3.pop_back();
    cout << "��ʱ arr3 �е�Ԫ�ظ���Ϊ: " << arr3.size() << ", ";
    if (arr3.size()) //�⺯��size��ʱ�临�Ӷ�ΪO(1)
        cout << "��� arr3 ��Ϊ��" << endl;
    else
        cout << "��� arr3 Ϊ��" << endl;

    //����
    arr1.insert(arr1.end(), arr4.begin(), arr4.end());
    cout << "����֮�� arr1 �е�Ԫ��: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;

    //��Ϣ
    cout << "arr1 �еĵ�һ��Ԫ����: " << arr1.front() << endl;
    cout << "arr1 �е����һ��Ԫ����: " << arr1.back() << endl;
    cout << "arr1 �е����ֵ��: " << *max_element(arr1.begin(), arr1.end()) << endl;
    cout << "arr1 �е���Сֵ��: " << *min_element(arr1.begin(), arr1.end()) << endl;
    cout << "arr1 �е�Ԫ���ܺ���: " << accumulate(arr1.begin(), arr1.end(), 0.0) << endl;

    //��ת
    reverse(arr1.begin(), arr1.end());
    cout << "��ת֮�� arr1 �е�Ԫ��: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;

    //����
    sort(arr1.begin(), arr1.end());
    cout << "����֮�� arr1 �е�Ԫ��: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;

    //������
    for (auto i = arr1.begin(); i != arr1.end(); i ++)
        cout << *i << ' '; //���������Կ�����һ��ָ��
    cout << endl;

    //����������õ�����������ֻ࣬�������û������
    for (auto i : arr1)
        cout << i << ' ';
    cout << endl;

    return 0;
}
