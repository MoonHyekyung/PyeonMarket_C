#ifndef CATEGORY_H
#define CATEGORY_H
#include "Choose.h"

class Category {
public: 
	Category() {
		Rectangle(3, 4, 100, 5); // �� Category �ڰ� �ִ� �׸� ĭ
		Rectangle(104, 13); // �׸��ִ� ī�װ�
		Text(); // �۾���

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