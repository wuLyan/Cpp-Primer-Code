#include <stdio.h>
// ���ϵ����2���ݴη���������٣�ֱ�������������������������ѭ��
// �������ٹ����е��ڸ�����������ô���������2���ݴη�������ǳ����ˣ��ǾͲ���

// ʹ��judge�����ж�num�Ƿ�Ϊ2���ݴη�
int judge(int num)
{
	int ret = 1;
	while (ret <= num)
	{
		// ���С�ڣ���˵����û�����
		if (ret < num)
		{
			// ÿ�β���һ��2���ݴη���
			ret *= 2;
		}
		else
		{
			// ��
			return 1;
		}
	}
	// ����
	return 0;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = judge(num);
	if (ret == 1)
	{
		printf("%d ��2���ݴη�\n", num);
	}
	else
	{
		printf("%d ����2���ݴη�\n", num);
	}

	return 0;
}
