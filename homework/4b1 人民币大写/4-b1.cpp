/* 2151133 �ﺫ�� ��07 */
#include <iostream>
using namespace std;

void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱��ʲô��˼������˼��
			cout << "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

int main()
{
	cout << "������[0-100��)֮�������:" << endl;
	double i, x, y, a, b, c, d, e, f, g, h, j, k, l, m;
	cin >> i;
	i += 0.005;
	x = i / 1000;
	y = x - (int)x;

	a = (int)x / 1000000;
	b = (int)(x - a * 1000000) / 100000;
	c = (int)(x - a * 1000000 - b * 100000) / 10000;
	d = (int)(x - a * 1000000 - b * 100000 - c * 10000) / 1000;
	e = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000) / 100;
	f = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100) / 10;
	g = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10);
	h = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g) / 0.1;
	j = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g - 0.1 * (int)h) / 0.01;
	k = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g - 0.1 * (int)h - 0.01 * (int)j) / 0.001;
	l = (int)(y * 10000) % 10;
	m = (int)(y * 100000) % 10;

	cout << "��д�����:" << endl;

	if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0 || l != 0 || m != 0) {
		daxie((int)a, (int)a);
		if ((int)a != 0)
			cout << "ʰ";
		daxie((int)b, (int)b);
		if ((int)a != 0 || (int)b != 0)
			cout << "��";

		daxie((int)c, ((int)a != 0 || (int)b != 0)&&(int)d );
		if ((int)c != 0)
			cout << "Ǫ";
		daxie((int)d, (int)e );
		if ((int)d != 0)
			cout << "��";
		daxie((int)e, (int)f );
		if ((int)e != 0)
			cout << "ʰ";
		daxie((int)f, 0);
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			cout << "��";

		daxie((int)g, ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && (int)h);
		if (g != 0)
			cout << "Ǫ";
		daxie((int)h, (int)j);
		if ((int)h != 0)
			cout << "��";
		daxie((int)j, (int)k);
		if ((int)j != 0)
			cout << "ʰ";
		daxie((int)k, 0);
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			cout << "Բ";

		if (m != 0 || l != 0) {
			daxie((int)l,((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) &&(int)m);
			if ((int)l != 0)
				cout << "��";
			daxie((int)m, 0);
			if ((int)m != 0)
				cout << "��";
			else
				cout << "��";
		}
		else
			cout << "��";
	}
	else 
		cout << "��Բ";

	cout << endl;
	return 0;
}