#include <iostream>

using namespace std;

class Example
{
    public:
        Example() { cout << "example constructor" << endl; }
        Example(const Example &ex) 
        { 
            cout << "Copy constructor for Example" << endl; 
        }
        Example(Example &&ex)
        {
            cout << "Move constructor for Example" << endl;
        }
        ~Example() { cout << "destructor" << endl; }
        Example operator+(Example &other)
        {
            cout << "operator +" << endl;
            return Example(); //Ĭ�Ϲ��캯����������ֵʱ������ÿ������캯��
        }
        Example test() //��������Ϊ���������͵ĺ���������ֵ����ֵ����ֵ��ֵ���֮��������������
        {
            cout << "test function" << endl;
            return Example(); //Ĭ�Ϲ��캯����������ֵʱ������ÿ������캯��
        }
};

class Another
{
    public:
        // Another(const Example &ex) {  } //�Գ�Ա����example����Ĭ�Ϲ��캯��
        
        Another(const Example &ex) : example(ex) 
        { 
            cout << "Copy constructor for Another" << endl;
        }
        Another(Example &&ex) : example(std::move(ex)) 
        { 
            cout << "Move constructor for Another" << endl;
        } 
        // �Գ�Ա����example���ÿ������캯��������ɳ�ʼ��֮����ֵ����������˻������������
    private:
        Example example; //ע�Ȿ��Ķ�������ʱҲ����ó�Ա������������������
};


int main()
{
    Example ex; //Ĭ�Ϲ��캯��
    Another at(ex + ex); //�ӷ���������غ���
    // ��Another�Ĺ��캯��������const���ͣ���Ϊ�������ʽ����ֵ��const����ֵ���òſ��԰󶨵���ֵ

    // ex = ex + ex;
    // �ڸ���ֵ��ֵ���֮�󣬵��üӷ���������غ�����������ʱ��ֵҲ�����������Ҳ�������������

    // Example ex1 = ex.test();
    // Example ex2 = ex; //�������캯��

    return 0;
}