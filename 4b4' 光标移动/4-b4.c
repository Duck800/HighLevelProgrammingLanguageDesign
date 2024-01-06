/*2151133 �ﺫ�� ��07*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	   /*���п����������20����ĸ����������ӵ�λ���ص�ʱ����������ĸ����20��*/
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
void menu() {
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0-4]");
}

void back(const HANDLE hout, int a) {
	cls(hout);
	menu();
}

void move1(const HANDLE hout, int X, int Y) {
	while (1) {
		int a = _getch();
		if ((a == 76 || a == 108) && X < 69) {
			X += 1;
			gotoxy(hout, X, Y);
		}
		else if ((a == 74 || a == 106) && X > 1) {
			X -= 1;
			gotoxy(hout, X, Y);
		}
		else if ((a == 73 || a == 105) && Y > 0) {
			Y -= 1;
			gotoxy(hout, X, Y);
		}
		else if ((a == 75 || a == 107) && Y < 17) {
			Y += 1;
			gotoxy(hout, X, Y);
		}
		else if (a == 80 && Y < 17) {
			Y += 1;
			gotoxy(hout, X, Y);
		}
		else if (a == 32) {
			showch(hout, X, Y, '\40');
			gotoxy(hout, X, Y);
		}
		else if (a == 81 || a == 113) {
			gotoxy(hout, 0, 22);
			printf("��Ϸ���������س������ز˵�.");
			while (1) {
				int a = _getch();
				if (a == 13) {
					back(hout, a);
					break;
				}
			}
			break;
		}
	}
}

void move2(const HANDLE hout, int X, int Y) {
	while (1) {
		int a = _getch();
		if (a == 76 || a == 108) {
			if (X < 69)
				X += 1;
			else
				X = 1;
			gotoxy(hout, X, Y);
		}
		else if (a == 74 || a == 106) {
			if (X > 1)
				X -= 1;
			else
				X = 69;
			gotoxy(hout, X, Y);
		}
		else if (a == 73 || a == 105) {
			if (Y > 0)
				Y -= 1;
			else
				Y = 17;
			gotoxy(hout, X, Y);
		}
		else if (a == 75 || a == 107) {
			if (Y < 17)
				Y += 1;
			else
				Y = 0;
			gotoxy(hout, X, Y);
		}
		else if (a == 80) {
			if (Y < 17)
				Y += 1;
			else
				Y = 1;
			gotoxy(hout, X, Y);
		}
		else if (a == 32) {
			showch(hout, X, Y, '\40');
			gotoxy(hout, X, Y);
		}
		else if (a == 81 || a == 113) {
			gotoxy(hout, 0, 22);
			printf("��Ϸ���������س������ز˵�.");
			while (1) {
				int a = _getch();
				if (a == 13) {
					back(hout, a);
					break;
				}
			}
			break;
		}
	}
}

void move3(const HANDLE hout, int X, int Y) {
	while (1) {
		switch (_getch()) {
		case 224:
			int a = _getch();
			if (a == 77 && X < 69) {
				X += 1;
				gotoxy(hout, X, Y);
			}
			else if (a == 75 && X > 1) {
				X -= 1;
				gotoxy(hout, X, Y);
			}
			else if (a == 72 && Y > 0) {
				Y -= 1;
				gotoxy(hout, X, Y);
			}
			else if (a == 80 && Y < 17) {
				Y += 1;
				gotoxy(hout, X, Y);
			}
			else if (a == 32) {
				showch(hout, X, Y, '\40');
				gotoxy(hout, X, Y);
			}
			else if (a == 81 || a == 113) {
				gotoxy(hout, 0, 22);
				printf("��Ϸ���������س������ز˵�.");
				while (1) {
					int a = _getch();
					if (a == 13) {
						back(hout, a);
						break;
					}
				}
				break;
			}
		}
	}
}

void move4(const HANDLE hout, int X, int Y) {
	while (1) {
		switch (_getch()) {
		case 224:
			int a = _getch();
			if (a == 77 || a == 108) {
				if (X < 69)
					X += 1;
				else
					X = 1;
				gotoxy(hout, X, Y);
			}
			else if (a == 75 || a == 106) {
				if (X > 1)
					X -= 1;
				else
					X = 69;
				gotoxy(hout, X, Y);
			}
			else if (a == 72 || a == 105) {
				if (Y > 0)
					Y -= 1;
				else
					Y = 17;
				gotoxy(hout, X, Y);
			}
			else if (a == 80 || a == 107) {
				if (Y < 17)
					Y += 1;
				else
					Y = 1;
				gotoxy(hout, X, Y);
			}
			else if (a == 32) {
				showch(hout, X, Y, '\40');
				gotoxy(hout, X, Y);
			}
			else if (a == 81 || a == 113) {
				gotoxy(hout, 0, 22);
				printf("��Ϸ���������س������ز˵�.");
				while (1) {
					int a = _getch();
					if (a == 13) {
						back(hout, a);
						break;
					}
				}
				break;
			}
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	menu();

	while (1) {
		int a = _getch();
		if (a == '1') {
			cls(hout);
			init_border(hout);

			int X = 35, Y = 9;
			gotoxy(hout, X, Y);

			move1(hout, X, Y);
		}
		else if (a == '2') {
			cls(hout);
			init_border(hout);

			int X = 35, Y = 9;
			gotoxy(hout, X, Y);

			move2(hout, X, Y);

		}
		else if (a == '3') {
			cls(hout);
			init_border(hout);

			int X = 35, Y = 9;
			gotoxy(hout, X, Y);

			move3(hout, X, Y);
		}
		else if (a == '4') {
			cls(hout);
			init_border(hout);

			int X = 35, Y = 9;
			gotoxy(hout, X, Y);

			move4(hout, X, Y);
		}
		else if (a == '0')
			break;
	}

	return 0;
}
/*���п����������20����ĸ����������ӵ�λ���ص�ʱ����������ĸ����20��*/