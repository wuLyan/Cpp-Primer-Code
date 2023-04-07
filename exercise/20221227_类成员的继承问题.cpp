//���ڣ�20221227
//���ݣ����Ա�����ļ̳�����
#include <iostream>
#include <cstring>

using namespace std;

class ABC //����
{
    private:
        char *label;
        int rating;
    public:
        ABC(const char *l = "null", int r = 0); //Ĭ�Ϲ��캯�����˴������βζ���Ĭ�ϲ���
        ABC(const ABC &rs); //���ƹ��캯�������캯���������麯��
        virtual ~ABC(); //��һ�����ǻ���ʱ����������������Ϊ�麯��

        //�������еĳ�Ա����Ϊ�麯��ʱ��ͨ�����û�ָ����øú����������û�ָ��Ķ�������;������û��໹��������ĳ�Ա����
        //�������еĳ�Ա���������麯��ʱ��ͨ�����û�ָ����øú�����ֱ�������ñ����ָ�뱾������;������û��໹��������ĳ�Ա����
        virtual void View() const; 
        //��ֵ������ǳ�Ա������������Ϊ�麯��û�����壬��˲���ͨ�����û�ָ�����
        ABC &operator=(const ABC &s);

        //��Ԫ�������ǳ�Ա����������޷����̳С���������Ϊ�麯��
        friend ostream &operator<<(ostream &os, const ABC &rs);
};

class baseDMA : public ABC //������1���������ಢû�����ר���ĳ�Ա�����������д�ܶ��Ա����
{
    public:
        //���캯���޷����̳У�Ҳ�������麯������ʹ�ó�Ա��ʼ���б�ķ�ʽ���û���Ĺ��캯��
        baseDMA(const char *l = "null", int r = 0);
        baseDMA(const baseDMA &rs); //���ƹ��캯��

        //��Ҫ��д�麯��ʱ��������������������Ҳ���ùؼ���virtual����ǿ�ɶ���
        virtual void View() const;
};

class lacksDMA : public ABC //������2������������Ȼ��ר���ĳ�Ա������������ʹ��new�����µ��ڴ�ռ�
{//��˲���Ҫ��д��ֵ���캯�����������������ظ�ֵ�����
    private:
        enum {COL_LEN = 40};
        char color[COL_LEN];
    public:
        lacksDMA(const char *l = "null", int r = 0, const char *c = "blank");
        lacksDMA(const ABC &rs, const char *c = "blank"); 
        //����һ�����캯����ֻ������һ���β��ǻ�����󣬵ڶ����βδ���һ��Ĭ�ϲ���
        //������Ĭ�Ϲ��캯������ΪĬ�Ϲ��캯��������β���Ӧ�������βζ���Ĭ�ϲ���

        //��Ҫ��д�麯��ʱ��������������������Ҳ���ùؼ���virtual����ǿ�ɶ���
        virtual void View() const;

        //��Ԫ�������ǳ�Ա����������޷����̳С���������Ϊ�麯��
        friend ostream &operator<<(ostream &os, const lacksDMA &rs);
};

class hasDMA : public ABC //������3���������಻����ר���ĳ�Ա����������ʹ��new�����µ��ڴ�ռ�
{//��˱���Ҫ��д��ֵ���캯�����������������ظ�ֵ�����
    private:
        char *style;
    public:
        hasDMA(const char *l = "null", int r = 0, const char *s = "null");
        hasDMA(const ABC &rs, const char *s);
        hasDMA(const hasDMA &rs);
        ~hasDMA();

        //��Ҫ��д�麯��ʱ��������������������Ҳ���ùؼ���virtual����ǿ�ɶ���
        virtual void View() const;
        hasDMA &operator=(const hasDMA &hs);

        //��Ԫ�������ǳ�Ա����������޷����̳С���������Ϊ�麯��
        friend ostream &operator<<(ostream &os, const hasDMA &rs);
};

