//���ڣ�20221120
//���ݣ�������������Ԫ�صĵ�ַ
#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};

    //���ֵһ���������岻һ��
    cout << arr << endl; //���������е�һ��Ԫ�صĵ�ַ
    cout << &arr << endl; //������������ĵ�ַ

    //���ֵ��һ��������Ҳ��һ��
    cout << arr + 1 << endl;  //ָ����һ�����ֽڵĵ�ַ
    cout << &arr + 1 << endl; //ָ����һ��ʮ�����ֽڵĵ�ַ

    return 0;
}