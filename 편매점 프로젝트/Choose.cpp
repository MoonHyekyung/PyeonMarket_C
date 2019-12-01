#include "Choose.h"

void Choose::Rectangle(int width, int height) { // 상자 그리기: 가로, 세로
	unsigned char a = 0xa6, b[7];

	for (unsigned char i = 1; i < 7; i++) b[i] = 0xa0 + i;
	//b[1]:-, b[2]: l, b[3]:┌, b[4]:ㄱ, b[5]: ┙, b[6]:ㄴ

	cout << "   ";
	cout << a << b[3]; //┌
	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1]; //-
	cout << a << b[4] << endl; //ㄱ

	for (int i = 1; i <= height - 2; i++) {
		cout << "   ";
		cout << a << b[2]; //|
		for (int j = 1; j <= width - 2; j++)
			cout << " ";

		cout << a << b[2] << endl;
	}
	cout << "   ";
	cout << a << b[6]; //ㄴ

	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1];
	cout << a << b[5] << endl; //┙
}
void Choose::Rectangle(int x, int y, int width, int height) {
	unsigned char a = 0xa6, b[7];

	for (unsigned char i = 1; i < 7; i++) b[i] = 0xa0 + i;
	//b[1]:-, b[2]: l, b[3]:┌, b[4]:ㄱ, b[5]: ┙, b[6]:ㄴ

	gotoxy(x, y);
	cout << "   ";
	cout << a << b[3]; //┌
	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1]; //-
	cout << a << b[4] << endl; //ㄱ

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
	cout << a << b[6]; //ㄴ

	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1];
	cout << a << b[5] << endl; //┙
}
void Choose::PrintVertical() { //박스 가운데 세로 라인

	for (int i = 2; i < 25; i++) {
		gotoxy(58, i);
		if (i % 2 == 0) cout << "|\n";
		else cout << endl;
	}
}
void Choose::text() { //글자 넣기
	gotoxy(22, 21);
	cout << "카테고리(메뉴판)";

	gotoxy(82, 21);
	cout << "메뉴 검색";
}
void Choose::CategoryDraw() {
	Rectangle(7, 5, 41, 15);
	for (int i = 6; i < 20; i++) { // 책 가운데 선라인
		gotoxy(31, i);
		if (i % 2 == 0) cout << "|\n";
		else cout << endl;
	} // for
	for (int i = 8; i < 18; i += 2) { // 책 속 글씨 표현
		gotoxy(13, i);
		cout << "~~~~~~~~~~~~~~~";
		gotoxy(33, i);
		cout << "~~~~~~~~~~~~~~~";
	} // for

}
void Choose::SearchDraw() {
	int i, j, y=0;
	Rectangle(68, 5, 20, 10);
	// 작은 손잡이
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
	// 큰손잡이
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