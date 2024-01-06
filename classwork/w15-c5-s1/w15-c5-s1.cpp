/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3������������һ������������Ҫ����Ҫ��
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//ĳ�γ̵ĳɼ����ٷ��ƣ�
	float weight;	//ĳ�γ̵�ѧ�֣�Ȩ�أ�
	int   gpa;	//ĳ�γ̵ļ��㣨ͬ�ù���[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5��
};

struct student {
	int   no;               //ѧ�ţ���Ȼ��int���������˴������ǣ�
	char  name[9];          //���������4������
	struct course score[3]; //��������ſεĳɼ���δʹ�ú궨�壬����ʵ��ʱ��ֱ��д3���ɣ�
	float average;//��������������Ϊ��Ҫ���ӵĽṹ���Ա����һ��������Ҫ��ɾ������
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����˴�����������һ���������Һ������βΡ��Զ������ȶ������Ǽ򵥱�������������[]��ʽ��
***************************************************************************/
void total(struct student* stu, int num)
{
	struct student* ps;
	struct course* pc;
	float count = 0;
	ps = stu;
	for (pc = ps->score; (pc - ps->score) < 3; pc++) {
		ps->average += pc->gpa * pc->weight;
		count += pc->weight;
	}
	ps->average = ps->average / count;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�����10��ѧ������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* �����������ͱ����⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int k=0; )��ʽ���±�������ͬ����ֹ */
	int i , j;
	for (stu->average = 0, i = 0; i < num; stu++, i++) {
		cout << "�������" << setw(2) << i + 1 << "��ѧ������Ϣ : ";
		cin >> stu->no;
		cin >> stu->name;
		for (j = 0; j < 3; j++) {
			cin >> stu->score[j].value;
			cin >> stu->score[j].weight;
			if (stu->score[j].value >= 0 && stu->score[j].value < 60)
				stu->score[j].gpa = 0;
			else if (stu->score[j].value >= 60 && stu->score[j].value < 70)
				stu->score[j].gpa = 2;
			else if (stu->score[j].value >= 70 && stu->score[j].value < 80)
				stu->score[j].gpa = 3;
			else if (stu->score[j].value >= 80 && stu->score[j].value < 90)
				stu->score[j].gpa = 4;
			else if (stu->score[j].value >= 90 && stu->score[j].value <= 100)
				stu->score[j].gpa = 5;
		}
		total(stu, num);
		cin.ignore(65535, '\n');
	}
	cout << endl;
	/* ������ʵ�ֲ��� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* ��������ָ������⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	struct student* ps;
	struct course* pc;
	cout << num << "��ѧ���ĳɼ�" << endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
	cout << "==================================================================" << endl;
	for (ps = stu; ps - stu < num; ps++) {
		cout << setiosflags(ios::left) << setw(4) << ps - stu + 1 << " ";
		cout << setiosflags(ios::left) << setw(7) << ps->no << " ";
		cout << setiosflags(ios::left) << setw(8) << ps->name << " ";
		for (pc = ps->score; (pc - ps->score) < 3; pc++) {
			cout << setiosflags(ios::left) << setw(5) << pc->gpa << " ";
			cout << setiosflags(ios::left) << setw(5) << pc->weight << " ";
		}
		cout << setiosflags(ios::left) << setw(5) << setprecision(4) << ps->average << endl;
	}
	cout << endl;
	/* ������ʵ�ֲ��֣��������κ���ʽ��[]���� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������ߵ�ѧ���������в��У�
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* ��������������������͵ļ򵥱������������������� */
	struct student* ps;
	struct course* pc;
	int high = 0;
	for (ps = stu; ps - stu < num; ps++) {
		if ((ps->average) > (stu + high)->average)
			high = ps - stu;
	}
	ps = stu;
	cout << "������ߵ�ѧ��Ϊ" << endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
	cout << "==================================================================" << endl;
	cout << setiosflags(ios::left) << setw(4) << ps - stu + 1 << " ";
	cout << setiosflags(ios::left) << setw(7) << ps->no << " ";
	cout << setiosflags(ios::left) << setw(8) << ps->name << " ";
	for (pc = ps->score; (pc - ps->score) < 3; pc++) {
		cout << setiosflags(ios::left) << setw(5) << pc->gpa << " ";
		cout << setiosflags(ios::left) << setw(5) << pc->weight << " ";
	}
	cout << setiosflags(ios::left) << setw(5) << setprecision(4) << ps->average << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, N);		//����10��ѧ������Ϣ
	output_base(stu, N);	//���10��ѧ���Ļ�����Ϣ
	output_max(stu, N);	//�����ߣ������ж����

	return 0;
}

/*
�������ݣ����Ƶ�cmd���ɣ�����ʱ����������һ�飩

2153171 ������ 76.5 4 82 5 52 2
2154063 ����� 63 4 49 1 87 6
2151626 ������ 56 3 76 4 69 5
2153178 ϯ���� 44.5 2 83.5 4 87 6
2153482 ���� 91 4 43.5 1 66 3
2151931 ���� 79 6 85.5 3 62 2
2151282 ���� 86 3 63 3 77.5 4
2153047 �ż�ľ 49.5 3 86 6 93.5 3
2151405 ��ά�� 81.5 2 64.5 3 87 4
2152505 ��ѧ�� 73 3 62 2 85 5

*/