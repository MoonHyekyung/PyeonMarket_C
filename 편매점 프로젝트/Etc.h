#ifndef ETC_H
#define ETC_H
#include "Product.h"

class Etc :public Product {
public:
	Etc(int number, string name, int price, string manufacturer, string taste, int cal)
		:Product(number, name, price, manufacturer, taste, cal) { }
};

#endif