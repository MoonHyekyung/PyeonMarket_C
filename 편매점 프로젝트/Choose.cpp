#include "Choose.h"
#include "intro.h"

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