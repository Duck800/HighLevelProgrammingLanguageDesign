/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������[0..100 ��)֮�������:" << endl;
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
		if (a != 0 || b != 0) {
			switch ((int)a) {
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
			}
			switch ((int)b) {
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
			}
			cout << "��";
		}
		/*��*/
		switch ((int)c) {
		case 0:
			if (((int)a != 0 || (int)b != 0) && ((int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0))
				cout << "��";
			break;
		case 1:
		    cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		}

		switch ((int)d) {
		case 0:
			if ((int)c != 0 && ((int)e != 0 || (int)f != 0 || (int)g != 0))
				cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		}
		switch ((int)e) {
		case 0:
			if ((int)d != 0 && (int)f != 0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		}
		switch ((int)f) {
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
		}
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			cout << "��";
		/*��*/
		switch ((int)g) {
		case 0:
			if (((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && ((int)h != 0 || (int)j != 0 || (int)k != 0))
				cout << "��";
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		}

		switch ((int)h) {
		case 0:
			if ((int)g != 0 && ((int)j != 0 || (int)k != 0))
				cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		}
		switch ((int)j) {
		case 0:
			if ((int)h != 0 && (int)k != 0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		}
		switch ((int)k) {
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
		}
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			cout << "Բ";
		/*Բ*/
		switch ((int)l) {
		case 0:
			if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) {
				if ((int)m == 0)
					cout << "��";
				else
					cout << "��";
			}
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 9:
			cout << "����";
			break;
		}
		switch ((int)m) {
		case 0:
			if ((int)l != 0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�Ʒ�";
			break;
		case 9:
			cout << "����";
			break;
		}
	}
	else
	cout << "��Բ";

	return 0;
}
