#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class StrBlob
{
    private:
        shared_ptr<vector<string>> data;
        void check(vector<string>::size_type i, const string &msg) const;
    public:
        StrBlob();
        StrBlob(initializer_list<string> il); //可变参数形参
        vector<string>::size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();
        string &front();
        string &back();
        const string &front() const;
        const string &back() const;
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
    check(0, "pop_back on empty StrBlob"); //检查是否为空
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob"); //检查是否为空
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob"); //检查是否为空
    return data->back();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob"); //检查是否为空
    return data->front();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob"); //检查是否为空
    return data->back();
} 

int main()
{
    StrBlob b1;

    { //新作用域
        StrBlob b2 = {"a", "an", "the"}; //发生了隐式类型转换
        b1 = b2; //类对象的赋值，即类的私有数据成员赋值，私有数据成员是智能指针，也就是智能指针的赋值
        //因此b1和b2共享同一个vector<string>对象
        b2.push_back("Hello");
        cout << b2.size() << endl;
    } //程序运行离开b2的作用域时，b2被销毁，但是b1仍然可以访问b2中的元素
    
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    return 0;
}