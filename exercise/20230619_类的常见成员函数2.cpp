#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>

using namespace std;

class StrVec
{
    private:
        string *elements;
        string *first_free;
        string *cap;
        allocator<string> alloc;
        
        // �����ڴ�ռ䲢����������Χ�ڵ�Ԫ�أ�������ָ���¿ռ�Ŀ�ʼλ�úͿ�����β��λ�õ�ָ�빹�ɵ�pair
        pair<string *, string *> alloc_n_copy(const string *, const string *); 
        void free(); //�������ٹ����Ԫ�ز��ͷ��ڴ�
        void reallocate(); //���ڴ�����ʱ���·����ڴ棬����ԭ��Ԫ��ʱʹ���ƶ����캯��
        void chk_n_alloc() //����Ƿ�������һ��������Ԫ�صĿռ�
        {
            if (size() == capacity())
                reallocate();
        }

    public:
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { } //Ĭ�Ϲ��캯�������е�alloc��Աʹ��Ĭ�ϳ�ʼ��
        StrVec(initializer_list<string> il); //�β�������ͬ�������ɱ�Ŀɱ�������캯��

        StrVec(const StrVec &); //�������캯��
        StrVec(StrVec &&) noexcept; //�ƶ����캯��
        StrVec &operator=(const StrVec &); //������ֵ�����
        StrVec &operator=(StrVec &&) noexcept; //�ƶ���ֵ�����
        StrVec &operator=(initializer_list<string> il);
        // �����βε�������ʲô����ֵ����������붨��Ϊ��Ա����

        ~StrVec(); //��������

        // ͬʱ�ṩ�����汾���ƶ��汾�ĳ�Ա����
        void push_back(const string &);
        void push_back(string &&);

        // ��ȡ������Ԫ�������������ĳ�Ա����
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements;}

        // ����ָ����Ԫ�غ�β��Ԫ�صĵ�����
        string *begin() const { return elements; }
        string *end() const { return first_free; }

        // �����ڴ������صĳ�Ա����
        void reserve(size_t n); //Ԥ��������������n��Ԫ�ص��ڴ�ռ�(���ܸ���)
        void resize(size_t n); //�ı�������Ԫ�ص����������nС�ڵ�ǰ��С��ɾ�������Ԫ�أ�������β�����Ĭ�ϳ�ʼ����Ԫ��

        // �±������[]��������Ϊ��ĳ�Ա�������ұ��뷵��������Ԫ�����͵����ã��������ĺô��Ƿ���ֵ���Գ����ڵȺŵ�����һ��
        string &operator[](size_t n) { return elements[n]; }
        const string &operator[](size_t n) const { return elements[n]; }
        // ����������������ص��±���������ʱ������������Ԫ�صĳ������ã�ȷ����������صĶ���ֵ
        // ��ֵ(=)���±�([])������( () )����Ա���ʼ�ͷ(->)����������ǳ�Ա

        // ������ȡ�����������������ϣ��������������жԳ��Բ�������˱��붨��Ϊ��Ԫ����
        friend bool operator==(const StrVec &, const StrVec &);
        friend bool operator!=(const StrVec &, const StrVec &);

        // ���ع�ϵ�����������ϣ��������������жԳ��Բ�������˱��붨��Ϊ��Ԫ����
        // �������˼·������ֶ��Ƚ������е�ÿ��string
        friend bool operator<(const StrVec &, const StrVec &);
        friend bool operator<=(const StrVec &, const StrVec &);
        friend bool operator>(const StrVec &, const StrVec &);
        friend bool operator>=(const StrVec &, const StrVec &);
};

pair<string *, string *> StrVec::alloc_n_copy(const string *beg, const string *ed)
{
    string *data = alloc.allocate(ed - beg); //�����ڴ�ռ䱣�������Χ�ڵ�Ԫ��
    return {data, uninitialized_copy(beg, ed, data)};
    // ���ؿ������֮���Ԫ����������
}

void StrVec::free()
{
    if (elements) //���ݸ�deallocate��ָ�������֮ǰĳ��allocate���ص�ָ�룬���Ա����ж�elements�Ƿ�Ϊ��
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        // for_each(elements, first_free, [&](string &s) {alloc.destroy(&s);});
        // ��Ϊ��lambda���ʽ��Ҫ�õ�alloc��Ա���������Ա���ʹ�����ò���thisָ��
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc.allocate(new_capacity);
    
    auto dest = new_data;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest ++, std::move(*elem ++)); //�ڶ������������˻����string���ƶ����캯��
        // alloc.construct(dest ++, *elem ++); //���õ�string�Ŀ������캯��
    
    free(); //һ���ƶ���Ԫ�ؾ��ͷžɵ��ڴ�ռ�
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

// ʹ���ƶ���������reallocate��Ա����
// void StrVec::reallocate()
// {
//     auto new_capacity = size() ? 2 * size() : 1;
//     auto first = alloc.allocate(new_capacity);
//     auto last = uninitialized_copy(make_move_iterator(begin()), 
//                                                     make_move_iterator(end()), first);
//     free();
//     elements = first;
//     first_free = last;
//     cap = elements + new_capacity;
// }

