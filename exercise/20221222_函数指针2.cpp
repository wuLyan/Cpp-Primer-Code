//���ڣ�20221222
//���ݣ�����ָ�롢����ָ�����顢ͨ������ָ����ú����ķ���
#include <iostream>

using namespace std;

const double *f1(const double ar[], int n);
const double *f2(const double *ar, int n);
const double *f3(const double [], int);
const double *f4(const double *, int n);
/*
�ں���ԭ���У������б�const double ar[]��const double *ar�ĺ�����ȫ��ͬ
���ں���ԭ���У�����ʡ���β��������const double ar[]��const double []��ͬ��const double *ar��const double *��ͬ
���������������ĸ�����������(����������������)��ȫ��ͬ�����main�������ڶ��庯��ָ��ʱ��ʹ��ͳһ�ĸ�ʽ
*/

int main()
{
    double arr[4] = {1112.3, 1542.6, 2227.9, 2248.5};

    //�����ĸ�����ָ�룬��C++11֮�󣬿���ʹ���Զ������ƶϣ�auto p1 = f1;
    const double *(*p1)(const double [], int) = f1;
    const double *(*p2)(const double [], int) = f2;
    const double *(*p3)(const double [], int) = f3;
    const double *(*p4)(const double [], int) = f4;

    //ͨ������ָ����ú��������ַ�ʽ��ָ����(�β�)��(*ָ����)(�β�)
    cout << "Using pointers to function: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    cout << p1(arr, 4) << ": " << *p1(arr, 4) << endl;
    cout << (*p2)(arr, 4) << ": " << *(*p2)(arr, 4) << endl;
    cout << p3(arr, 4) << ": " << *p3(arr, 4) << endl;
    cout << (*p4)(arr, 4) << ": " << *(*p4)(arr, 4) << endl;

    //�Զ������ƶ�ֻ�����ڵ�ֵ��ʼ���������������б��ʼ��

    //���庯��ָ�����飬��ͨ�������±������ķ�ʽ���ú��������ﲻ��ʹ���Զ������ƶ�
    const double *(*pa[4])(const double *, int) = {f1, f2, f3, f4};
    cout << "\nUsing an array of pointers to function: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    for (int i = 0; i < 4; i ++)
        //cout << pa[i](arr, 4) << ": " << *pa[i](arr, 4) << endl;
        cout << (*pa[i])(arr, 4) << ": " << *(*pa[i])(arr, 4) << endl;

    //����ָ����ָ���ָ�룬��ͨ����һ��ȡָ�����ݵڶ��������±������ķ�ʽ���ú������������ʹ���Զ������ƶ�
    const double *(**pb)(const double *, int) = pa;
    cout << "\nUsing a pointer to an array of function pointers: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    for (int i = 0; i < 4; i ++)
        //cout << pb[i](arr, 4) << ": " << *pb[i](arr, 4) << endl;
        cout << (*pb[i])(arr, 4) << ": " << *(*pb[i])(arr, 4) << endl;

    //����ָ����ָ�������ָ��
    const double *(*(*pc)[4])(const double *, int)= &pa;
    cout << "\nUsing a pointer to an array of function pointers: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    for (int i = 0; i < 4; i ++)
        //cout << (*pc)[i](arr, 4) << ": " << *(*pc)[i](arr, 4) << endl;
        cout << (*(*pc)[i])(arr, 4) << ": " << *(*(*pc)[i])(arr, 4) << endl;

    return 0;
}

//�ں���ԭ���п���ʡ���β��������ں��������в���ʡ��
const double *f1(const double ar[], int n)
{
    return ar;
}

const double *f2(const double *ar, int n)
{
    return ar + 1;
}

const double *f3(const double ar[], int)
{
    return ar + 2;
}

const double *f4(const double *ar, int n)
{
    return ar + 3;
}