#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool divided_all(vector<int>& ivec, int div)
{
    // return any_of(ivec.begin(), ivec.end(), bind1st(modulus<int>(), div));
    return any_of(ivec.begin(), ivec.end(), bind(modulus<int>(), _1, div));
    // ���ֲ�ͬ��д�����ֱ�ʹ���˲�ͬ�Ŀ⺯��
}

int main()
{
    return 0;
}