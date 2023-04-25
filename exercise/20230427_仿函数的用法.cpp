#include <iostream>
#include <string>

using namespace std;

class Hasher
{
    public:
        Hasher() {
            cout << "Hasher()" << endl;
        }
        Hasher(string str) {
            cout << "Hasher(string)" << endl;
        }
        size_t operator()(const string &str) const {
            cout << "operator=()" << endl;
            //Ϊ��ʹ�÷º����ͱ�������()�����
        }
};

int main()
{
    Hasher h("Hello World!");
    h("Good morning!"); //������һ��ʹ����Ķ���
    Hasher()("Good morning!"); //������ʱ���������� 

    return 0;
}