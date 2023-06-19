//���ڣ�20221220
//���ݣ����ƹ��캯�����������������������������������ظ�ֵ�����
#include <iostream>
#include <cstring>

using namespace std;

class String
{
    private://������ܵ���˽�г�Ա������ֻ�г�Ա��������
        char *str; //ָ��ֻ����ʵ��������ʱ�Ŷ�̬������ڴ�ռ�
        int len; 
        static int num_strings; //������ж�����һ����̬��Ա����
        static const int SIZE;  //����ھ�̬�洢�����������κ�һ������

    public:
    /*
    һ���Ա������������ѭ����˳�򣺾�̬��Ա���� -> Ĭ�Ϲ��캯�� -> ���ƹ��캯�� -> ����/ת�����캯�� -> ��������
    -> �������� -> һ���Ա���� -> �����������Ա���� -> ��Ԫ����
    */

        // ��̬��Ա�����������κ�һ��������˲���ͨ��ĳһ���������
        // ����Ҫͨ������+��������������(::)���ã�������ͬ�����ʵ��Ǿ�̬��Ա����
        static int Howmany();

        // ���캯���Ķ�����ע�����������Ӱ��ľ�̬��Ա����(num_strings)
        String(); //Ĭ�Ϲ��캯����������β������ȫ������Ĭ�ϲ��������������κ�һ���β�
        String(const char *s); //�вι��캯����û�д�Ĭ�ϲ�������˾��Բ���Ĭ�Ϲ������
        String(const String &st); //�����������ƹ��캯��(�ֳ�Ϊ�������캯��)
        // ��Ա�������ض���(�����Ƕ��������)ʱ����ø��ƹ��캯��������������
        ~String(); //ʹ�ùؼ���new��̬�����ڴ�ʱ������ʽ�������������ͷ��ڴ�

        int length() const {return len;} //������������������ֱ��д������

        void stringlow();
        void stringup();
        int has(char ch) const;

        // ��ֵ�������Ե��ú����Ķ�������޸ģ����ֻ�ܷ��ط�const����
        // Ϊ���������ʹ�ø�ֵ�����ʱ��Ч��(����ʹ�ø��ƹ��캯��)��Ҫ���ط�const���������
        String &operator=(const String &st);
        String &operator=(const char *st);

        char &operator[](int i); //�޸��±�������Ԫ��
        // �Ȳ��޸Ķ���Ҳ���޸��ַ������ǰ��Ҫ��const
        const char &operator[](int i) const; //�����±�������Ԫ��

        // ��Ԫ�������������������Է���˽�г�Ա���������������ϲ��ǳ�Ա����
        // ��Ϊ���ǳ�Ա���������Զ���ʱ����Ҫ�������������������ת��Ϊ�����ĵ��÷�ʽ
        friend bool operator<(const String &str1, const String &str2);
        friend bool operator>(const String &str1, const String &str2);
        friend bool operator==(const String &str1, const String &str2);

        // ����������������ʱ��Ϊ����ʹ��ϰ����ƥ�����ʹ����Ԫ��������
        // Ϊ�˷��㴮��/��������������ʹ�ã�����ʱ���뷵��ostream/istream������������
        // ������Ϊostream/istream��û�й��еĸ��ƹ��캯������˱��뷵�ض�������
        friend ostream &operator<<(ostream &os, const String &st);
        friend istream &operator>>(istream &is, String &st);
        // �������������ʱһ�����漰���޸Ķ������Ҫ����Ķ�������const���� 

        // Ϊ�˱��ּӺ�ʹ��ʱ�Ľ����ɣ���Ҫ�ó�Ա������ǳ�Ա������������
        // �������ӵ������ַ���(���ַ�)�ڼ�������б��ֲ��䣬���Ҫ��const�޶�
        // ������Ϻ󣬺��������ڴ�ż���������ʱ�����Ѳ����ڣ����ֻ�ܷ��ض��󣬶������Ƕ��������
        friend String operator+(const char *s, const String &st);
        String operator+(const String &st) const;
};

// ��ʼ����̬��Ա����ʱ������ʹ�ùؼ���static��ֻ��������������
int String::num_strings = 0;
const int String::SIZE = 80;

