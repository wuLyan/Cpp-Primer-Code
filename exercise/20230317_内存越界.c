#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *p1 = "wuyan"; //
    char *p2 = (char *)malloc(strlen(p1) + 1);
    //����strlen()�ڼ����ַ�������ʱ�����ĩβ�Ľ�����'\0'��������
    //���Ǻ���strcpy()�ڿ����ַ���ʱ����ͨĩβ�Ľ�����'\0'һ�𿽱�
    //����ڿ����ڴ�ռ�ʱ����Ҫ�࿪��һ���ֽڣ���֤�ַ����н�����
    strcpy(p2, p1);
    printf("%s\n", p2);
    return 0;
}