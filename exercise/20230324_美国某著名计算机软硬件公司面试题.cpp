#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct 
{
    short a1;
    short a2;
    short a3;
}A;

struct
{
    long a1;
    short a2;
}B;


int main()
{
    char *ss1 = "0123456789";
    char ss2[] = "0123456789";
    char ss3[100] = "0123456789";
    int ss4[100];

    char q1[] = "abc";
    char q2[] = "a\n";
    char *q3 = "a\n";

    char *str1 = (char *)malloc(100);
    void *str2 = (void *)malloc(100);

    cout << sizeof(ss1) << " "; //���8����Ϊ�������ָ�뱾����ռ�ڴ�ռ�Ĵ�С
    cout << sizeof(ss2) << " "; //���11����Ϊ�������������ռ�ڴ�ռ�Ĵ�С��ע�����ĩβ�Ľ������������������˻�Ϊָ��
    cout << sizeof(ss3) << " "; //���100������ͬ��
    cout << sizeof(ss4) << " "; //���400������ͬ��

    cout << endl;

    cout << sizeof(q1) << " "; //���4
    cout << sizeof(q2) << " "; //���3
    cout << sizeof(q3) << " "; //���8

    cout << endl;

    cout << sizeof(short) << " "; //���2
    cout << sizeof(long) << " ";  //���4
    cout << sizeof(A) << " "; //���6
    cout << sizeof(B) << " "; //���8(2*4=8)

    cout << endl;

    cout << sizeof(str1) << " "; //���8
    cout << sizeof(str2) << " "; //���8

    return 0;
}