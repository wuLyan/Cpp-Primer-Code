//���ڣ�20221219 
//���ݣ�ָ�볣��
#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int m = 100;
    int *const pt = &n; //��������һ��������ֻ�������������������ָ��

    cout << "1):n = " << n << endl;

    *pt = 20; //����ͨ��ָ���޸���ָ������ֵ
    cout << "2):n = " << n << endl;

    //pt = &m; //�������޸�ָ��ָ�������ڴ�λ��
    cout << "*pt = " << *pt << endl;

    return 0;
}