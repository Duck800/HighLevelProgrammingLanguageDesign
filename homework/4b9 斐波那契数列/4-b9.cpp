/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����fibonacci���еĵ�n���ֵ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int fibonacci(int n)
{
	int i;
	if (n == 1 || n == 2)
		i = 1;
	else
		i = fibonacci(n - 1) + fibonacci(n - 2);
	return i;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����������޸�
***************************************************************************/
int main()
{
	int n, f;
	cout << "������Fibonacci���е�����[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ����ʱ������
	f = fibonacci(n);
	cout << "Fibonacci���е�" << n << "���ֵ : " << f << endl;

	QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������
	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}