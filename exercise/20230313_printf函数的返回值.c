#include <stdio.h>

int main()
{
    int i = 43;
    printf("%d\n", printf("%d", printf("%d", i))); //4321(�س�)
    
    /*printf�����ķ���ֵ�Ǵ�ӡ�ַ��ĸ���
    1) printf("%d", i) --> ���43������2
    2) printf("%d", printf("%d", i)) = printf("%d", 2) --> ���432������1
    3) printf("%d\n", printf("%d", printf("%d", i))) = printf("%d\n", 1) --> ���4321������4
    */

    printf("%d\n", 5); //5

    return 0;
}