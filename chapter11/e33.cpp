#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include  <map>

using namespace std;

void word_transform(ifstream &map_file, ifstream &input);
map<string, string> buildMap(ifstream &map_file);
const string &transform(const string &s, const map<string, string> &m);

int main(int argc, char *argv[])
{
    ifstream if_map(argv[1]);
    ifstream if_content(argv[2]);

    if(if_map && if_content)
        word_transform(if_map, if_content);
    else
        cout << "Can't open the files." << endl;

    return 0;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true; //每行的第一个单词没有前导空格
        while(stream >> word)
        {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            
            cout << transform(word, trans_map);
        }
        cout << endl; //完成一行的转换
    }
}

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;

    string key;
    string value;

    //读取每一行的第一个单词存入key中，读取剩余行存入value中
    while(map_file >> key && getline(map_file, value))
    {
        if(value.size() > 1)
            trans_map[key] = value.substr(1); //跨过前导空格
        else
            throw runtime_error("no rule for " + key);
    }

    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if(map_it != m.cend())
        return map_it->second;
    else
        return s;
} 