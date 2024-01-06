/* 2151133 孙韩雅 信07 */
#include <iostream>
using namespace std;

void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
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

	cout << "大写结果是:" << endl;

	if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0 || l != 0 || m != 0) {
		daxie((int)a, (int)a);
		if ((int)a != 0)
			cout << "拾";
		daxie((int)b, (int)b);
		if ((int)a != 0 || (int)b != 0)
			cout << "亿";

		daxie((int)c, ((int)a != 0 || (int)b != 0)&&(int)d );
		if ((int)c != 0)
			cout << "仟";
		daxie((int)d, (int)e );
		if ((int)d != 0)
			cout << "佰";
		daxie((int)e, (int)f );
		if ((int)e != 0)
			cout << "拾";
		daxie((int)f, 0);
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			cout << "万";

		daxie((int)g, ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && (int)h);
		if (g != 0)
			cout << "仟";
		daxie((int)h, (int)j);
		if ((int)h != 0)
			cout << "佰";
		daxie((int)j, (int)k);
		if ((int)j != 0)
			cout << "拾";
		daxie((int)k, 0);
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			cout << "圆";

		if (m != 0 || l != 0) {
			daxie((int)l,((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) &&(int)m);
			if ((int)l != 0)
				cout << "角";
			daxie((int)m, 0);
			if ((int)m != 0)
				cout << "分";
			else
				cout << "整";
		}
		else
			cout << "整";
	}
	else 
		cout << "零圆";

	cout << endl;
	return 0;
}