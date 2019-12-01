#ifndef ICECREAM_H
#define ICECREAM_H
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





#define SQL_SELECT_RECORD3 "SELECT * FROM icecream"
MYSQL *connection3 = NULL, conn3;

MYSQL_RES *sql_result3;

MYSQL_ROW sql_row3;

int query_stat3;






#endif