//���֪ʶ����C++ Primer P81
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "Hello", s2 = "World"; //�ַ�������ֵ������ʽת��Ϊstring����
    cout << s1 << ' ' << s2 << endl; //���Hello World
    cout << "Hello" << ' ' << "World" << endl; //���Hello World
    cout << *"Hello" << ' ' << *"World" << endl; //���H W����˵���ַ�������ֵ�ı�����ָ�룬�����޷�ȡ����

    //����string�����ַ�������ֵ���ַ�����ֵ����һ�������ʹ��ʱ������ȷ��ÿ���ӷ��������������������������һ������string����
    string s3 = s1 + "!"; //��string�������ַ�������ֵ��ӣ����ɷ�������ʽ����ת��
    cout << s3 << endl; 
    string s4 = "@" + s2 + "@"; //��string�������ַ�������ֵ��ӣ����ɷ�������ʽ����ת��
    cout << s4 << endl; 
    //string s5 = "Hello" + "World"; //��������������󶼲���string
    string s6 = s1 + "!" + "!"; //��ȷ���൱��s5 = (s1 + "!") + "!"
    cout << s6 << endl; 

    return 0;
}