//���������в�д�βε�Ĭ�ϲ���
ABC::ABC(const char *l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

ABC::ABC(const ABC &rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

ABC::~ABC()
{
    delete []label;
}

//�麯���ĺ��������в���ʹ�ùؼ���virtual
void ABC::View() const
{
    cout << "Label: " << label << endl;
    cout << "Rating: " << rating << endl;
}

//ע������з���ֵ
ABC &ABC::operator=(const ABC &rs)
{
    if (this == &rs)
        return *this;
    delete []label;
    label = new char [strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

//��Ԫ�����ĺ��������в���ʹ�ùؼ���friend
ostream &operator<<(ostream &os, const ABC &rs)
{
    os << "Label: " << rs.label << endl;
    os << "Rating: " << rs.rating << endl;
    return os;
}

//ͨ����Ա��ʼ���б�ķ�ʽ���û���Ĺ��캯������������ͨ���β��б��Զ�ƥ��
baseDMA::baseDMA(const char *l, int r) : ABC(l, r)
{

}

//ͨ����Ա��ʼ���б�ķ�ʽ���û���Ĺ��캯�����ù��캯�����β��ǻ�������ã���˿ɴ���������Ķ���
baseDMA::baseDMA(const baseDMA &rs) : ABC(rs)
{

}

void baseDMA::View() const
{
    ABC::View(); //��������ĳ�Ա�����е��û���ĳ�Ա������������ʽ��ָ��������
}

//ͨ����Ա��ʼ���б�ķ�ʽ���û���Ĺ��캯������������ͨ���β��б��Զ�ƥ��
lacksDMA::lacksDMA(const char *l, int r, const char *c) : ABC(l, r)
{
    strncpy(color, c, COL_LEN - 1);

    //�����ж��������������ʹ����ַ����ĳ��ȣ�ȷ�������Կ��ַ���β
    if (strlen(c) >= COL_LEN)
        color[39] = '\0';
    else
        color[strlen(c)] = '\0';
}

//���βδ������ĸ��ƹ��캯��
lacksDMA::lacksDMA(const ABC &rs, const char *c) : ABC(rs)
{
    strncpy(color, c, COL_LEN - 1);

    //�����ж��������������ʹ����ַ����ĳ��ȣ�ȷ�������Կ��ַ���β
    if (strlen(c) >= COL_LEN)
        color[39] = '\0';
    else
        color[strlen(c)] = '\0';
}

void lacksDMA::View() const
{
    ABC::View(); //��������ĳ�Ա�����е��û���ĳ�Ա������������ʽ��ָ��������
    cout << "Color: " << color << endl;
}

ostream &operator<<(ostream &os, const lacksDMA &rs)
{
    os << (const ABC &)rs; //Ҫʹ�û������Ԫ����������ͨ��ǿ������ת��������������û�ָ��ת��Ϊ��������û�ָ��
    os << "Color: " << rs.color << endl;

    return os; //�����з���ֵ
}

//ͨ����Ա��ʼ���б�ķ�ʽ���û���Ĺ��캯������������ͨ���β��б��Զ�ƥ��
hasDMA::hasDMA(const char *l, int r, const char *s) : ABC(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

//���βδ������ĸ��ƹ��캯��
hasDMA::hasDMA(const ABC &rs, const char *s) : ABC(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

//ͨ����Ա��ʼ���б�ķ�ʽ���û���Ĺ��캯�����ù��캯�����β��ǻ�������ã���˿ɴ���������Ķ���
hasDMA::hasDMA(const hasDMA &hs) : ABC(hs)
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete []style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    
    ABC::operator=(hs); //������ʾ�����û��������صĸ�ֵ�����
    //��������ĳ�Ա�����е��û���ĳ�Ա������������ʽ��ָ��������
    //��ʵ�ڱ���������������������ĺ������ǡ�operator + �������

    delete []style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);

    return *this; //�����з���ֵ
}

ostream &operator<<(ostream &os, const hasDMA &hs)
{
    os << (const ABC &)hs;
    os << "Style: " << hs.style << endl;

    return os; //�����з���ֵ
}

void hasDMA::View() const
{
    ABC::View(); //Ҫʹ�û������Ԫ����������ͨ��ǿ������ת��������������û�ָ��ת��Ϊ��������û�ָ��
    cout << "Style: " << style << endl;
}

int main()
{
    baseDMA shirt("Protabelly", 8);
    cout << "Displaying baseDMA object: " << endl;
    cout << shirt;
    cout << "-------------------" << endl;

    lacksDMA ballon("Blimpo", 4, "red");
    cout << "Displaying lacksDMA object: " << endl;
    cout << ballon;
    cout << "-------------------" << endl;

    lacksDMA ballon2(ballon); //������õ���Ĭ�ϵĸ��ƹ��캯��
    cout << "Result of lacksDMA copy: " << endl;
    cout << ballon2;
    cout << "-------------------" << endl;

    hasDMA map("Keys", 5, "Mercator");
    cout << "Displaying hasDMA object: " << endl;
    cout << map;
    cout << "-------------------" << endl;

    hasDMA map2 = map; //��������Ķ���ĳ�ʼ�����������û���ʽ����ĸ��ƹ��캯��
    cout << "Result of hasDMA copy: " << endl;
    cout << map2;
    cout << "-------------------" << endl;

    hasDMA map3;
    map3 = map; //�����������ĸ�ֵ����������ʽ��������صĸ�ֵ�����
    cout << "Result of hasDMA copy: " << endl;
    cout << map3;
    cout << "-------------------" << endl;

    return 0;
}