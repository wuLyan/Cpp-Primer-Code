//���ڣ�20221121
//���ݣ�ָ��Ӽ�����
#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
    int *pa = arr;

    cout << arr << endl;
    cout << pa << endl;

    pa = pa + 2;
    cout << pa - arr << endl; //������ͬ���͵�ָ����ܽ����������
    
    return 0;
}