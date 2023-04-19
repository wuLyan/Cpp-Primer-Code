#include <stdio.h>
#include <complex.h>
#include <math.h>

//�������������źŴ�����-��е��ҵ������ �������� ������

double complex DTFT(int L, double *x, double W);
void DTFTR(int L, double *x, int N, complex *X, double wa, double wb);
void DFT(int L, double *x, int N, complex *X);

int main(void) 
{
    return 0;
}

//���ѼӴ��ź�x(n)(n = 0, 1, 2, ..., L-1)��Ƶ��W���ĵ�DTFTƵ���ܶ�ֵ
//�β�x��һ��ָ�룬ָ��һ������ΪL��double������
double complex DTFT(int L, double *x, double W)
{
    complex z, X;

    //�����I��complex.h�ж����������λ
    //z = cexp(cmplx(0, -W)); //z = e^(-jW)
    z = 0 - W * I; //��ȷ�ĳ�ʼ������z�ķ���
    //X = cmplx(0, 0);
    X = 0 + 0 * I; //��ȷ�ĳ�ʼ������X�ķ���

    int n; //ѭ����������
    for (n = L - 1; n >= 0; n --)
    {
        //X = cadd(cmplx(x[n], 0), cmul(z, X)); //cadd �� cmul �������ǿ⺯��
        X = (x[n] + 0 * I) + (z * X); //�������������㷽��ͬʵ��
    }
    //��ѭ���������������Ӵ������е��κ�һ�㶼��Ӱ��õ��Ƶ���ܶ�ֵ

    return X;
}

//Ƶ�ʷ�Χ[wa, wb]���ȷֲ��ŵ�N�����DTFTƵ���ܶ�ֵ
//�β�x��һ��ָ�룬ָ��һ������ΪL��double������
//�β�X��һ��ָ�룬ָ��һ������ΪN��complex������
void DTFTR(int L, double *x, int N, complex *X, double wa, double wb)
{
    double dw = (wb - wa) / (N - 1); //��Ƶ�ʷ�Χ[wa, wb]���ȷֲ��ŵ�N�����Ƶ�ʼ��

    int k; //ѭ����������
    for(k = 0; k < N; k ++)
        X[k] = DTFT(L, x, wa + k * dw);
}

//�ѼӴ��ź�x(n)(n = 0, 1, 2, ..., L-1)��N��DFT����Ϊ
//�źŵ�DTFT���ο�˹������[0, 2 * pi]��N���ȼ��㴦��Ƶ���ܶ�ֵ
void DFT(int L, double *x, int N, complex *X)
{
    double pi = 4 * atan(1.0); //�Ի��ȱ�ʾ��1�ķ����У�����/4��������ս��Ϊ��

    int k; //ѭ����������
    for(k = 0; k < N; k ++)
        DTFTR(L, x, N, X, 0.0, 2 * pi);
}
