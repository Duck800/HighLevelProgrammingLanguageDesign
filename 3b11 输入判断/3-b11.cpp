/*2151133 �ﺫ�� ��07*/
#include <iostream>
using namespace std;
int main()
{
	int x;
	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			while (getchar() != '\n')
				continue;
		}
		else if (x >= 0 && x <= 100) {
			break;
		}
		else
			continue;
	}
	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}