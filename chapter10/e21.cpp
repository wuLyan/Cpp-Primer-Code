#include <iostream>

using namespace std;

int main()
{
    int i = 10;

    auto f = [i]() mutable -> bool{
        if(i > 0) 
        {
            i--;
            return false;
        } 
        else 
            return true;};
    
    for(int j = 0; i < 20; j ++)
    {
        if(f())
            break;
        cout << i << endl; //lambda���ʽ�е�i��һ�����������������ã��������Ϊ10
    }

    return 0;
}