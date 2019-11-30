#include <iostream>
#include "intro.h"
#define START 8
using namespace std;


void Rectangle(int width, int height) { // 상자 그리기
	unsigned char a = 0xa6, b[7];

	for (unsigned char i = 1; i < 7; i++) b[i] = 0xa0 + i;
	//b[1]:-, b[2]: l, b[3]:┌, b[4]:ㄱ, b[5]: ┙, b[6]:ㄴ

	cout << "     ";
	cout << a << b[3]; //┌
	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1]; //-
	cout << a << b[4] << endl; //ㄱ

	for (int i = 1; i <= height - 2; i++) {
		cout << "     ";
		cout << a << b[2]; //|
		for (int j = 1; j <= width - 2; j++)
			cout << " ";

		cout << a << b[2] << endl;
	}

	cout << "     ";
	cout << a << b[6]; //ㄴ

	for (int i = 1; i <= width - 2; i++)
		cout << a << b[1];
	cout << a << b[5] << endl; //┙
}

void textcolor(int color_num) { // 콘솔 글자 색깔 지정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}

void WayText() {
	gotoxy(START, 3);
	textcolor(13);
	cout << "                                          ★이용 방법★";
	gotoxy(START, 4);
	textcolor(15);
	cout << "-------------------------------------------------------------------------------------------------";

	
	gotoxy(START, 7);
	cout << "                                  편매점 이용 시작 버튼을 누른다.";

	gotoxy(START, 10);
	cout << "                                     ↙                     ↘";

	gotoxy(START, 12);
	cout << "                    ◎ 검색창에 상품을 검색한다.";
	cout << "    ◎ 카테고리를 선택한다.";

	gotoxy(START, 14);
	cout << "                                     ↘                     ↙";

	gotoxy(START, 16);
	cout << "                           원하는 상품을 눌러 상품의 상세정보를 확인한다.";

	textcolor(14);
	gotoxy(START, 21);
	cout << "                  < 상세 정보에는 이름, 가격, 열량, 수량 등이 기재되어있습니다! >";

	textcolor(15);
	gotoxy(START, 25);
}