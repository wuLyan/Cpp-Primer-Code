//���ڣ�20221009
//���ݣ��ַ������ͱ���֮����໥ת��
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word1, word2;
    char word3, word4;
    int num1, num2;

    cin >> word1 >> word2; //���԰����ֿ������ַ���
    cin >> word3 >> word4; //���԰�ʮ���ڵ����ֿ����ǵ����ַ�
    cin >> num1 >> num2; //�����ܰ��ַ�ת��Ϊ����

    cout << "Part1: --------" << endl;
    cout << word1 << ' ' << word2 << endl;
    cout << word3 << ' ' << word4 << endl;
    cout << num1 << ' ' << num2 << endl;

    cout << "Part2: --------" << endl;
    //cout << (int)word1 << ' ' << (int)word2 << endl; //�����ԭ����string���Ͳ���ǿ��ת��Ϊint��
    cout << (int)word3 << ' ' << (int)word4 << endl; //����ַ���Ӧ��ASCII��
    cout << (char)num1 << ' ' << (char)num2 << endl; //���ASCII���Ӧ���ַ�

    return 0;
}