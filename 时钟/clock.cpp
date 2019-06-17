#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <time.h>

#define PI 3.1415926
static bu_dong=0;
/*������*/
void DralDial()
{
	int i;
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;										  //��������ϵ����
	char rome[][3] = {"12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"}; //��������

	//���ĸ�Բ
	circle(300, 300, 250);
	circle(300, 300, 30);
	circle(300, 300, 260);
	circle(300, 300, 270);

	for (i = 0; i < 59; i++)
	{

		// ��60������
		x1 = (int)(300 + (sin(i * PI / 30) * 250));
		y1 = (int)(300 - (cos(i * PI / 30) * 250));
		x2 = (int)(300 + (sin(i * PI / 30) * 260));
		y2 = (int)(300 - (cos(i * PI / 30) * 260));
		//	setbkcolor(RGB(245, 247, 222));
		line(x1, y1, x2, y2);

		//��12��������
		setfillstyle(BLACK);
		if (i % 5 == 0)
		{
			x3 = (int)(x1 + sin((i + 5) * PI / 30) * 12);
			y3 = (int)(y1 - cos((i + 5) * PI / 30) * 12);
			x4 = (int)(x1 + sin((i - 5) * PI / 30) * 12);
			y4 = (int)(y1 - cos((i - 5) * PI / 30) * 12);
			x5 = (int)(290 + (sin((i - 0.2) * PI / 30) * 220));
			y5 = (int)(290 - (cos((i - 0.2) * PI / 30) * 220));
			int triangle[6] = {x1, y1, x3, y3, x4, y4};
			//	setcolor(BLACK);
			fillpoly(3, triangle);

			//д��������
			//	setbkcolor(RGB(245, 247, 222));
			setfont(24, 0, "����");
			outtextxy(x5, y5, rome[i / 5]);
		}
	}
}

//��ָ��
void DrawHand(int hour, int minute, int second)
{

	int xhour, yhour, xminute, yminute, xsecond, ysecond; //��������ϵָ������

	xhour = (int)(130 * sin(hour * PI / 6 + minute * PI / 360 + second * PI / 1800));
	yhour = (int)(130 * cos(hour * PI / 6 + minute * PI / 360 + second * PI / 1800));
	xminute = (int)(145 * sin(minute * PI / 30 + second * PI / 1800));
	yminute = (int)(145 * cos(minute * PI / 30 + second * PI / 1800));
	xsecond = (int)(200 * sin(second * PI / 30));
	ysecond = (int)(200 * cos(second * PI / 30));

	//��ʱ��
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	//	setcolor(LIGHTGRAY);
	line(300 + xhour, 300 - yhour, 300 - xhour / 6, 300 + yhour / 6);

	//������
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	//	setcolor(RGB(222, 158, 107));
	line(300 + xminute, 300 - yminute, 300 - xminute / 4, 300 + yminute / 4);

	//������
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	//	setcolor(RED);
	line(300 + xsecond, 300 - ysecond, 300 - xsecond / 3, 300 + ysecond / 3);
}

