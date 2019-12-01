#ifndef SNACK_H
#define SNACK_H
#include "Product.h"

class Snack :public Product {
public:
	Snack(int number, string name, int price, string manufacturer, string taste, int cal)
		:Product(number, name, price, manufacturer, taste, cal) { }
};

#endif
