#include <iostream>

using namespace std;

class nf 
{
    public:
        nf();
        ~nf();
    public:
        int * get();
        void set(int i);
    private:
        int * pi;
};

nf::nf()
{
       cout << "nf construction" << endl;
       pi = new int(0);
}

nf::~nf()
{
       cout << "nf destruction" << endl;
       delete pi;
}

int * nf::get()
{
           return pi;
}

void nf::set(int i)
{
        *pi = i;
}

int main()
{
    nf* pnf = new nf();
    pnf->set(100);
    int *pp = pnf->get();
    cout << *pp << endl;
    //delete pnf;
    free(pnf);
    cout << *pp << endl;
    return 0;
}

/*
1) : new�����ִ�з����ڴ桢�������deleteִ�����������ͷ��ڴ�����
2) : �������free�ͷ�delete���ٵ��ڴ棬ֻ���ͷ��ڴ�������������� 
    �ڹ��캯������������ڴ���Ϊû�е����������������Ը��ڴ沢û�б��ͷ�
*/