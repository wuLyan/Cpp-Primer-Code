#include <iostream>
#include <string>

using namespace std;

int main()
{
    char ch;
    string s1 = "hello";
    string s2 = "world";
    string s3;

    //������һ��ʹ���±��������
    ch = s1[0];
    cout << ch << endl;

    int len = s1.size();
    cout << "s1�ĳ���Ϊ: " << len << endl;
    
    //�㷨�ⳣ�ü��ɣ��ַ�ת��Ϊ����
    for (int i = 0; i < len; i ++)
        cout << s1[i] - 'a' << ' ';
    cout << endl;

    s3 = s1 + s2; //�����ַ�������
    cout << s3 << endl;
    s3 += "oo";   //���µ��ַ�������
    cout << s3 << endl;
    s3 += '!';    //���µ��ַ�����
    cout << s3 << endl;
    //s3 += 666;  //���������Ȼ������
    s3 += to_string(666); //��int����ת��Ϊstring���Ͳ������
    cout << s3 << endl;

    cout << s1.substr(1, 2) << endl; // �ӵڶ���Ԫ��(�±��0��ʼ)��ʼ���س���Ϊ 2 ���Ӵ�
    //��Ҫ�󷵻صĳ��ȴ���ʣ���ַ���ȫ����������굱ǰ�ַ���Ϊֹ����ʡ�Գ��Ȳ�������Ҳ�Ǵ�ָ��λ�ÿ�ʼ�����굱ǰ�ַ���Ϊֹ

    printf("%s\n", s1.c_str()); //�⺯�� c_str �����ַ������ͷָ��

    s1.clear(); //���Ԫ��
    if (s1.empty()) //�ж��Ƿ�Ϊ��
        cout << "s1Ϊ��" << endl;

    //���ַ����е�����ת��Ϊint����
    cout << 1 + stoi("666") << endl; //���667
    cout << 1 + "666" << endl; //���66.����֣�

    return 0;
}