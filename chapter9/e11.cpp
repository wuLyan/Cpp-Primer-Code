#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec1; //������
    vector<int> ivec2(ivec1); //��������
    vector<int> ivec3{1, 2, 3, 4, 5}; //�б��ʼ��
    vector<int> ivec4(ivec3.begin(), ivec3.end()); //��������Χ����
    vector<int> ivec5(6); //����6��Ԫ�ص�������ÿ��Ԫ�ؾ�Ϊ0
    vector<int> ivec6(7, 8); //����7��Ԫ�ص�������ÿ��Ԫ�ؾ�Ϊ8

    return 0;
}