int String::Howmany()
{
    return num_strings;  
}

String::String()
{
    num_strings++;
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char *s)
{
    num_strings++;
    len = strlen(s);
    str = new char[len + 1]; //�����㹻�Ŀռ����洢��Ҫ���Ƶ�����
    strcpy(str, s); //�������ݣ��������������ݵĵ�ַ
    /*
    for (int i = 0; i < len; i ++)
        str[i] = s[i];
    */
}

String::String(const String &st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1]; //�����㹻�Ŀռ����洢��Ҫ���Ƶ�����
    strcpy(str, st.str); //�������ݣ��������������ݵĵ�ַ
    /*
    for (int i = 0; i < len; i ++)
        str[i] = st.str[i];
    */
}

// ����Ķ������ý���ʱ(����ִ����ϻ���������ִ�����)�����������ᱻ�Զ�����
// ����ֻ����һ������������������еĹ��캯����������֮����(delete�����Ƿ��[]���������ڿ�ָ��)
String::~String()
{
    num_strings--; //���¾�̬����
    delete []str; 
}

void String::stringlow()
{
    for (int i = 0; i < len; i ++)
        str[i] = tolower(str[i]);
}

void String::stringup()
{
    for (int i = 0; i < len; i ++)
        str[i] = toupper(str[i]);
}

int String::has(char ch) const
{
    int cnt = 0;
    for (int i = 0; i < len; i ++)
        if (str[i] == ch)
            cnt++;

    return cnt;
}

String &String::operator=(const String &st)
{
    if (this == &st)
        return *this; //���������Ҹ�ֵʱֱ�ӷ���
    
    delete []str; //�ͷŴ�������ʱ��Աָ��ָ����ڴ�
    len = st.len;
    str = new char[len + 1]; //�����㹻�Ŀռ����洢��Ҫ���Ƶ�����
    strcpy(str, st.str); //�������ݣ��������������ݵĵ�ַ
    /*
    for (int i = 0; i < len; i ++)
        str[i] = st.str[i];
    */

    return *this; //this��ָ������ָ�룬����Ҫȡ����
}

String &String::operator=(const char *st)
{
    // �β����Ͳ����࣬������������Ҹ��Ƶ����
    delete []str;
    len = strlen(st);
    str = new char[len+ 1];
    strcpy(str, st);
    /*
    for (int i = 0; i < len; i ++)
        str[i] = st.str[i];
    */

    return *this; //this��ָ������ָ�룬����Ҫȡ����
}

char &String::operator[](int i)
{
    return str[i]; //�����õ�����ָ����±�����ԭ��
}

const char &String::operator[](int i) const
{
    return str[i]; //�����õ�����ָ����±�����ԭ��
}

bool operator<(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) < 0);
}

bool operator>(const String &str1, const String &str2)
{
    return str2 < str1; //�õ���Ա������<�����������
}

bool operator==(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

// �������������ʱ����Ҫ���Ķ�����˲��ܼ�const
istream &operator>>(istream &is, String &st)
{
    char temp[String::SIZE];
    is.get(temp, String::SIZE); //�������еĶ�ȡ���뺯��
    // is.getline(temp, String::SIZE);

    if (is)
        st = temp; //�õ�ǰ�渳ֵ�����������
    
    // �������뻺������ʣ�µ�/�Ų��µ��ַ�
    // cin.get()���ڶ�ȡ�����ַ��������ǻ��з�Ҳ���Զ�ȡ
    while (is && is.get() != '\n')
        continue; 
    return is;
}

String operator+(const char *s, const String &st)
{
    String temp;

    temp.len = strlen(s) + st.len;
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, s); //�ַ�����������
    strcat(temp.str, st.str); //�ַ���׷�Ӻ���

    return temp;
}

String String::operator+(const String &st) const
{
    String temp;

    temp.len = len + st.len;
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, str); //�ַ�����������
    strcat(temp.str, st.str); //�ַ���׷�Ӻ���

    return temp;
}

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;

    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A') << " 'A' characters in it.\n";
    s1 = "red";
    
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow();
        for (int i = 0; i < 3; i ++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";

    return 0;
}