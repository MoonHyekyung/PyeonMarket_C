#include <iostream>
#include "intro.h"
#define START 8
using namespace std;


void Rectangle(int width, int height) { // ���� �׸���
	unsigned char a = 0xa6, b[7];

	for (unsigned char i = 1; i < 7; i++) b[i] = 0xa0 + i;
	//b[1]:-, b[2]: l, b[3]:��, b[4]:��, b[5]: ��, b[6]:��

	cout << "     ";
	cout << a << b[3]; //��
	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1]; //-
	cout << a << b[4] << endl; //��

	for (int i = 1; i <= height - 2; i++) {
		cout << "     ";
		cout << a << b[2]; //|
		for (int j = 1; j <= width - 2; j++)
			cout << " ";

		cout << a << b[2] << endl;
	}

	cout << "     ";
	cout << a << b[6]; //��

	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1];
	cout << a << b[5] << endl; //��
}

void textcolor(int color_num) { // �ܼ� ���� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}

void WayText() {
	gotoxy(START, 3);
	textcolor(13);
	cout << "                                          ���̿� �����";
	gotoxy(START, 4);
	textcolor(15);
	cout << "-------------------------------------------------------------------------------------------------";

	
	gotoxy(START, 7);
	cout << "                                  ����� �̿� ���� ��ư�� ������.";

	gotoxy(START, 10);
	cout << "                                     ��                     ��";

	gotoxy(START, 12);
	cout << "                    �� �˻�â�� ��ǰ�� �˻��Ѵ�.";
	cout << "    �� ī�װ��� �����Ѵ�.";

	gotoxy(START, 14);
	cout << "                                     ��                     ��";

	gotoxy(START, 16);
	cout << "                           ���ϴ� ��ǰ�� ���� ��ǰ�� �������� Ȯ���Ѵ�.";

	textcolor(14);
	gotoxy(START, 21);
	cout << "                  < �� �������� �̸�, ����, ����, ���� ���� ����Ǿ��ֽ��ϴ�! >";

	textcolor(15);
	gotoxy(START, 25);
}