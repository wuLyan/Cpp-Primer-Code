#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include <map>
#include <set>

using namespace std;

void runQueries(ifstream &infile);

vector<string> file;
map<string, set<int>> wm;

class QueryResult;

class TextQuery
{
    public:
        TextQuery(ifstream &infile);
        QueryResult query(const string &str) const; //Ϊ�˴�����ض����Ϣ�ͱ����и������洢��Щ��Ϣ
    private:
        shared_ptr<vector<string>> file;
        map<string, shared_ptr<set<int>>> wm;
        string remove_punc(string &s);
};

class QueryResult
{
    public:
        QueryResult(string s, shared_ptr<set<int>> p, shared_ptr<vector<string>> f) : str(s), lines(p), file(f) {}
        friend ostream &print(ostream &os, const QueryResult &qr);
    private:
        string str;
        shared_ptr<set<int>> lines;
        shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &infile) : file(new vector<string>) //��new���ص�ָ���ʼ������ָ��
{
    string text;
    while (getline(infile, text))
    {
        file->push_back(text);
        int n = file->size() - 1; //�����к�
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[remove_punc(word)]; //����ֵ��һ������ָ�룬һ��Ҫ�����ý��գ�����ﲻ��������޸�Ч��
            if (!lines) //��һ�����ʵ�һ�γ���ʱ��Ҫ����һ���µ�set(�����ڴ�ռ�)
                lines.reset(new set<int>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    static shared_ptr<set<int>> nodata(new set<int>); //���ٿյ��ڴ�ռ�
    auto loc = wm.find(str);
    if (loc == wm.end()) //��δ���ҵ�keyʱ��find()��������β������
        return QueryResult(str, nodata, file); //����QueryResult��Ĺ��캯������������������ͬ
    else
        return QueryResult(str, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.str << " occurs " << qr.lines->size() << " times" << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}

int main(int argc, char *argv[]) // ./a.exe book.txt
{
    ifstream infile;
    infile.open(argv[1]);

    runQueries(infile);

    return 0;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

string TextQuery::remove_punc(string &s)
{
    string result;
    for (auto c : s)
    {
        if (!ispunct(c))
            result += c;
    }
    return result;
}