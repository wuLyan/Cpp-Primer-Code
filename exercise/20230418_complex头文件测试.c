#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    double complex z = 1.0 + 1.0 * I;
    double complex result = cexp(z); //�Ը���z������eΪ�׵�ָ������
    // z = x + jy  result = e^(x + jy) = e^x * e^(jy) = e^x * (cos(y) + j * sin(y)) (x��yΪʵ�����������Ǻ���ʱ�ĵ�λΪ����)
    printf("cexp(%.1f + %.1fi) = %.2f + %.2fi\n", creal(z), cimag(z), creal(result), cimag(result));
    return 0;
}