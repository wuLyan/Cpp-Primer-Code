#include <iostream>

using namespace std;

class Example
{
    public:
        Example() { cout << "example constructor" << endl; }
        Example(const Example &ex) { cout << "copy constructor" << endl; }
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
        
        Another(const Example &ex) : example(ex) {  } 
        // �Գ�Ա����example���ÿ������캯��������ɳ�ʼ��֮����ֵ����������˻������������
    private:
        Example example; //ע�Ȿ��Ķ�������ʱҲ����ó�Ա������������������
};


int main()
{
    Example ex; //Ĭ�Ϲ��캯��
    Another at(ex + ex); //�ӷ���������غ���
    // ��Another�Ĺ��캯��������const���ͣ���Ϊ�������ʽ����ֵ��const����ֵ���òſ��԰󶨵���ֵ
    // ��Ҳ��Ϊʲô���಻�����ƶ����캯��ʱ��Ҳ����ɡ��ƶ���������ԭ����Ϊ��ֵ���ð��պ������õ�ƥ�����Ҳ���Ե��ÿ������캯��

    ex = ex + ex;
    // �ڸ���ֵ��ֵ���֮�󣬵��üӷ���������غ�����������ʱ��ֵҲ�����������Ҳ�������������

    Example ex1 = ex.test();
    Example ex2 = ex; //�������캯��

    return 0;
}