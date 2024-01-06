/*2151133 �ﺫ�� ��07*/
/*2151134 ���淰 2154057 ����� 2154310 ������ 2152362 ��ͤ�� 2153069 ���� 2151780 Ԭ�h 2152817 �����*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

/*��ӡ��б��*/const char backslash = 92;

//transform to hex
void transform(int n, char* p)
{
	if (n < 16){
		if (n < 10)
			*p = n + '0';
		else
			*p = n - 10 + 'a';
	}
	else{
		int tmp = n % 16;
		transform(n / 16, p++);
		if (tmp < 10)
			*p = tmp + '0';
		else
			*p = tmp - 10 + 'a';
	}
}

int main(int argc, char* argv[])
{
	//1.open the file(in1)
	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "    a.hex                    : ����·����ʽ" << endl;
	cerr << "    .." << backslash << "data" << backslash << "b.txt          : ���·����ʽ" << endl;
	cerr << "    C:" << backslash << "Windows" << backslash << "System32" << backslash << "c.hex : �������·����ʽ" << endl;
	cerr << "������Ҫת����hex��ʽ�ļ��� :";
	char before[7777];
	cin >> before;
	cerr << "������ת������ļ���        :";
	char after[7777];
	cin >> after;

	
	ifstream in1(before, ios::in);
	if (!in1.is_open())
		cout << "�����ļ�" << before << "��ʧ�ܣ�" << endl;
	else {
		ofstream out(after, ios::out|ios::binary);
		in1.close();
		//1.end(in1)
		//2.compare the offset(in2)
		ifstream in2(before, ios::in | ios::binary);
		int count, i, copy, copy_2, gps = 0;
		char copy_1;
		while (in2.peek() != EOF) {
			int x, m, y;
			char a[8] = { '0','0','0','0','0','0','0','0' };
			transform(gps, a);
			if (gps == 0)
				in2.seekg(-1, ios::cur);
			for (x = 0; x < 8; x++) {
				if (in2.get() != '0') {
					in2.seekg(-1, ios::cur);
					break;
				}
			}
			for (y = x; y < 8; y++) {
				int ch = in2.get();
				if (in2.good()) {
					if (ch != (int)a[y - x]) {
						if (ch + 32 == (int)a[y - x])
							continue;
						else {
							cout << "������ƫ����0x";
							in2.seekg(-y, ios::cur);
							for (m = 0; m < 8; m++) {
								cout << (char)in2.get();
							}
							cout << "��������ֵ0x";
							cout << hex << setfill('0') << setw(8) << gps << "  ";
							cout << endl;
							return 0;
						}
					}
				}
				else
					break;
			}
			for (count = 0; count < 17; count++) {
				for (i = 0; i < 2; ) {
					copy = in2.get();
					if (copy == ' ' || copy == '-')
						continue;
					else
						i++;
					if (i == 1)
						gps++;
				}
			}
			in2.seekg(16, ios::cur);
			gps--;
		}
		in2.close();
		//2.end(in2)
		//3.read,swap and write
		ifstream in(before, ios::in | ios::binary);
		while (in.peek() != EOF) {
			in.seekg(10, ios::cur);
			for (count = 0; count < 16; count++) {
				for (i = 0, copy_1 = 0, copy_2 = 0; i < 2; ) {
					copy = in.get();
					if (copy != EOF) {
						if (copy >= 'a' && copy <= 'f')
							copy -= 87;
						else if (copy >= 'A' && copy <= 'F')
							copy -= 55;
						else if (copy >= '0' && copy <= '9')
							copy -= 48;
						else if (copy == ' ' || copy == '-')
							continue;
						if (i == 0)
							copy_2 += copy * 16;
						else if (i == 1) {
							copy_2 += copy;
							copy_1 = copy_2;
							if (copy_2 < 257 && copy_2 >= 0)
								out << copy_1;
							copy_2 = 0;
						}
						i++;
					}
					else
						break;
				}
			}
			in.seekg(22, ios::cur);
			if (in.get() < 0)
				break;
		}
		in.close();
		out.close();
	}
	//3.end
	return 0;
}
