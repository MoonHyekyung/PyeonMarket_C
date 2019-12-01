#ifndef BREAD_H
#define BREAD_H
#include "intro.h"
#include "Category.h"


#include <string.h>

#include <stdio.h>

#include <mysql.h>



#pragma comment(lib, "libmysql.lib")

#pragma comment(lib, "ws2_32.lib")  



#define DB_HOST "10.96.122.63"//"호스트IP, 도메인또는localhost"

#define DB_USER "root"

#define DB_PASS "mirim2"

#define DB_NAME "PyeonMarket"



#define SQL_SELECT_RECORD "SELECT * FROM bread"

MYSQL *connection = NULL, conn;

MYSQL_RES *sql_result;

MYSQL_ROW sql_row;

int query_stat;

int i;
/*

class bread{
public:
	bread() {
		Rectangle(100, 100);
	}
	void Rectangle(int width, int height);
};


void Rectangle(int width, int height);
*/


#endif