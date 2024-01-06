/*2151133 Ëïº«ÑÅ ĞÅ07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "ÇëÊäÈë[0..100 ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
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

	cout << "´óĞ´½á¹ûÊÇ:" << endl;
	if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0 || l != 0 || m != 0) {
		if (a != 0 || b != 0) {
			switch ((int)a) {
			case 1:
				cout << "Ò¼Ê°";
				break;
			case 2:
				cout << "·¡Ê°";
				break;
			case 3:
				cout << "ÈşÊ°";
				break;
			case 4:
				cout << "ËÁÊ°";
				break;
			case 5:
				cout << "ÎéÊ°";
				break;
			case 6:
				cout << "Â½Ê°";
				break;
			case 7:
				cout << "ÆâÊ°";
				break;
			case 8:
				cout << "°ÆÊ°";
				break;
			case 9:
				cout << "¾ÁÊ°";
				break;
			}
			switch ((int)b) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			}
			cout << "ÒÚ";
		}
		/*ÒÚ*/
		switch ((int)c) {
		case 0:
			if (((int)a != 0 || (int)b != 0) && ((int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0))
				cout << "Áã";
			break;
		case 1:
		    cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
		}

		switch ((int)d) {
		case 0:
			if ((int)c != 0 && ((int)e != 0 || (int)f != 0 || (int)g != 0))
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
		}
		switch ((int)e) {
		case 0:
			if ((int)d != 0 && (int)f != 0)
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
		}
		switch ((int)f) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			cout << "Íò";
		/*Íò*/
		switch ((int)g) {
		case 0:
			if (((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && ((int)h != 0 || (int)j != 0 || (int)k != 0))
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
		}

		switch ((int)h) {
		case 0:
			if ((int)g != 0 && ((int)j != 0 || (int)k != 0))
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
		}
		switch ((int)j) {
		case 0:
			if ((int)h != 0 && (int)k != 0)
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
		}
		switch ((int)k) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			cout << "Ô²";
		/*Ô²*/
		switch ((int)l) {
		case 0:
			if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) {
				if ((int)m == 0)
					cout << "Õû";
				else
					cout << "Áã";
			}
			break;
		case 1:
			cout << "Ò¼½Ç";
			break;
		case 2:
			cout << "·¡½Ç";
			break;
		case 3:
			cout << "Èş½Ç";
			break;
		case 4:
			cout << "ËÁ½Ç";
			break;
		case 5:
			cout << "Îé½Ç";
			break;
		case 6:
			cout << "Â½½Ç";
			break;
		case 7:
			cout << "Æâ½Ç";
			break;
		case 8:
			cout << "°Æ½Ç";
			break;
		case 9:
			cout << "¾Á½Ç";
			break;
		}
		switch ((int)m) {
		case 0:
			if ((int)l != 0)
				cout << "Õû";
			break;
		case 1:
			cout << "Ò¼·Ö";
			break;
		case 2:
			cout << "·¡·Ö";
			break;
		case 3:
			cout << "Èş·Ö";
			break;
		case 4:
			cout << "ËÁ·Ö";
			break;
		case 5:
			cout << "Îé·Ö";
			break;
		case 6:
			cout << "Â½·Ö";
			break;
		case 7:
			cout << "Æâ·Ö";
			break;
		case 8:
			cout << "°Æ·Ö";
			break;
		case 9:
			cout << "¾Á·Ö";
			break;
		}
	}
	else
	cout << "ÁãÔ²";

	return 0;
}
