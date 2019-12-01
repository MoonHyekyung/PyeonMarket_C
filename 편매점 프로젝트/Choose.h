#ifndef CHOOSE_H
#define CHOOSE_H
#include "intro.h"

class Choose {
public:
	Choose() {}
	Choose(int i) {
		Rectangle(110, 25);
		PrintVertical();
		text();
		CategoryDraw();
		SearchDraw();
	}

	void Rectangle(int width, int height);
	void Rectangle(int width, int height, int x, int y);
	void PrintVertical();

	void text();
	void CategoryDraw();
	void SearchDraw();

};
#endif
