#ifndef __E49_H__
#define __E49_H__

#include <string>
#include <iostream>
#include <memory>

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
        StrVec(StrVec &&) noexcept; //�ƶ����캯��
        StrVec &operator=(const StrVec &); //������ֵ�����
        StrVec &operator=(StrVec &&rhs) noexcept; //�ƶ���ֵ�����
        ~StrVec();
        void push_back(const string &);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements;}
        string *begin() const { return elements; }
        string *end() const { return first_free; }
};

#endif