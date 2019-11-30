#include "Category.h"

void Category::Rectangle(int x, int y, int width, int height) { // 상자 그리기: x좌표, y좌표, 가로, 세로
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
} // Rectangle 오버로딩 ( x좌표, y좌표 들어간)
void Category::Rectangle(int width, int height) { // 상자 그리기: 가로, 세로
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
void Triangle(int x, int y, int height) {
	int line, space, star, i = 1; // 라인, 공백, 별, i는 gotoxy에 다음 y줄 더하려고
	// 1 라인
	gotoxy(x, y);
	for (star = 1; star <= (2 * height - 1); star++)//별 = 2*n -1
		putchar('*');

	putchar('\n');//개행



	// 1, 마지막 빼고 가운데 라인
	for (line = (height - 2); line >= 1; line--)//line: 1~(n-2)
	{
		gotoxy(x, y + i++);
		for (space = 1; space <= (height - line - 1); space++) //공백 = n-line-1
			putchar(' ');

		cout << "*";//별1

		for (space = 1; space <= 2 * line - 1; space++) //공백 = 2*line-1
			putchar(' ');

		putchar('*');//별1

		putchar('\n');//개행=1

	}

	// 마지막 라인
	gotoxy(x, y + i);
	for (space = 1; space < height; space++)//공백 = n-line
		putchar(' ');

	putchar('*');//별1

	putchar('\n');//개행
}



void Category::Text() {
	
	gotoxy(43, 6);
	cout << "★      CATEGORY      ★" << endl;

	gotoxy(18, 20);
	cout << "빵";
	char cat[][11] = { "  ", "과자", "음료수", "아이스크림", "기타" };

	gotoxy(22, 20);
	for (int i = 0; i < sizeof(cat) / 11; i++) {
		cout << cat[i] << "           ";
	}
}

void Category::BreadImage() {

	int x = 8, y = 13, width = 15, height = 3;

	Rectangle(8, 13, 15, 4);
	unsigned char a = 0xa6, b[7];

	for (unsigned char i = 1; i < 7; i++) b[i] = 0xa0 + i;
	//b[1]:-, b[2]: l, b[3]:┌, b[4]:ㄱ, b[5]: ┙, b[6]:ㄴ

	gotoxy(x, y);
	cout << "   ";
	cout << a << b[3]; //┌
	for (int i = 1; i <= width - 6; i++) { // 첫 시작┌, 마지막 ㄱ 빼고
		if (i == 4 || i == 7) {
			cout << a << b[4];
			cout << a << b[3];
		}
		cout << a << b[1]; //-
	}
		
	cout << a << b[4] << endl; //ㄱ

	for (int i = 1; i <= height - 3; i++) {
		gotoxy(x, y + i);
		cout << "   ";
		cout << a << b[2]; //|
		for (int j = 1; j <= width - 2; j++)
			cout << " ";

		cout << a << b[2] << endl;
	}
}
void Category::SnackImage() {
	Rectangle(29, 12, 9, 5); // 과자봉지 네모

	// 과자봉지 세모
	gotoxy(33, 11);
	cout << "△ △ △";

	gotoxy(33, 17);
	cout << "▽ ▽ ▽";


	gotoxy(34, 14);
	printf("Snack");
}
void Category::IcecreamImage() {
	Triangle(68, 15, 4);
	Rectangle(64, 13, 8, 3);
	Rectangle(65, 11, 6, 3);
}
void Category::DrinkImage() {
	Rectangle(46, 13, 7, 5);
	gotoxy(52, 10);
	cout << "┌─" << endl;
	for (int i = 2; i < 4; i++) {
		gotoxy(52, 9+i);
		cout << "ㅣ" << endl;
	}
	gotoxy(50, 15);
	cout << "Drink";
}
void Category::Etc() {
	gotoxy(86, 15);
	cout << "● ● ●";
}
