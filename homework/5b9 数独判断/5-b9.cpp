/*2151133 �ﺫ�� ��07*/
#include <iostream>
using namespace std;

void tell(int num[3][3], int a)
{
	int i, j, k, l;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = i + 1; k < 3; k++) {
				for (l = j + 1; l < 3; l++) {
					if (num[i][j] == num[k][l])
						a++;
				}
			}
		}
	}
}

int main()
{
	int one[3][3], two[3][3], three[3][3], four[3][3], five[3][3], six[3][3], seven[3][3], eight[3][3], nine[3][3];
	int sudoku[9][9] = { one[3][3],two[3][3], three[3][3], four[3][3], five[3][3], six[3][3], seven[3][3], eight[3][3], nine[3][3] };
	int i, j, k;
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (i = 0; i < 9; ) {
		for (j = 0; j < 9; ) {
			cin >> sudoku[i][j];
			if (cin.good() == 0) {
				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else if (sudoku[i][j] > 9 || sudoku[i][j] < 0) {
				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
				continue;
			}
			j++;
		}
		i++;
	}
	int a = 0;
	/*�ж���*/for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = j + 1; k < 9; k++) {
				if (sudoku[i][j] == sudoku[i][k]) {
					a++;
					break;
				}
			}
		}
	}
	/*�ж���*/for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = j + 1; k < 9; k++) {
				if (sudoku[j][i] == sudoku[k][i]) {
					a++;
					break;
				}
			}
		}
	}
	if (a != 0)
		cout << "���������Ľ�" << endl;

	/*�жϾŹ���*/else {
		tell(one, a);
		tell(two, a);
		tell(three, a);
		tell(four, a);
		tell(five, a);
		tell(six, a);
		tell(seven, a);
		tell(eight, a);
		tell(nine, a);
		if (a != 0)
			cout << "���������Ľ�" << endl;
		else
			cout << "�������Ľ�" << endl;
	}
}