#include <iostream>

using namespace std;

class Y; //ǰ������

class X
{
    private:
        Y *y;
};

//Y������X֮����ܶ���X�Ķ���
class Y
{
    private:
        X x;
};

int main()
{
    return 0;
}