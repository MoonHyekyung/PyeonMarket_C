#ifndef BREAD_H
#define BREAD_H
#include "Product.h"

class Bread :public Product {
public:
	Bread(int number, string name, int price, string manufacturer, string taste, int cal)
		:Product(number, name, price, manufacturer, taste, cal){ }
};

#endif
