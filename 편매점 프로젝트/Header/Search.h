#include "intro.h"
class Search {
private:
	string SearchProduct;
public:
	Search() : SearchProduct(""){
		system(" mode  con lines=45   cols=80 ");
		Insert();
	}
	
	void Insert();
};