#include <iostream>
#include <fstream> 

using namespace std;

int main()
{
    //ofstream ofs("c2_2.txt", fstream::out); //��out��ʽ���ļ��ᶪ����������
    ofstream ofs("c2_2.txt", fstream::out | fstream::app); //ģʽΪ�����׷��

    return 0;
} 