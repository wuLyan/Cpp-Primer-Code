#ifndef __E40_H__
#define __E40_H__

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>

using namespace std;

class StrVec
{
    private:
        string *elements;
        string *first_free;
        string *cap;
        allocator<string> alloc;

        pair<string *, string *> alloc_n_copy(const string *, const string *); //分配内存空间并拷贝给定范围内的元素
        void free(); //销毁构造的元素并释放内存
        void reallocate(); //在内存用完时重新分配内存
        void chk_n_alloc() //检查是否至少有一个容纳新元素的空间
        {
            if (size() == capacity())
                reallocate();
        }
    public:
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
        StrVec(const StrVec &); //拷贝构造函数 
        StrVec(initializer_list<string> il);
        StrVec &operator=(const StrVec &); //拷贝赋值运算符
        ~StrVec();
        void push_back(const string &);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements;}
        string *begin() const { return elements; }
        string *end() const { return first_free; }
        void reserve(size_t n);
        void resize(size_t n);
};

#endif