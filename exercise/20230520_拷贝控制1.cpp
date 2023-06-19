#include <iostream>
#include <vector>

using namespace std;

class A
{
    public:
        A()
        {
            cout << "class create" << endl;
        }
        A(const A &a)
        {
            cout << "class copy" << endl;
        }
        A &operator=(const A &a)
        {
            cout << "override operator= " << endl;
            return *this;
        }
        ~A() //������������ִ�к����壬�����ٳ�Ա
        {
            cout << "class destroy" << endl;
        }
};

void f1(A a)
{
    cout << "f1 without ref A" << endl;
}

void f2(A &a)
{
    cout << "f2 with ref A" << endl;
    //��ָ��һ������������뿪������ʱ�����������������
}

int main()
{
    A a; //Ĭ�Ϲ��캯��

    f1(a); //�������캯�� -> ��������
    f2(a); //������ÿ������캯����Ҳ���������������
    // ��ָ��һ����������û�ָ���뿪������ʱ�����������������

    A *pa = new A(a); //�������캯��
    delete pa; //��������

    vector<A> vec(3); //��ֻ�����Ĭ�Ϲ��캯����������ÿ������캯��
    cout << "Size = " << vec.size() << ", Capacity = " << vec.capacity() << endl;
    // �ڶ�vector�������ݵĹ����У��µ��ڴ�ռ��е�Ԫ�شӾ��ڴ�ռ��е�Ԫ�ؿ������������Ȼ���ٵ����������������ڴ�ռ��е�Ԫ��������
    vec.push_back(a); //�������캯�����������á��������б���ʼ��һ�������е�Ԫ�زŻ���ÿ������캯��
    cout << "Size = " << vec.size() << ", Capacity = " << vec.capacity() << endl;

    return 0; //��a����������������vec�е�Ԫ�ص�����������
}