#ifndef __STRBLOBPTR_H__
#define __STRBLOBPTR_H__

#include <vector>
#include <memory>
#include <string>
#include "StrBlob.h"

using namespace std;

// ���ڷ���һ��������Ԫ�صĳ��ԣ�StrBlobPtr�׳�һ���쳣
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
    friend bool nqr(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

    public:
        StrBlobPtr() : curr(0) { }
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

        string &deref() const;
        StrBlobPtr &incr(); //ǰ׺����
        StrBlobPtr &decr(); //ǰ׺�ݼ�

        // �����±��������һ�㶨���������ذ汾
        // һ��������ͨ���ã�һ����const��Ա�����ҷ��س�������
        string &operator[](size_t n) { return (*wptr.lock())[n]; }
        const string &operator[](size_t n) const { return (*wptr.lock())[n]; }

        // ǰ����������ص�����ݼ�����������
        StrBlobPtr &operator++();
        StrBlobPtr &operator--();

        // ���õ����ݼ���������ض����ԭֵ(������ݼ�֮ǰ��ֵ)
        StrBlobPtr operator++(int);
        StrBlobPtr operator++(int);

        // ���ؼӷ��ͼ��������
        StrBlobPtr &operator+=(size_t n);
        StrBlobPtr &operator-=(size_t n);
        StrBlobPtr operator+(size_t n);
        StrBlobPtr operator-(size_t n);

        // ���س�Ա���������
        string &operator*() const {
            auto p = check(curr, "dereference past end");
            return (*p)[curr];
        }
        string *operator->() const {
            // ��ʵ�ʹ���ί�и������������
            return &this->operator*();
        }

    private:
        // �����ɹ�������check()��������һ��ָ��vector��shared_ptr
        shared_ptr<vector<string>> check(size_t, const string &) const;
        
        // ����һ��weak_ptr����ζ�ŵײ��vector���ܻᱻ����
        weak_ptr<vector<string>> wptr;
        size_t curr; //��ǰ�������е�λ��
};

#endif