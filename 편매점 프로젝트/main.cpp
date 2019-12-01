#include "HowToUse.h"
#include "Choose.h"
#include "Category.h"
#include "Search.h"
#include "Bread.h"
#include "Drink.h"
#include "IceCream"


using namespace std;

int x, y; // 현재 좌표 위치

// →:77   ←:75     ↑:72    ↓:80
void gotoxy(int a, int b) {
	COORD Pos = { (short)(a - 1),(short)(b - 1) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void box2() { //상자 그리기 (편매점 로고 그릴때 사용)
	char start = 0;
	unsigned char a = 0xa6, b[7], i;


	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	gotoxy(6, 5);

	printf("%c%c", a, b[3]); //┌
	for (int i = 1; i <= 100; i++) printf("%c%c", a, b[1]); //-
	printf("%c%c", a, b[4]); //ㄱ

	printf("\n");

	for (int i = 1; i <= 14; i++) {
		printf("     ");
		printf("%c%c", a, b[2]);
		for (int j = 1; j <= 100; j++) printf(" ");

		printf("%c%c\n", a, b[2]);
	}

	printf("\n");
	gotoxy(6, 20);
	printf("%c%c", a, b[6]); //ㄴ

	for (int i = 1; i <= 100; i++) printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]); //┘
	printf("\n\n");

}

void display() { // 편매점 로고
	//box2();
	box2();
	gotoxy(14, 6);
	printf("                    ■                       ■      ■");
	gotoxy(14, 7);
	printf("                    ■                       ■      ■       ■■■■■■■■      ■");
	gotoxy(14, 8);
	printf("■■■■■■        ■          ■■■■■   ■      ■              ■■           ■");
	gotoxy(14, 9);
	printf("   ■  ■	     ■■■          ■      ■   ■      ■             ■  ■          ■");
	gotoxy(14, 10);
	printf("   ■  ■	         ■          ■      ■   ■■■■■            ■    ■     ■■■");
	gotoxy(14, 11);
	printf("   ■  ■       ■■■          ■      ■   ■      ■           ■      ■        ■");
	gotoxy(14, 12);
	printf("■■■■■■        ■          ■■■■■   ■      ■          ■        ■       ■");
	gotoxy(14, 13);
	printf("                    ■                       ■      ■                             ■");
	gotoxy(14, 15);
	printf("      ■                                                         ■■■■■■■■■■■ ");
	gotoxy(14, 16);
	printf("      ■                                                         ■                  ■");
	gotoxy(14, 17);
	printf("      ■                                                         ■                  ■");
	gotoxy(14, 18);
	printf("      ■■■■■■■                                             ■■■■■■■■■■■");



	gotoxy(50, 27);




}

int keyControl() {
	char temp = _getch();

	switch (temp) {
	case 72: return UP; break;
	case 75: return LEFT; break;
	case 77:  return RIGHT; break;
	case 80: return DOWN; break;
	case ' ': case 13: return SUBMIT; break;
	}
}

int menudrow() {

	x = 50;
	y = 23;
	gotoxy(x + 1, y);
	cout << "편매점 이용"; // y==23
	gotoxy(x + 1, y + 2); //y ==25
	cout << "이용 방법";
	gotoxy(x + 1, y + 4); // y==27
	cout << "종 료";

	gotoxy(x - 2, y); // 처음에 선택 키 보이게 하기 위해서 
	cout << "▶"; // 미리 하나 찍어놓음

	while (1) {//무한반복
		int n = keyControl(); // 입력 받은 키
		switch (n) {
		case UP: {
			if (y > 24) {
				gotoxy(x - 2, y);
				cout << " ";
				y -= 2;
				gotoxy(x - 2, y);
				cout << "▶";
			}
			break;
		}

		case DOWN: {
			if (y < 26) {
				gotoxy(x - 2, y);
				cout << " ";
				y += 2;
				gotoxy(x - 2, y);
				cout << "▶";
			}
			break;
		}
		case SUBMIT: {
			system("cls");
			return y - 24;
		}
		}

	}

}

int ChooseLocation() {
	while (true) {
		int x = 26;
		int y = 23;
		gotoxy(28, 23);// 처음에 선택 키 보이게 하기 위해서 
		cout << "▲"; // 미리하나 찍어놓음

		while (1) {//무한반복
			int n = keyControl(); // 입력 받은 키
			switch (n) {
			case LEFT: {
				if (x > 26) {
					gotoxy(x, y);
					cout << "    ";
					x = x - 60;
					gotoxy(x, y);
					cout << "▲";
				} // if
				break;
			} // case LEFT

			case RIGHT: {
				if (x < 86) {
					gotoxy(x, y);
					cout << "    ";
					x += 60;
					gotoxy(x, y);
					cout << "▲";
				} // if
				break;
			} // case RIGHT
			case SUBMIT: {
				system("cls");
				return x;
				break;
			}// case SUBMIT

			} // 방향 키 switch
		} // 안쪽 while
		break;
	} // 바깥 쪽 while
}

