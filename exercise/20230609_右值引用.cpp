#include <iostream>

using namespace std;

class Example
{
    public:
        Example() { cout << "example constructor" << endl; }
        Example(const Example *ex) { cout << "copy constructor" << endl; }
        ~Example() { cout << "destructor" << endl; }
        Example operator+(Example &other)
        {
            cout << "operator +" << endl;
            return Example();
        }
};

class Another
{
    public:
        Another(const Example &ex) : example(ex) {  }
    private:
        Example example; 
};


int main()
{
    Example ex;
    Another at(ex + ex); 
    // ��Another�Ĺ��캯��������const���ͣ���Ϊ�������ʽ����ֵ��const����ֵ���òſ��԰󶨵���ֵ

    return 0;
}