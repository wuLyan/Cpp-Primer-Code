#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char s1[] = "hello ";
    const char s2[] = "world";

    char *p = new char(strlen(s1) + strlen(s2) + 1);

    strcpy(p, s1); //�����ַ���
    strcat(p, s2); //׷���ַ���

    cout << p << endl;

    delete [] p;

    return 0;
}