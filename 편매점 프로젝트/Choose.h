#ifndef CHOOSE_H
#define CHOOSE_H
#include "intro.h"

class Choose {
public:
	Choose() {
		Rectangle(110, 25);
		PrintVertical();
		text();
	}

	void Rectangle(int width, int height);
	void PrintVertical();
	void text();

};
#endif