StrVec::StrVec(initializer_list<string> il)
{
    auto new_data = alloc_n_copy(il.begin(), il.end());
    elements = new_data.first;
    cap = first_free = new_data.second;
}

// �������캯��������������ֻ��һ���βΣ��Ҹ��βα�����const���͵����ã�������������ѭ������
StrVec::StrVec(const StrVec &rhs)
{
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    elements = new_data.first; //֮ǰ����Ҫ�ͷ�Դ������ڴ�ռ䣬��Ϊ���Ƕ����ʼ��
    first_free = cap = new_data.second;
}

// �ƶ����캯��������������ֻ��һ���βΣ��Ҹ��βα����Ƿ�const���͵���ֵ���ã���ΪҪ�ı�Դ�����״̬
// �������Ͷ����Ƕ��ڲ����б�֮��ָ��noexcept����ʾ�ú��������׳��κ��쳣
StrVec::StrVec(StrVec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
    // ��Դ����rhs����������״̬������������������ǰ�ȫ��
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //�ͷ�ԭ����ɵ��ڴ�ռ�
    elements = new_data.first;
    cap = first_free = new_data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    // �п��ܴ������ֵ��move���÷��صĽ�������Ա������Ƿ����Ը�ֵ
    if (this != &rhs) //�Ը�ֵ���
    {
        free(); //�ͷ�ԭ����ɵ��ڴ�ռ�
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr; //��Դ�������������״̬������������������ǰ�ȫ��
    }
    return *this;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
    // �������Ը�ֵ�������Ϊ�βε����;����˲����ܳ����Ը�ֵ
    // alloc_n_copy�����ڴ�ռ䲢�Ӹ�����Χ�ڿ���Ԫ��
    auto new_data = alloc_n_copy(il.begin(), il.end());
    free();                     //���ٶ����е�Ԫ�ز��ͷž��ڴ�ռ�
    elements = new_data.first;  //�������ݳ�Ա������ָ�����ڴ�ռ�
    cap = first_free = new_data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free ++, s);
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free ++,std::move(s));
    // ��Ȼ�β�����Ϊ��ֵ���ã�������������ֵ������ڴ��ݸ�construct()����ʱ�������move()����ת��Ϊ��ֵ
}

void StrVec::reserve(size_t n)
{
    if (n <= capacity())
        return; //�������С��������ǰ����ʱ��ʲôҲ����

    auto new_data = alloc.allocate(n); //���Ա����reallocate()���������ڣ����ﲻһ���ǿ���ԭ���������ռ�
    
    auto dest = new_data;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest ++, std::move(*elem ++));  //�ڶ������������˻����string���ƶ����캯��
        // alloc.construct(dest ++, *elem ++); //���õ�string�Ŀ������캯��
    
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + n;
}

void StrVec::resize(size_t n)
{
    if (n > size())
        while (size() < n)
            push_back(" "); //�����ǰ��СС����Ҫ��Ĵ�С�������л����Ĭ�ϳ�ʼ����Ԫ��
    else if (n < size())
        while (size() > n)
            alloc.destroy(--first_free); //�����ǰ��С������Ҫ��Ĵ�С�������ж����Ԫ�ػᱻ����
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (auto it1 = lhs.begin(), it2 = rhs.begin(); 
         it1 != lhs.end() && it2 != rhs.end(); it1 ++, it2 ++)
        {
            if (*it1 != *it2)
                return false;
        }
    
    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //֮ǰ��string����ȣ���ǰstring��С
            return true;
        else if (*it1 > *it2) //֮ǰ��string����ȣ���ǰstring����
            return false;
    }
    // lhs�е�string����rhs�е�string��ȣ��Ҹ���
    if (it1 == lhs.end() && it2 != rhs.end())
        return true;
    return false;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //֮ǰ��string����ȣ���ǰstring��С
            return true;
        else if (*it1 > *it2) //֮ǰ��string����ȣ���ǰstring����
            return false;
    }
    // lhs�е�string����rhs�е�string��ȣ��Ҹ��̻�һ����
    if (it1 == lhs.end())
        return true;
    return false;
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //֮ǰ��string����ȣ���ǰstring��С
            return false;
        else if (*it1 > *it2) //֮ǰ��string����ȣ���ǰstring����
            return true;
    }
    // rhs�е�string����lhs�е�string��ȣ��Ҹ���
    if (it1 != lhs.end() && it2 == rhs.end())
        return true;
    return false;
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //֮ǰ��string����ȣ���ǰstring��С
            return false;
        else if (*it1 > *it2) //֮ǰ��string����ȣ���ǰstring����
            return true;
    }
    // rhs�е�string����lhs�е�string��ȣ��Ҹ��̻�һ����
    if (it2 == rhs.end())
        return true;
    return false;
}

int main()
{
    return 0;
}