int x1[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // �����ÿ������
int x2[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // ƽ���ÿ������

char *Week[] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������"}; // ��������
char num[3];																		   // ���� num �ַ���
char xy[30];																		   // ���� xy �ַ���,

struct Time // ������һ���ṹ��
{
	int year, month, day;			  // ����
	int yearFlag, monthFlag, dayFlag; // ������������Ƿ�ı�
};

// ��ʼ��
void Init()
{
	// ��ʼ����ͼ����
	initgraph(1400, 650);

	cleardevice();
}

// ��������
void DrawWeek()
{
	char str[7];
	int x1 = 0;

	settextstyle(18, 0, "����");
	for (int i = 0; i < 7; i++)
	{
		sprintf(str, "%s", Week[i]);
		outtextxy(720 + x1, 100, str);
		x1 += 60;
	}
}

// ��������2
void DrawWeek2()
{
	char str[7];
	int x1 = 0;

	settextstyle(18, 0, "����");
	for (int i = 0; i < 7; i++)
	{
		sprintf(str, "%s", Week[i]);
		outtextxy(120 + x1, 100, str);
		x1 += 60;
	}
}

// �������ڵ�����
void CalDate(Time &tm, char x)
{
	switch (x)
	{
	case 'q':
		tm.year++;
		break;
	case 'w':
		tm.year += 10;
		break;
	case 'e':
		tm.year += 100;
		break;
	case 'r':
		tm.year += 1000;
		break;
	case 't':
		if (tm.month < 12)
			tm.month++;
		break;
	case 'a':
		if (tm.year > 0)
			tm.year--;
		break;
	case 's':
		if (tm.year >= 10)
			tm.year -= 10;
		break;
	case 'd':
		if (tm.year >= 100)
			tm.year -= 100;
		break;
	case 'f':
		if (tm.year >= 1000)
			tm.year -= 1000;
		break;
	case 'g':
		if (tm.month > 1)
			tm.month--;
		break;
	}
}

// �ж���ݺ��·��Ƿ����
bool DateFlag(int y1, int y2, int m1, int m2)
{
	return (y1 != y2 || m1 != m2);
}

// �ж������껹��ƽ��
bool CalYear(int year)
{
	return ((year % 4 == 0 && year % 10 != 0) || year % 400 == 0);
}

// ���Ƶ�������
void DrawDate(Time &tm)
{
	int y = 0, z = 0;
	int s;

	sprintf(xy, "��ǰΪ��Ԫ %d �� %d �µ�����", tm.year, tm.month);
	settextstyle(18, 0, "����");
	outtextxy(720, 50, xy);

	s = (5 + (tm.year + 1) + (tm.year - 1) / 4 - (tm.year - 1) / 100 + (tm.year - 1) / 400) % 7;

	if (CalYear(tm.year)) // �����ǰ���������
	{
		for (int i = 1; i < tm.month; i++)
		{
			s = (x1[i] + s) % 7;
		}

		if (s / 6 != 1)
		{
			y = (s + 1) * 60;
		}

		settextstyle(36, 0, "Arial");
		for (i = 1; i <= x1[tm.month]; i++)
		{
			sprintf(num, " %d ", i);
			outtextxy(730 + y, 150 + z, num);
			y += 60;
			if ((i + s) % 7 == 6 && (i + s) >= 6)
			{
				z += 85;
				y = 0;
			}
		}
	}
	else // �����ǰ��ݲ�������
	{
		for (int i = 1; i < tm.month; i++)
		{
			s = (x2[i] + s) % 7;
		}

		if (s / 6 != 1)
		{
			y = (s + 1) * 60;
		}

		settextstyle(36, 0, "Arial");
		for (i = 1; i <= x2[tm.month]; i++)
		{
			sprintf(num, "%2d", i);
			outtextxy(730 + y, 150 + z, num);
			y += 60;
			if ((i + s) % 7 == 6)
			{
				z += 85;
				y = 0;
			}
		}
	}
}

// ���Ƶ�������2
void DrawDate2(Time &tm)
{
	int y = 0, z = 0;
	int s;

	sprintf(xy, "��ǰΪ��Ԫ %d �� %d �µ�����", tm.year, tm.month);
	settextstyle(18, 0, "����");
	outtextxy(120, 50, xy);

	s = (5 + (tm.year + 1) + (tm.year - 1) / 4 - (tm.year - 1) / 100 + (tm.year - 1) / 400) % 7;

	if (CalYear(tm.year)) // �����ǰ���������
	{
		for (int i = 1; i < tm.month; i++)
		{
			s = (x1[i] + s) % 7;
		}

		if (s / 6 != 1)
		{
			y = (s + 1) * 60;
		}

		settextstyle(36, 0, "Arial");
		for (i = 1; i <= x1[tm.month]; i++)
		{
			sprintf(num, " %d ", i);
			outtextxy(130 + y, 150 + z, num);
			y += 60;
			if ((i + s) % 7 == 6 && (i + s) >= 6)
			{
				z += 85;
				y = 0;
			}
		}
	}
	else // �����ǰ��ݲ�������
	{
		for (int i = 1; i < tm.month; i++)
		{
			s = (x2[i] + s) % 7;
		}

		if (s / 6 != 1)
		{
			y = (s + 1) * 60;
		}

		settextstyle(36, 0, "Arial");
		for (i = 1; i <= x2[tm.month]; i++)
		{
			sprintf(num, "%2d", i);
			outtextxy(130 + y, 150 + z, num);
			y += 60;
			if ((i + s) % 7 == 6)
			{
				z += 85;
				y = 0;
			}
		}
	}
}

// ������
int main()
{
	printf("�������ܣ�\nq��+1 ��/�Σ�a��-1 ��/�Σ�\nw��+10��/�Σ�s��-10��/�Σ�\nt��+1 ��/�Σ�g��-1 ��/��\n");
	printf("��ǰʱ��Ϊϵͳ��׼ʱ�䣻\n�޸�������1��\n��ѯ��������2��\n�������������ַ���س�\n");
	int y;
	scanf("%d", &y);
	if (y == 1)
	{
		int hour1;
		int Second1;
		int min1;
		printf("��������Ҫ�޸ĵ�Сʱ����ʽΪ0-23\n");
		scanf("%d", &hour1);
		printf("��������Ҫ�޸ĵķ��ӣ���ʽΪ0-59\n");
		scanf("%d", &min1);
		printf("��������Ҫ�޸ĵ��룬��ʽΪ0-59\n");
		scanf("%d", &Second1);
		SYSTEMTIME t0; //��ȡ��ǰʱ��
		GetLocalTime(&t0);
		int a = 0, b = 0, c = 0;
		a = 23 - hour1 + t0.wHour; //�߼�˼�룺��ȡ�޸�ʱ����24��֮���׼ʱ��+��Ϊ�߼�24ʱ����day+1��
		b = 59 - min1 + t0.wMinute;
		c = 59 - Second1 + t0.wSecond;

		void DralDial();
		void DrawDecoration();
		void DrawHand(int hour, int minute, int second);

		initgraph(1400, 650); //��ʼ��600��600�Ļ�ͼ����

		//	cleardevice();	//�����Ļ

		char add;
		tm *t1;		  // �� time.h ���ж���Ϊһ���ṹ�壬�÷��� MSDN
		time_t Clock; // �� time.h ���ж���Ϊһ���ṹ�壬�÷��� MSDN
		Time tm;	  // �ṹ�� tm

		// ��ʼ��
		Init();

		// ��ȡ�ṹ�� Clock �Ĳ���
		time(&Clock);

		// ��ȡʱ��
		t1 = localtime(&Clock);
		//	printf(t1);

		tm.year = t1->tm_year + 1900; // ��ǰϵͳʱ���������, ����Ϊʲô�� 1900, �� MSDN
		tm.month = t1->tm_mon + 1;	// ��ȡϵͳʱ�������·�, ����Ϊʲô�� 1, �� MSDN
		tm.day = t1->tm_mday;
		tm.yearFlag = tm.year;   // ��ǵ�ǰ��ݷ�
		tm.monthFlag = tm.month; // ��ǵ�ǰ�·�
		tm.dayFlag = tm.day;

		// ��������
		DrawWeek();
		outtextxy(1150, 30, "��������:");
		outtextxy(1150, 50, "q��+1 ��/�Σ�a��-1 ��/��");
		outtextxy(1150, 80, "w��+10��/�Σ�s��-10��/��");
		outtextxy(1150, 110, "t��+1 ��/�Σ�g��-1 ��/��");

		// ���Ƶ��µ�����
		DrawDate(tm);

		//������
		//	setcolor(RED);
		setfont(32, 0, "������κ");
		outtextxy(260, 130, "TIME");

		setwritemode(R2_XORPEN); //��������ͼ��ʽ
		SYSTEMTIME t;			 //����������浱ǰʱ��
		GetLocalTime(&t);		 //��ȡ��ǰʱ��
		sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d �� ", t.wYear, t.wMonth, t.wDay);
		settextstyle(25, 0, "����");
		outtextxy(0, 5, xy);
		//����������þ�����ʾ��ǰ����

		int day1 = 0;
		DralDial();  //������
		int y, m, d; //����ȫ�ֱ���������
		while (!kbhit())
		{
			Second1++;
			if (Second1 == 60)
			{
				Second1 = 0;
				min1++;
			}
			DrawHand(hour1, min1, Second1); //������
			Sleep(1000);
			DrawHand(hour1, min1, Second1); //������

			SYSTEMTIME t;
			GetLocalTime(&t); //��ȡ��ǰʱ��
			if (a == t.wHour && b == t.wMinute && c == t.wSecond)
			{
				t.wDay++;
				if (t.wDay == 32)
				{
					t.wMonth++;
					t.wDay = 1;
				}
				if (t.wMonth == 12)
				{
					t.wYear++;
					t.wMonth = 1;
				}
				y = t.wYear;
				m = t.wMonth;
				d = t.wDay;
				sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d ��", t.wYear, t.wMonth, t.wDay);
				settextstyle(25, 0, "����");
				outtextxy(0, 5, xy);
			}
			y = y;
			m = m;
			d = d;
		}

		/*		while(1){
		if (hour1==23 && min1== 59 && Second1 == 59 ) {			//�ж�ʱ��ʱ�䣬��������day+1
		
/*		SYSTEMTIME t;
		GetLocalTime(&t);
		t.wDay++;
		sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d ��", t.wYear, t.wMonth, t.wDay);
	    settextstyle(25, 0, "����");
		outtextxy(0, 5, xy);

/*
		SYSTEMTIME t3;
		GetLocalTime(&t3);

		sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d ��", t.wYear, t.wMonth, t.wDay+1);
	    settextstyle(25, 0, "����");
		outtextxy(0, 5, xy);
		if(a==t3.wHour){
        sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d ��", t.wYear, t.wMonth, t.wDay+1);
	    settextstyle(25, 0, "����");
		outtextxy(0, 5, xy);

		}	
	}
*/
		// ��ѭ��
		while (1)
		{
			// �Ӽ��̻�ȡ����
			add = getch();

			// �������ڵ�����
			CalDate(tm, add);

			// �ж������Ƿ����, ������� if ���
			if (DateFlag(tm.year, tm.yearFlag, tm.month, tm.monthFlag))
			{
				// �����Ļ
				//	cleardevice();
				initgraph(850, 650);
				// ���»�������
				DrawWeek2();
				outtextxy(600, 30, "��������:");
				outtextxy(600, 50, "q��+1 ��/�Σ�a��-1 ��/��");
				outtextxy(600, 80, "w��+10��/�Σ�s��-10��/��");
				outtextxy(600, 110, "t��+1 ��/�Σ�g��-1 ��/��");
				// ���»��Ƶ�������
				DrawDate2(tm);

				tm.yearFlag = tm.year;   // �����±�����
				tm.monthFlag = tm.month; // �����±���·�
			}
		}

		// ����
		return 0;
	}

	else if (y == 2)
	{
		int year1, month1;
		printf("��������Ҫ��ѯ����ݣ���ʽΪ2019\n");
		scanf("%d", &year1);
		printf("��������Ҫ��ѯ���·ݣ���ʽΪ  05\n");
		scanf("%d", &month1);
		void DralDial();
		void DrawDecoration();
		void DrawHand(int hour, int minute, int second);
		initgraph(1400, 650); //��ʼ��600��600�Ļ�ͼ����
		//	cleardevice();	//�����Ļ
		char add;
		Time tm; // �ṹ�� tm

		tm.year = year1;		 // ��ǰ�޸�ʱ���������, ����Ϊʲô�� 1900, �� MSDN
		tm.month = month1;		 // ��ȡ�޸�ʱ�������·�, ����Ϊʲô�� 1, �� MSDN
		tm.yearFlag = tm.year;   // ��ǵ�ǰ���
		tm.monthFlag = tm.month; // ��ǵ�ǰ�·�

		DrawWeek(); // ��������
		outtextxy(1150, 30, "��������:");
		outtextxy(1150, 50, "q��+1 ��/�Σ�a��-1 ��/��");
		outtextxy(1150, 80, "w��+10��/�Σ�s��-10��/��");
		outtextxy(1150, 110, "t��+1 ��/�Σ�g��-1 ��/��");
		DrawDate(tm); // ���Ƶ��µ�����
		//	DrawDecoration();		//��װ��
		DralDial(); //������
		//������
		//	setcolor(RED);
		setfont(32, 0, "������κ");
		outtextxy(260, 130, "TIME");
		setwritemode(R2_XORPEN); //��������ͼ��ʽ
		SYSTEMTIME t;			 //����������浱ǰʱ��
		while (!kbhit())
		{
			GetLocalTime(&t); //��ȡ��ǰʱ��
			sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d �� %d:%d:%d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
			settextstyle(25, 0, "����");
			outtextxy(0, 5, xy);
			DrawHand(t.wHour, t.wMinute, t.wSecond); //������
			Sleep(1000);
			DrawHand(t.wHour, t.wMinute, t.wSecond); //������
		}

		// ��ѭ��
		while (1)
		{
			add = getch();	// �Ӽ��̻�ȡ����
			CalDate(tm, add); // �������ڵ�����
			// �ж������Ƿ����, ������� if ���
			if (DateFlag(tm.year, tm.yearFlag, tm.month, tm.monthFlag))
			{

				cleardevice(); // �����Ļ
				DralDial();	//������
				DrawWeek();	// ���»�������
				outtextxy(1150, 30, "��������:");
				outtextxy(1150, 50, "q��+1 ��/�Σ�a��-1 ��/��");
				outtextxy(1150, 80, "w��+10��/�Σ�s��-10��/��");
				outtextxy(1150, 110, "t��+1 ��/�Σ�g��-1 ��/��");
				DrawDate(tm);			 // ���»��Ƶ�������
				tm.yearFlag = tm.year;   // �����±�����
				tm.monthFlag = tm.month; // �����±���·�
				setfont(32, 0, "������κ");
				outtextxy(260, 130, "TIME");
				setwritemode(R2_XORPEN); //��������ͼ��ʽ
				while (!kbhit())
				{
					SYSTEMTIME t;	 //����������浱ǰʱ��
					GetLocalTime(&t); //��ȡ��ǰʱ��
					sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d �� %d:%d:%d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
					settextstyle(25, 0, "����");
					outtextxy(0, 5, xy);
					DrawHand(t.wHour, t.wMinute, t.wSecond); //������
					Sleep(1000);
					DrawHand(t.wHour, t.wMinute, t.wSecond); //������
				}
			}
		}

		// ����
		return 0;
	}


	else
	{
		initgraph(1400, 650); //��ʼ��600��600�Ļ�ͼ����

		//	cleardevice();	//�����Ļ

		char add;
		tm *t1;		  // �� time.h ���ж���Ϊһ���ṹ�壬�÷��� MSDN
		time_t Clock; // �� time.h ���ж���Ϊһ���ṹ�壬�÷��� MSDN
		Time tm;	  // �ṹ�� tm

		// ��ʼ��
		Init();

		// ��ȡ�ṹ�� Clock �Ĳ���
		time(&Clock);

		// ��ȡʱ��
		t1 = localtime(&Clock);
		//	printf(t1);

		tm.year = t1->tm_year + 1900; // ��ǰϵͳʱ���������, ����Ϊʲô�� 1900, �� MSDN
		tm.month = t1->tm_mon + 1;	// ��ȡϵͳʱ�������·�, ����Ϊʲô�� 1, �� MSDN
		tm.day = t1->tm_mday;
		tm.yearFlag = tm.year;   // ��ǵ�ǰ��ݷ�
		tm.monthFlag = tm.month; // ��ǵ�ǰ�·�
		tm.dayFlag = tm.day;

		// ��������
		DrawWeek();
				outtextxy(1150, 30, "��������:");
		outtextxy(1150, 50, "q��+1 ��/�Σ�a��-1 ��/��");
		outtextxy(1150, 80, "w��+10��/�Σ�s��-10��/��");
		outtextxy(1150, 110, "t��+1 ��/�Σ�g��-1 ��/��");

		// ���Ƶ��µ�����
		DrawDate(tm);
		//	DrawDecoration();		//��װ��
		DralDial(); //������

		//������
		//	setcolor(RED);
		setfont(32, 0, "������κ");
		outtextxy(260, 130, "TIME");

		setwritemode(R2_XORPEN); //��������ͼ��ʽ
		SYSTEMTIME t;			 //����������浱ǰʱ��

		while (!kbhit())
		{
			GetLocalTime(&t); //��ȡ��ǰʱ��
			sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d �� %d:%d:%d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
			settextstyle(25, 0, "����");

			outtextxy(0, 5, xy);

			DrawHand(t.wHour, t.wMinute, t.wSecond); //������
			Sleep(1000);
			DrawHand(t.wHour, t.wMinute, t.wSecond); //������
		}

		// ��ѭ��
		while (1)
		{
			// �Ӽ��̻�ȡ����
			add = getch();

			// �������ڵ�����
			CalDate(tm, add);

			// �ж������Ƿ����, ������� if ���
			if (DateFlag(tm.year, tm.yearFlag, tm.month, tm.monthFlag))
			{
				// �����Ļ
				cleardevice();

				DralDial(); //������

				// ���»�������
				DrawWeek();
				outtextxy(1150, 30, "��������:");
				outtextxy(1150, 50, "q��+1 ��/�Σ�a��-1 ��/��");
				outtextxy(1150, 80, "w��+10��/�Σ�s��-10��/��");
				outtextxy(1150, 110, "t��+1 ��/�Σ�g��-1 ��/��");
				// ���»��Ƶ�������
				DrawDate(tm);

				tm.yearFlag = tm.year;   // �����±�����
				tm.monthFlag = tm.month; // �����±���·�

				setfont(32, 0, "������κ");
				outtextxy(260, 130, "TIME");

				while (!kbhit())
				{
					SYSTEMTIME t;	 //����������浱ǰʱ��
					GetLocalTime(&t); //��ȡ��ǰʱ��
					sprintf(xy, "�����ǹ�Ԫ %d �� %d �� %d �� %d:%d:%d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
					settextstyle(25, 0, "����");
					outtextxy(0, 5, xy);

					DrawHand(t.wHour, t.wMinute, t.wSecond); //������
					Sleep(1000);
					DrawHand(t.wHour, t.wMinute, t.wSecond); //������
				}
			}
		}

		// ����
		return 0;
	}
}