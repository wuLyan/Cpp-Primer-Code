#include <iostream>

using namespace std;

class Empty
{

};

// ��������ȼ���
/*
class Empty
{
  public:
    Empty();                            //ȱʡ���캯��
    Empty(const Empty &rhs);            //�������캯��
    ~Empty();                           //�������� 
    Empty& operator=(const Empty &rhs); //������ֵ�����
    Empty* operator&();                 //ȡַ�����
    const Empty* operator&() const;     //ȡַ�����(const�汾)
};
*/

int main()
{
    // ʵ����һ������Ķ���֮������������Ա�������ᱻͳһ��������ʹʲôҲ����
    Empty *e = new Empty();    //ȱʡ���캯��
    delete e;                  //��������
    Empty e1;                  //ȱʡ���캯��                               
    Empty e2(e1);              //�������캯��
    e2 = e1;                   //������ֵ�����
    Empty *pe1 = &e1;          //ȡַ�����(��const)
    const Empty *pe2 = &e2;    //ȡַ�����(const)

    return 0;
}

// ȱʡ��Ա�����ľ���ʵ�����£�
/*
inline Empty::Empty()                          //ȱʡ���캯��
{
}

inline Empty::~Empty()                         //��������
{
}

inline Empty *Empty::operator&()               //ȡַ�����(��const)
{
    return this; 
}

inline const Empty *Empty::operator&() const    //ȡַ�����(const)
{
    return this;
}

inline Empty::Empty(const Empty &rhs)           //�������캯��
{
    // ����ķǾ�̬���ݳ�Ա������"��ԱΪ��λ"��һ��������
    // �̶����͵Ķ��󿽱������Ǵ�Դ����Ŀ������"��λ"����
}
 
inline Empty& Empty::operator=(const Empty &rhs) //��ֵ�����
{
    // ����ķǾ�̬���ݳ�Ա������"��ԱΪ��λ"��һ��ֵ
    // �̶����͵Ķ���ֵ�Ǵ�Դ����Ŀ������"��λ"��ֵ��
}
*/