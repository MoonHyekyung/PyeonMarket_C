#include "Choose.h"

void Choose::Rectangle(int width, int height) { // ���� �׸���: ����, ����
	unsigned char a = 0xa6, b[7];

	for (unsigned char i = 1; i < 7; i++) b[i] = 0xa0 + i;
	//b[1]:-, b[2]: l, b[3]:��, b[4]:��, b[5]: ��, b[6]:��

	cout << "   ";
	cout << a << b[3]; //��
	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1]; //-
	cout << a << b[4] << endl; //��

	for (int i = 1; i <= height - 2; i++) {
		cout << "   ";
		cout << a << b[2]; //|
		for (int j = 1; j <= width - 2; j++)
			cout << " ";

		cout << a << b[2] << endl;
	}
	cout << "   ";
	cout << a << b[6]; //��

	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1];
	cout << a << b[5] << endl; //��
}
void Choose::Rectangle(int x, int y, int width, int height) {
	unsigned char a = 0xa6, b[7];

	for (unsigned char i = 1; i < 7; i++) b[i] = 0xa0 + i;
	//b[1]:-, b[2]: l, b[3]:��, b[4]:��, b[5]: ��, b[6]:��

	gotoxy(x, y);
	cout << "   ";
	cout << a << b[3]; //��
	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1]; //-
	cout << a << b[4] << endl; //��

	for (int i = 1; i <= height - 2; i++) {
		gotoxy(x, y + i);
		cout << "   ";
		cout << a << b[2]; //|
		for (int j = 1; j <= width - 2; j++)
			cout << " ";

		cout << a << b[2] << endl;
	}
	gotoxy(x, y + height - 1);
	cout << "   ";
	cout << a << b[6]; //��

	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1];
	cout << a << b[5] << endl; //��
}
void Choose::PrintVertical() { //�ڽ� ��� ���� ����

	for (int i = 2; i < 25; i++) {
		gotoxy(58, i);
		if (i % 2 == 0) cout << "|\n";
		else cout << endl;
	}
}
void Choose::text() { //���� �ֱ�
	gotoxy(22, 21);
	cout << "ī�װ�(�޴���)";

	gotoxy(82, 21);
	cout << "�޴� �˻�";
}
void Choose::CategoryDraw() {
	Rectangle(7, 5, 41, 15);
	for (int i = 6; i < 20; i++) { // å ��� ������
		gotoxy(31, i);
		if (i % 2 == 0) cout << "|\n";
		else cout << endl;
	} // for
	for (int i = 8; i < 18; i += 2) { // å �� �۾� ǥ��
		gotoxy(13, i);
		cout << "~~~~~~~~~~~~~~~";
		gotoxy(33, i);
		cout << "~~~~~~~~~~~~~~~";
	} // for

}
void Choose::SearchDraw() {
	int i, j, y=0;
	Rectangle(68, 5, 20, 10);
	// ���� ������
	for (i = 2; i >= 1; i--)
	{
		gotoxy(90, 15+y);
		for (j = 1; j <= 2 - i; j++) {
			
			printf(" ");
		}
		for (j = 1; j <= 2; j++)
			printf("*");
		printf("\n");
		y++;
	}
	// ū������
	y = 0;
	for (i = 4; i >= 1; i--)
	{
		gotoxy(91, 17 + y);
		for (j = 1; j <= 4 - i; j++) {

			printf(" ");
		}
		for (j = 1; j <= 4; j++)
			printf("*");
		printf("\n");
		y++;
	}
	
}