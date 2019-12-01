#ifndef ICECREAM_H
#define ICECREAM_H
#include "Product.h"

class IceCream :public Product {
public:
	IceCream(int number, string name, int price, string manufacturer, string taste, int cal)
		:Product(number, name, price, manufacturer, taste, cal) { }
};

#endif
