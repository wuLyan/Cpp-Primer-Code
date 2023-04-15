#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(int i, const string &str);
void biggies(vector<int> &v, const string &s);

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    biggies(v, "Hello");

    return 0;
}

void biggies(vector<int> &v, const string &s)
{
    auto it = find_if(v.begin(), v.end(), bind(check_size, _1, s));
    //find_if�������ص��ǵ�һ������ν�������ĵ�����
    cout << *it << endl;
}

bool check_size(int i, const string &str)
{
    return i > str.size();
}