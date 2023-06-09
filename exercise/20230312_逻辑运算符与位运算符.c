#include <stdio.h>

#define SIZE 10

int main()
{
    int i = 0;
    char arr[SIZE] = "ABCDEFGhIJ";

    while (i < SIZE && arr[i] != 'E') i++;
    //while (i < SIZE & arr[i] != 'E') i++;

    /*上述两条语句可以达到相同的效果，有如下两个原因/侥幸
    1) 运算符两侧的表达式的值均为0或1，在这种情况下按位与才和逻辑与达到相同的效果
       例如：5 && 10 = 1，5 & 10 = 0101 & 1010 = 0000 = 0
    2) 对于逻辑与运算符，当前面的表达式为假时不再判断后面的表达式，
       因此当 i= 10 时后面的表达式不会执行，也就不会发生数组越界访问的情况
       但对于按位与运算符，当 i = 10 时还会执行后面的表达式，这时就有可能出现数组越界访问的情况
    */

    printf("i = %d\n", i);
    return 0;
}