#ifndef __E43_H__
#define __E43_H__

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <algorithm>

using namespace std;

class StrVec
{
    private:
        string *elements;
        string *first_free;
        string *cap;
        allocator<string> alloc;

        pair<string *, string *> alloc_n_copy(const string *, const string *); //�����ڴ�ռ䲢����������Χ�ڵ�Ԫ��
        void free(); //���ٹ����Ԫ�ز��ͷ��ڴ�
        void reallocate(); //���ڴ�����ʱ���·����ڴ�
        void chk_n_alloc() //����Ƿ�������һ��������Ԫ�صĿռ�
        {
            if (size() == capacity())
                reallocate();
        }
    public:
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
        StrVec(const StrVec &); //�������캯�� 
        StrVec(initializer_list<string> il);
        StrVec &operator=(const StrVec &); //������ֵ�����
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