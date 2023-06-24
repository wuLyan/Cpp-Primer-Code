#ifndef __STRBLOB_H__
#define __STRBLOB_H__

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);

    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);

    public:
        StrBlob();
        StrBlob(initializer_list<string> il); //�ɱ�����β�
        vector<string>::size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        
        // ��Ӻ�ɾ��Ԫ��
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();

        // Ԫ�ط��ʣ���Ա�����Ƿ�Ϊ const Ҳ��������
        string &front();
        string &back();
        const string &front() const;
        const string &back() const;

        StrBlobPtr begin();
        StrBlobPtr end();

        // �����±��������һ�㶨���������ذ汾
        // һ��������ͨ���ã�һ����const��Ա�����ҷ��س�������
        string &operator[](size_t n) { return (*data)[n]; }
        const string &operator[](size_t n) const { return (*data)[n]; }
    
    private:
        shared_ptr<vector<string>> data; //ָ�����ַ���������������ָ��
        void check(vector<string>::size_type i, const string &msg) const;
};

#endif