int bread() {
	mysql_init(&conn);
	// DB 연결

	connection = mysql_real_connect(&conn, "localhost",

		"root", "mirim2", "PyeonMarket", 3306, (char *)NULL, 0);
	if (connection == NULL)

	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;

	}
	//한글사용을위해추가.

	mysql_query(connection, "set session character_set_connection=euckr;");

	mysql_query(connection, "set session character_set_results=euckr;");

	mysql_query(connection, "set session character_set_client=euckr;");


	// 셀렉트

	query_stat = mysql_query(connection, SQL_SELECT_RECORD);

	if (query_stat != 0)

	{

		fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));

		return 1;

	}

	// 결과출력

	sql_result = mysql_store_result(connection);

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)

	{
		printf("\n\n");
		printf("%2s %2s %2s %2s %2s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3], sql_row[4], sql_row[5]);  //품번,이름,가격,제조,맛,칼

	}

	mysql_free_result(sql_result);
	// DB 연결닫기

	mysql_close(connection);

	return 0;

}
int drink() {
	mysql_init(&conn2);
	// DB 연결

	connection2 = mysql_real_connect(&conn2, "localhost",

		"root", "mirim2", "PyeonMarket", 3306, (char *)NULL, 0);
	if (connection2 == NULL)

	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn2));
		return 1;

	}
	//한글사용을위해추가.

	mysql_query(connection2, "set session character_set_connection=euckr;");

	mysql_query(connection2, "set session character_set_results=euckr;");

	mysql_query(connection2, "set session character_set_client=euckr;");


	// 셀렉트

	query_stat2 = mysql_query(connection2, SQL_SELECT_RECORD2);

	if (query_stat2 != 0)

	{

		fprintf(stderr, "Mysql query error : %s", mysql_error(&conn2));

		return 1;

	}

	// 결과출력
	sql_result2 = mysql_store_result(connection2);

	while ((sql_row2 = mysql_fetch_row(sql_result2)) != NULL)

	{

		printf("\n");
		printf("%2s %2s %2s %2s %2s %s\n", sql_row2[0], sql_row2[1], sql_row2[2], sql_row2[3], sql_row2[4], sql_row2[5]);  //품번,이름,가격,제조,맛,칼

	}

	mysql_free_result(sql_result2);
	// DB 연결닫기

	mysql_close(connection2);

	return 0;


}
int icecream() {
	mysql_init(&conn3);
	// DB 연결

	connection3 = mysql_real_connect(&conn3, "localhost",

		"root", "mirim2", "PyeonMarket", 3306, (char *)NULL, 0);
	if (connection3 == NULL)

	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;

	}
	//한글사용을위해추가.

	mysql_query(connection3, "set session character_set_connection=euckr;");

	mysql_query(connection3, "set session character_set_results=euckr;");

	mysql_query(connection3, "set session character_set_client=euckr;");


	// 셀렉트

	query_stat3 = mysql_query(connection3, SQL_SELECT_RECORD3);

	if (query_stat3 != 0)

	{

		fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));

		return 1;

	}

	// 결과출력

	sql_result3 = mysql_store_result(connection3);

	while ((sql_row3 = mysql_fetch_row(sql_result3)) != NULL)

	{


		printf("%2s %2s %2s %2s %2s %s\n", sql_row3[0], sql_row3[1], sql_row3[2], sql_row3[3], sql_row3[4], sql_row3[5]);  //품번,이름,가격,제조,맛,칼

	}

	mysql_free_result(sql_result3);
	// DB 연결닫기

	mysql_close(connection3);

	return 0;

}

int CategoryLocation() {
	///////////////////////////////////// 카테고리 선택 ////////////////////////////////////////////////
	int x = 18;
	int y = 23;
	gotoxy(18, 23);// 처음에 선택 키 보이게 하기 위해서 
	cout << "▲"; // 미리하나 찍어놓음

	while (1) {//무한반복
		int n = keyControl(); // 입력 받은 키
		switch (n) {
		case LEFT: {
			if (x > 18) {
				gotoxy(x, y);
				cout << "   ";
				x -= 18;
				gotoxy(x, y);
				cout << "▲";
			} //if
			break;
		} // case LEFT

		case RIGHT: {
			if (x < 88) {
				gotoxy(x, y);
				cout << "   ";
				x += 18;
				gotoxy(x, y);
				cout << "▲";
			} // if
			break;
		} // case RIGHT
		case SUBMIT: {
			system("cls");
			return x;
		} // case SUBMIT
		} // switch
	} // while
}

int main() {
	system(" mode  con lines=30   cols=120 "); // 높이 30, 너비 120 콘솔 설정
	display(); //편매점 로고 출력
	gotoxy(50, 25); // Enter키를 누르시오. 위치 지정
	cout << "Enter키를 누르시오." << endl;

	while (1) {
		if (_getch() == 13) { // Enter키가 눌리면 화면 변경
			system("cls"); //편매점 로고와 Enter키를 누르시오. 삭제
			system(" mode  con lines=30   cols=120 "); // 높이 30, 너비 120 콘솔 설정
			display(); //로고 다시 출력
			menudrow(); // 메뉴 선택


			switch (y) {
			case 23: { // 입력받은 y 위치가 23 일시 Choose 클래스(사용 시작) 으로 넘어감
				{Choose c = Choose(); } // Choose 객체 생성 (Choose화면 출력)
				int Choose_XLocation = ChooseLocation(); // ▲움직이기, ▲키가 멈춘 위치 받기(Choose)
				if (Choose_XLocation == 26) { // 카테고리 위치에서 엔터가 되었을 시 true
					system("cls"); // 화면지우기
					Category cate = Category(); // Category 객체 생성 (Category 화면 출력) 
					int Category_XLocation = CategoryLocation(); // ▲움직이기, ▲키가 멈춘 위치 받기(Category)
					if (Category_XLocation == 18) {
						bread();
					}
					else if (Category_XLocation == 54) {
						drink();
					}

					else if (Category_XLocation == 72) {
						icecream();
					}

				}
				else if (Choose_XLocation == 86) { // 검색 위치에서 엔터가 되었을 시 true
					system("cls"); // 화면 지우기
					Search search = Search();

				}
				break;
			}// case 23

			case 25: {// y위치가 25일 시 이용방법(WayText)함수 호출
				Rectangle(100, 23); // 사각형 틀 출력
				WayText(); // 이용방법 출력
				break;
			} // case 25
			} // switch (y)
			if (y == 27) break;

		}
	}
	return 0;
}