//���ڣ�20230102
//���ݣ���Ŀ��Դ��https://www.runoob.com/w3cnote/const-char.html
//�ο���https://blog.csdn.net/u012601587/article/details/50462189

/*
const char *p="hello";       
foo(&p);   
�����к������壺foo(const char **pp)��������˵������ȷ���� (B)
A.����foo()���ܸı�pָ����ַ������ݡ�
B.����foo()����ʹָ��pָ��malloc���ɵĵ�ַ��
C.����foo()����ʹpָ���µ��ַ���������
D.����foo()���԰�p��ֵΪ NULL��
*/

#include <stdio.h>
#include <stdlib.h>

const char *p = "Hello"; //p��ָ��const char���͵�ָ�룬����ζ�Ų���ͨ��ָ��p�޸�����ָ������ֵ
//������ʹָ��pָ�������ַ��������������ڴ洦

void foo(const char **pp) //foo����һ���β�Ϊָ��const char���͵�ָ���ָ��pp�����޷���ֵ�ĺ���
{
    //*pp = p����ָ��const char���͵�ָ��

    //ѡ��A��
    //(*pp)[1] = 'x';

    //ѡ��B��
    //*pp = (char *) malloc(11);
    //snprintf(*pp, 11, "hi google!");

    //ѡ��C��
    //*pp = "Google";

    //ѡ��D��
    //*pp = NULL;
}

int main()
{
    printf("Before foo:  %s\n",p);

    foo(&p);
    printf("After foo:  %s\n",p);

    //p[1] = 'x'; //������ѡ��B���ʹ�ã���ʹ��foo����pָ������malloc���ɵ��ڴ�飬�����Ծɲ����� p[1]='x' ����������޸���ָ�������
    //Gccֻ�Ǹ���const���������˼�����������ƣ�����const char *p������ָ�룬���ܺ���pʵ��ָ��malloc���ڴ���߳������ڴ棬�������� p[1]='x' ����������޸���ָ�������
    //���Ǻ���֣���foo���棬��pָ��malloc���ڴ�󣬿�����snprintf֮��ĺ����޸������ݣ���Ȼ���о��浫���ɿ���ʵ���޸�Ŀ��

    return 0;
}