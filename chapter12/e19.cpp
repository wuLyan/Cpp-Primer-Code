#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class StrBlobPtr; //ǰ������

class StrBlob
{
    friend class StrBlobPtr; //����Ϊ��Ԫ�࣬����StrBlobPtr�����StrBlob���˽�г�Ա
    private:
        shared_ptr<vector<string>> data;
        void check(vector<string>::size_type i, const string &msg) const;
    public:
        StrBlob();
        StrBlob(initializer_list<string> il); //�ɱ�����β�
        vector<string>::size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();
        string &front();
        string &back();
        const string &front() const;
        const string &back() const;
        StrBlobPtr begin() { return StrBlobPtr(*this); }
        StrBlobPtr end();
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(vector<string>::size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob"); //����Ƿ�Ϊ��
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob"); //����Ƿ�Ϊ��
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob"); //����Ƿ�Ϊ��
    return data->back();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob"); //����Ƿ�Ϊ��
    return data->front();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob"); //����Ƿ�Ϊ��
    return data->back();
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

//����ָ�������ָ��ײ������е�ĳ��Ԫ�أ�������ָ����������
class StrBlobPtr
{
    private:
        weak_ptr<vector<string>> wptr;
        vector<string>::size_type curr;
        shared_ptr<vector<string>> check(vector<string>::size_type, const string &msg) const; //ע�ⷵ������
    public:
        StrBlobPtr() : curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        //������캯����д��������һ��StrBlob��������ø�ֵ��StrBlobPtr��������β��Ƿ� const ���͵�
        string &deref() const; //������
        StrBlobPtr &incr(); //ǰ׺����
};

shared_ptr<vector<string>> StrBlobPtr::check(vector<string>::size_type i, const string &msg) const
{
    auto ret = wptr.lock(); //���vector�Ƿ񻹴���
    if (!ret)
        throw runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
    //lock()�����ķ���������shared_ptr<vector<string>>
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end"); //���vector�Ƿ񻹴���
    return (*p)[curr]; //(*p)�Ƕ�����ָ���vector
    //����ָ��p��������shared_ptr<vector<string>>
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr"); //���vector�Ƿ񻹴���
    ++curr;
    return *this; //����ָ����ָ��Ķ��󣬼�StrBlobPtr������
}

int main()
{
    StrBlob b1;

    { //��������
        StrBlob b2 = {"a", "an", "the"}; //��������ʽ����ת��
        b1 = b2; //�����ĸ�ֵ�������˽�����ݳ�Ա��ֵ��˽�����ݳ�Ա������ָ�룬Ҳ��������ָ��ĸ�ֵ
        //���b1��b2����ͬһ��vector<string>����
        b2.push_back("Hello");
        cout << b2.size() << endl;
    } //���������뿪b2��������ʱ��b2�����٣�����b1��Ȼ���Է���b2�е�Ԫ��
    
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    return 0;
}