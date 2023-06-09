#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    public:
        HasPtr() {}

        // ���β���ĳ�����͵�����ʱ��ͨ�����ֳ������û��Ƿǳ������ù�������
        // HasPtr(string &s = string()) : ps(new string(s)), i(0) { } //�βθ���Ĭ��ʱ���ɵ���ʱ����Ϊ��ֵ�����������͵ı���Ϊ��ֵ����ֵ�޷��󶨵���ֵ�����Իᱨ��
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) { } //���⣺const����ֵ���ÿ��԰󶨵���ֵ

        // ���β���ĳ�����͵�ָ��ʱ��ͨ�����ֳ���ָ�뻹�Ƿǳ���ָ�빹������
        HasPtr(string *ptr = new string()) : ps(ptr), i(0) { }
        // HasPtr(const string *ptr = new string()) : ps(ptr), i(0) { }

        HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { } //�������캯��
        HasPtr &operator=(const HasPtr &); //������ֵ�����

        HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = nullptr; p.i = 0; } //�ƶ����캯��
        HasPtr &operator=(HasPtr &&) noexcept; //�ƶ���ֵ�����

        // ʹ����Ԫ����swap�ĸ�ֵ���������ֵ���ݲ��������ں�������
        // ���ǿ�����ֵ������������ƶ���ֵ�������������ʵ��ʹ��ʱ����ɶ����Ե���
        // HasPtr &operator=(HasPtr rhs) { swap(*this, rhs); return *this; }

        // ��������������Ϊ��Ԫ����
        friend void swap(HasPtr &lhs, HasPtr &rhs);

        ~HasPtr() { delete ps;} //��������

        // ���ɺ�������
        void show() { cout << "non-const show(): " << *ps << endl;}
        void show() const { cout << "const show(): " << *ps << endl;}
    private:
        string *ps;
        int i;
};

// ������ֵ�������������������Ϳ������캯���Ĺ���
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

// �ƶ���ֵ���������������������ƶ����캯���Ĺ���
HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if (this != &rhs)
    {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    // HasPtr hp; //��HasPtr�������Ĭ�Ϲ��캯�������Իᱨ��
    HasPtr hp1("Hello World!");
    hp1.show();
    const HasPtr hp2("Good morning!");
    hp2.show();

    HasPtr hp3("Good luck!");
    // �ڲ����������Ե��õ�ǰ���£�1)���ÿ�����ֵ�������2)���ø�ֵ��������غ�������ֵ���ݲ�����ʹ�ÿ������캯������hp3
    hp1 = hp3; //��ֵ���Ը�����ֵ��Ҳ���԰�ֵ���ݸ��β�(��ֵ)
    // �ڲ����������Ե��õ�ǰ���£�1)�����ƶ���ֵ�������2)���ø�ֵ��������غ�������ֵ���ݲ�����ʹ���ƶ����캯���ƶ�hp3
    hp1 = std::move(hp3); //��ֵ���Ը�����ֵ���ã����԰��մ��ݸ��β�(��ֵ)
    // ��Ϊ��ֵ���ݲ����������Ǵ������µ���ʱ����

    return 0;
}