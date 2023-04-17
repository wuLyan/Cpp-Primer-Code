#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str = "A string with % may not work.\n";

    printf("%s", str); //��%s����ַ����������A string with % may not work.
    printf(str); //�����A string with may not work.
    //�����÷�Ҳ�Ƿ��Ϲ淶�ģ����ǻᷢ�����벻���Ĵ������Բ����Ƽ�

    char *str2 = "i want to print %d\n";
    printf("%s", str2);
    printf(str2); // �����i want to print 1337215536

    //�������
    puts("---------------");
    printf("%d\n", sizeof(str)); //���8���������ָ�뱾����ռ�ڴ�Ĵ�С
    printf("%d\n", sizeof(*str)); //���1���������ָ��ָ����ڴ�Ĵ�С��
                                           //char��ָ�뵱Ȼָ���ǵ����ַ��������������ַ���
    int len = strlen(str); //����strlenҪ����Ĳ�����const char *���ͣ����������str�ǺϷ��ģ������ܴ���*str
    printf("%d\n", len); //���30��strlen��������ַ����ĳ��ȣ�������'\0'
    //printf("%d\n", strlen(str)); //����д�ᱨ��ģ���Ϊ����strlen�ķ�������Ϊsize_t
                                   //��printf�ĸ�ʽ���ַ����е�%dֻ�ܽ���int���͵Ĳ���

    return 0;
}