#include "StrBlobPtr.h"

bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
        // ������ָ�붼Ϊ�գ���ָ����ͬԪ��ʱ���������
    else 
        return false; //ָ��ͬ��vectorʱ������
}

bool nqr(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
        // ������ָ�붼Ϊ�գ���ָ����ͬԪ��ʱ���������
    else 
        return false; //ָ��ͬ��vectorʱ������
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //����ָ�붼Ϊ�գ���Ϊ�����
        return (lhs.curr < rhs.curr); //��ָ����ͬ��vectorʱ���Ƚ�ָ���λ��
    }
    else
        return false; //ָ��ͬ��vectorʱ�����ܱȽ�
        
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //����ָ�붼Ϊ�գ���Ϊ�����
        return (lhs.curr <= rhs.curr); //��ָ����ͬ��vectorʱ���Ƚ�ָ���λ��
    }
    else
        return false;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //����ָ�붼Ϊ�գ���Ϊ�����
        return (lhs.curr > rhs.curr); //��ָ����ͬ��vectorʱ���Ƚ�ָ���λ��
    }
    else
        return false;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //����ָ�붼Ϊ�գ���Ϊ�����
        return (lhs.curr >= rhs.curr); //��ָ����ͬ��vectorʱ���Ƚ�ָ���λ��
    }
    else
        return false;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); //��ָ���vector��������
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //(*p)��StrBlobPtr��Ķ�����ָ���vector
}

// ǰ׺���������ص�������������
StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++ curr;
    return *this;
}

// ǰ׺�ݼ������صݼ�����������
StrBlobPtr &StrBlobPtr::decr()
{
    -- curr;
    check(-1, "decrement past begin of StrBlob Ptr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator++()
{
    // ����Ѿ�ָ����������β��λ�ã����޷���������
    check(curr, "increment past end of StrBlobPtr");
    ++ curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    // ���curr��0��������ݼ��������Ч�±�
    -- curr;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this; //��¼ԭֵ������
    ++*this; //����ǰ�õ��������
    return ret;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this; //��¼ԭֵ������
    --*this; //����ǰ�õݼ������
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "decrement past end of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n)
{
    auto ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n)
{
    auto ret = *this;
    ret -= n;
    return ret;
}