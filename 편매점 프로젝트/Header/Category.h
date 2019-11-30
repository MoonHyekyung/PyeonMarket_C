#ifndef CATEGORY_H
#define CATEGORY_H
#include "Choose.h"

class Category {
public: 
	Category() {
		Rectangle(3, 4, 100, 5); // ★ Category ★가 있는 네모 칸
		Rectangle(104, 13); // 그림있는 카테고리
		Text(); // 글씨들

		SnackImage();
		DrinkImage();
		BreadImage();

		IcecreamImage();
		Etc();
	}
	void Rectangle(int x, int y);
	void Rectangle(int x, int y, int width, int height);

	void Text();
	void BreadImage();
	void SnackImage();
	void IcecreamImage();
	void DrinkImage();
	void Etc();
};

#endif
