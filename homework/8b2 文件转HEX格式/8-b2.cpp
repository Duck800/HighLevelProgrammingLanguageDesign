/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

/*��ӡ��б��*/const char backslash = 92;

int main(int argc, char* argv[])
{
	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "    a.txt                    : ����·����ʽ" << endl;
	cerr << "    .." << backslash << "data" << backslash << "b.dat          : ���·����ʽ" << endl;
	cerr << "    C:" << backslash << "Windows" << backslash << "System32" << backslash << "c.dat : �������·����ʽ" << endl;
	cerr << "�������ļ��� :";

	char str[16000];
	cin >> str;
	ifstream in(str, ios::in | ios::binary);
	if (!in.is_open())
		cout << "�����ļ�" << str << "��ʧ�ܣ�" << endl;
	else {
		while (in.peek()!=EOF) {
			int count, gps, i;
			for (count = 0, gps = 0; count < 17;) {
				unsigned char copy_1 = in.get();
				if (in.good()) {
					if (count == 0)
						cout << hex << setfill('0') << setw(8) << gps << "  ";
					else if (count == 8 && in.peek() != EOF)
						cout << "- ";
					else if (count == 16) {
						in.seekg(-17, ios::cur);
						cout << "    ";
						for (i = 0; i < 16; i++) {
							char copy_2 = in.get();
							if (copy_2 > 32 && copy_2 < 127)
								cout << copy_2;
							else
								cout << ".";
						}
						cout << endl;
						count = 0;
						continue;
					}
					cout << hex << setfill('0') << setw(2) << (unsigned int)copy_1 << " ";
					count++;
					gps++;
				}
				else {
					in.clear();
					in.ignore();
					if (count <= 8)
						cout << setw((16 - (long long)count) * 3 + 2) << setfill(' ') << "";
					else
						cout << setw((16 - (long long)count) * 3) << setfill(' ') << "";
					cout << "    ";
					in.seekg(-(long long)count, ios::cur);
					for (i = 0; i < 16; i++) {
						char copy_2 = in.get();
						if (copy_2 > 32 && copy_2 < 127)
							cout << copy_2;
						else if (in.eof())
							break;
						else
							cout << ".";
					}
					break;
				}
			}
			in.close();
			cerr << endl;
			break;
		}
	}
	return 0;
}
/*C:\Users\pc\Desktop\test1.txt*/