//���⣺��C��C++�У�free()��delete����β���ָ��̬�����ڴ��ָ��ģ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *p = (char *)malloc(100);
    strcpy(p, "wuyan");
    printf("p = %s\n", p);
    printf("sizeof(p) = %d\n", (int)sizeof(p)); //����ָ��p������ռ�ڴ�ռ�Ĵ�С��������p��ָ����ڴ�ռ�Ĵ�С
    printf("strlen(p) = %d\n", (int)strlen(p)); //strlen()��������һ������


    free(p); //free()��������һ������
    printf("p = %s\n", p);
    if (p != NULL) //C�����У���NULL��ʾ��ָ��
    {
        strcpy(p, "Hello World");
        printf("p = %s\n", p);
    }
    //ͨ�����ϳ�����Կ���������free()ֻ�ǰѶ�̬���ٵ��ڴ��ͷŵ������û���ò�Ҫ��ʹ�ã��п��ܴ�ŵ�������ֵ
    //����ָ����ڴ�ռ��ָ�벻�����ٴ������Ի����ٶ��丳ֵ
    //������������������ȫ��ָ���п���ָ���޷����ʵĿռ䣬���Խ������²���
    p = NULL;

    // new�������졢�ڴ���䡢����ָ��
    // delete�������������ڴ��ͷš�ע�Ⲣ������ָ��
        

    return 0;
}