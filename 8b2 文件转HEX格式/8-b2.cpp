/*2151133 孙韩雅 信07*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

/*打印反斜杠*/const char backslash = 92;

int main(int argc, char* argv[])
{
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.txt                    : 不带路径形式" << endl;
	cerr << "    .." << backslash << "data" << backslash << "b.dat          : 相对路径形式" << endl;
	cerr << "    C:" << backslash << "Windows" << backslash << "System32" << backslash << "c.dat : 绝对相对路径形式" << endl;
	cerr << "请输入文件名 :";

	char str[16000];
	cin >> str;
	ifstream in(str, ios::in | ios::binary);
	if (!in.is_open())
		cout << "输入文件" << str << "打开失败！" << endl;
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