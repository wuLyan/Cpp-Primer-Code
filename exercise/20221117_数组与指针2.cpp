//���ڣ�20221117
//���ݣ�������ָ����±�������ʽ
#include <iostream>

using namespace std;

int main()
{
    int n[3] = {1, 2, 3};
    int *pn = n; //������������int *��������int�������ڴ󲿷�����¿�����Ϊpn = n

    cout << "Part1: --------" << endl; //�ò��־��������n�еڶ���Ԫ�ص�����
    cout << n[1] << endl;
    cout << pn[1] << endl;
    cout << *(n + 1) << endl;
    cout << *(pn + 1) << endl;

    cout << "Part2: --------" << endl; //�ò��־��������n�еڶ���Ԫ�صĵ�ַ
    cout << &n[1] << endl;
    cout << &pn[1] << endl;
    cout << (n + 1) << endl;
    cout << (pn + 1) << endl;

    cout << "Part3: --------" << endl;
    cout << n << endl; //�����������n�е�һ��Ԫ�صĵ�ַ����&n[1]��ͬ
    cout << n + 1 << endl;
    cout << &n << endl; //��25�����������ֵ��ͬ������������岻ͬ�����д��������������ĵ�ַ
    cout << &n + 1 << endl; //�����һ��ʮ���ֽڵ���ʼλ��
    cout << pn << endl;
    cout << pn + 1 << endl;
    cout << &pn << endl; //����Ľ������ָ�뱾��ĵ�ַ
    cout << &pn + 1 << endl; //������˵����ָ��ռ�˸��ֽ�
    cout << sizeof(pn) << endl; //��֤������Ľ���

    cout << "Part4: --------" << endl; //�ò��־��������n�е�һ��Ԫ�ص�����
    cout << *n << endl;
    cout << *pn << endl;
    cout << **&n << endl;
    cout << **&pn << endl;

    return 0;
}