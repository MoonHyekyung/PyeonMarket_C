#ifndef DRINK_H
#define DRINK_H
#include "Product.h"

class Drink :public Product {
public:
	Drink(int number, string name, int price, string manufacturer, string taste, int cal)
		:Product(number, name, price, manufacturer, taste, cal) { }
};

#endif
