#include <iostream>
#include <cstring>

using namespace std;

class Name
{
    char name[20];
    public:
        Name() //Ĭ�Ϲ��캯��
        {
            strcpy(name, " ");
            cout << '?';
        }
        Name(const char *fname)
        {
            strcpy(name, fname);
            cout << '?';
        }
        void show()
        {

        }
};

int main()
{
    Name names[3] = {Name{"Rick"}, Name{"Jack"}}; 
    //���ս��������'?'����Ϊ�����е����һ��Ԫ�ؽ�ִ��Ĭ�ϳ�ʼ��
    //ǰ����Ԫ��ͨ������ʽ�ء����ù��캯��ִ�г�ʼ��
    return 0;
}