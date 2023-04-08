#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    //1) ���ļ�
    ifstream ifs("e10.txt");
    if(!ifs)
    {
        cerr << "Failed to open the file!" << endl;
        return -1;
    }

    //2) ��ȡ�ļ�
    vector<string> strs;
    string line;
    while(getline(ifs, line))
        strs.push_back(line);
    ifs.close();

    //3) ��ȡvector
    for(auto s : strs)
    {
        string word;
        istringstream iss(s);
        while(iss >> word)
            cout << word << endl;
    }
    
    return 0;
}